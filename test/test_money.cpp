#include "money.h"
#include "catch.hpp"
#include <vector>

using namespace moneycpp;

template <typename T>
inline void REQUIRE_EQ(T const v1, T const v2, T const epsilon = 0.00001)
{
   REQUIRE(std::fabs(v1 - v2) <= epsilon);
}

TEST_CASE("Make money", "[money]")
{
   auto m1 = make_money(20.0, currency::USD);
   REQUIRE(m1.amount == 20.0);
   REQUIRE(m1.currency == currency::USD);
}

TEST_CASE("Equality money", "[money]")
{
   auto m1 = make_money(20.0, currency::USD);
   auto m2 = make_money(20.0, currency::USD);
   auto m3 = make_money(30.0, currency::USD);
   auto m4 = make_money(20.0, currency::EUR);

   REQUIRE(m1 == m2);
   REQUIRE(m1 != m3);
   REQUIRE_THROWS_AS(m1 == m4, currency_mismatch_error);

   REQUIRE(m1 <= m2);
   REQUIRE(m1 < m3);
   REQUIRE(m3 > m2);
   REQUIRE(m3 >= m3);
   REQUIRE_THROWS_AS(m1 < m4, currency_mismatch_error);
}

TEST_CASE("Add money", "[money]")
{
   auto m1 = make_money(20.0, currency::USD);
   auto m2 = make_money(20.0, currency::USD);
   auto m3 = make_money(12.50, currency::USD);
   auto m4 = make_money(10.0, currency::EUR);

   REQUIRE((m1 + m2).amount == 40.0);
   REQUIRE((m1 + m3).amount == 32.50);
   REQUIRE_THROWS_AS(m1 + m4, currency_mismatch_error);
}

TEST_CASE("Subtract money", "[money]")
{
   auto m1 = make_money(20.0, currency::USD);
   auto m2 = make_money(20.0, currency::USD);
   auto m3 = make_money(12.50, currency::USD);
   auto m4 = make_money(10.0, currency::EUR);

   REQUIRE((m1 - m2).amount == 0.0);
   REQUIRE((m1 - m3).amount == 7.50);
   REQUIRE_THROWS_AS(m1 - m4, currency_mismatch_error);
}

TEST_CASE("Multiply money", "[money]")
{
   auto m1 = make_money(20.0, currency::USD);

   auto m2 = m1 * 2;
   auto m3 = m1 * 1.5;

   REQUIRE(m2.amount == 40.0);
   REQUIRE(m2.currency == currency::USD);

   REQUIRE(m3.amount == 30.0);
}

TEST_CASE("Divide money", "[money]")
{
   auto m1 = make_money(20.0, currency::USD);

   auto m2 = m1 / 2;
   auto m3 = m1 / 2.5;   

   REQUIRE(m2.amount == 10.0);
   REQUIRE(m2.currency == currency::USD);

   REQUIRE(m3.amount == 8.0);
   REQUIRE_THROWS_AS(m1 / 0, std::runtime_error);
}

TEST_CASE("Test invalid exchange", "[exchange]")
{
   auto m = make_money(20.0, currency::USD);
   REQUIRE_THROWS_AS(
      exchange_money(m, currency::EUR, 0.0, rounding_policy_standard(round_ceiling())),
      std::runtime_error);
   REQUIRE_THROWS_AS(
      exchange_money(m, currency::EUR, -1.0, rounding_policy_standard(round_ceiling())),
      std::runtime_error);
}

TEST_CASE("Test exchange same currency", "[exchange]")
{
   auto m1 = make_money(20.0, currency::USD);
   auto m2 = exchange_money(m1, currency::USD, 2.0, rounding_policy_none(round_ceiling()));
   auto m3 = exchange_money(m1, currency::USD, 2.0, rounding_policy_standard(round_ceiling()));
   auto m4 = exchange_money(m1, currency::USD, 2.0, rounding_policy_to_currency_digits(round_ceiling()));

   REQUIRE(m1 == m2);
   REQUIRE(m1 == m3);
   REQUIRE(m1 == m4);
}

TEST_CASE("Test conversion", "[exchange]")
{
   std::vector<std::tuple<double, double, double>> values
   {
      { 0.0,     1.0,    0.00 },

      { 20.0,    1.0,    20.0 },
      { 20.12,   1.0,    20.12 },
      { 20.0,    1.1,    22.0 },
      { 22.55,   1.2345, 27.84 },
      { 101.95,  1.1149, 113.67 },

      { -20.0,   1.0,    -20.0 },
      { -20.12,  1.0,    -20.12 },
      { -20.0,   1.1,    -22.0 },
      { -22.55,  1.2345, -27.83 },
      { -101.95, 1.1149, -113.66 },

   };

   for (auto const & t : values)
   {
      auto[amount, rate, result] = t;

      auto m1 = make_money(amount, currency::USD);
      auto m2 = exchange_money(m1, currency::EUR, rate, rounding_policy_to_currency_digits(round_ceiling()));

      REQUIRE_EQ(m2.amount, result);
   }   
}

TEST_CASE("Test conversion extra decimals", "[exchange]")
{
   std::vector<std::tuple<double, double, double>> values
   {
      { 0.0,     1.0,    0.0 },
      
      { 20.0,    1.0,    20.0000 },
      { 20.12,   1.0,    20.1200 },
      { 20.0,    1.1,    22.0000 },
      { 22.55,   1.2345, 27.8380 },
      { 101.95,  1.1149, 113.6641 },
      
      { -20.0,   1.0,    -20.0000 },
      { -20.12,  1.0,    -20.1200 },
      { -20.0,   1.1,    -22.0000 },
      { -22.55,  1.2345, -27.8379 },
      { -101.95, 1.1149, -113.6640 },
   };
   
   for (auto const & t : values)
   {
      auto[amount, rate, result] = t;
      
      auto m1 = make_money(amount, currency::USD);
      auto m2 = exchange_money(m1, currency::CLF, rate, rounding_policy_standard(round_ceiling()));
      
      REQUIRE_EQ(m2.amount, result);
   }
}
