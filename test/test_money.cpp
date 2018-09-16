#include "money.h"
#include "catch.hpp"

using namespace moneycpp;

TEST_CASE("Make money", "[money]")
{
   auto m1 = make_money(20, currency::USD);
   REQUIRE(m1.amount == 20);
   REQUIRE(m1.currency == currency::USD);
}

TEST_CASE("Equality money", "[money]")
{
   auto m1 = make_money(20, currency::USD);
   auto m2 = make_money(20, currency::USD);
   auto m3 = make_money(30, currency::USD);
   auto m4 = make_money(20, currency::EUR);

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
   auto m1 = make_money(20, currency::USD);
   auto m2 = make_money(20, currency::USD);
   auto m3 = make_money(12.50, currency::USD);
   auto m4 = make_money(10, currency::EUR);

   REQUIRE((m1 + m2).amount == 40);
   REQUIRE((m1 + m3).amount == 32.50);
   REQUIRE_THROWS_AS(m1 + m4, currency_mismatch_error);
}

TEST_CASE("Subtract money", "[money]")
{
   auto m1 = make_money(20, currency::USD);
   auto m2 = make_money(20, currency::USD);
   auto m3 = make_money(12.50, currency::USD);
   auto m4 = make_money(10, currency::EUR);

   REQUIRE((m1 - m2).amount == 0);
   REQUIRE((m1 - m3).amount == 7.50);
   REQUIRE_THROWS_AS(m1 - m4, currency_mismatch_error);
}

TEST_CASE("Multiply money", "[money]")
{
   auto m1 = make_money(20, currency::USD);

   auto m2 = m1 * 2;
   auto m3 = m1 * 1.5;

   REQUIRE(m2.amount == 40);
   REQUIRE(m2.currency == currency::USD);

   REQUIRE(m3.amount == 30.0);
}

TEST_CASE("Divide money", "[money]")
{
   auto m1 = make_money(20, currency::USD);

   auto m2 = m1 / 2;
   auto m3 = m1 / 2.5;   

   REQUIRE(m2.amount == 10);
   REQUIRE(m2.currency == currency::USD);

   REQUIRE(m3.amount == 8.0);
   REQUIRE_THROWS_AS(m1 / 0, std::runtime_error);
}

TEST_CASE("Test invalid exchange", "[exchange]")
{
   auto m = make_money(20, currency::USD);
   
   REQUIRE_THROWS_AS(convert_money(m, currency::EUR, 0), std::runtime_error);
   REQUIRE_THROWS_AS(convert_money(m, currency::EUR, -1), std::runtime_error);
}

TEST_CASE("Test exchange same currency", "[exchange]")
{
   auto m1 = make_money(20, currency::USD);
   auto m2 = convert_money(m1, currency::USD, 2);
   
   REQUIRE(m1 == m2);
}

TEST_CASE("Test round ceil", "[rounding]")
{
   std::vector<double> inputs {5.5, 2.5, 1.6, 1.1, 1.0, -1.0, -1.1, -1.6, -2.5, -5.5};
   std::vector<double> expected {6, 3, 2, 2, 1, -1, -1, -1, -2, -5};
   
   for(size_t i = 0; i < inputs.size(); ++i)
   {
      auto r = round_ceiling(inputs[i]);
      REQUIRE(r == expected[i]);
   }
}

TEST_CASE("Test round floor", "[rounding]")
{
   std::vector<double> inputs {5.5, 2.5, 1.6, 1.1, 1.0, -1.0, -1.1, -1.6, -2.5, -5.5};
   std::vector<double> expected {5, 2, 1, 1, 1, -1, -2, -2, -3, -6};
   
   for(size_t i = 0; i < inputs.size(); ++i)
   {
      auto r = round_floor(inputs[i]);
      REQUIRE(r == expected[i]);
   }
}
