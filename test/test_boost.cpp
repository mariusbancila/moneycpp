#include "money.h"
#include "catch.hpp"

#ifdef USE_BOOST_MULTIPRECISION
#include "ext\boost.h"
#include <vector>

using namespace moneycpp;

TEST_CASE("Simple boost multiprecision test", "[boost]")
{
   auto m1 = make_money("20.45"_dec, currency::USD);

   REQUIRE(m1.amount == "20.45"_dec);
   REQUIRE(m1.currency == currency::USD);
}

TEST_CASE("Boost decimal add money", "[boost][money]")
{
   auto m1 = make_money("20.45"_dec, currency::USD);
   auto m2 = make_money("20.54"_dec, currency::USD);
   auto m3 = make_money("12.50"_dec, currency::USD);
   auto m4 = make_money("10.0"_dec, currency::EUR);

   REQUIRE((m1 + m2).amount == "40.99"_dec);
   REQUIRE((m1 + m3).amount == "32.95"_dec);
   REQUIRE_THROWS_AS(m1 + m4, currency_mismatch_error);
}

TEST_CASE("Boost decimal subtract money", "[boost][money]")
{
   auto m1 = make_money("20.55"_dec, currency::USD);
   auto m2 = make_money("10.54"_dec, currency::USD);
   auto m3 = make_money("12.50"_dec, currency::USD);
   auto m4 = make_money("10.0"_dec, currency::EUR);

   REQUIRE((m1 - m2).amount == "10.01"_dec);
   REQUIRE((m1 - m3).amount == "8.05"_dec);
   REQUIRE_THROWS_AS(m1 - m4, currency_mismatch_error);
}

TEST_CASE("Boost decimal multiply money", "[boost][money]")
{
   auto m1 = make_money("20.02"_dec, currency::USD);

   auto m2 = m1 * 2;
   auto m3 = m1 * 1.5;

   REQUIRE(m2.amount == "40.04"_dec);
   REQUIRE(m2.currency == currency::USD);

   REQUIRE(m3.amount == "30.03"_dec);
}

TEST_CASE("Boost decimal divide money", "[boost][money]")
{
   auto m1 = make_money("20.10"_dec, currency::USD);

   auto m2 = m1 / 2;
   auto m3 = m1 / 2.5;

   REQUIRE(m2.amount == "10.05"_dec);
   REQUIRE(m2.currency == currency::USD);

   REQUIRE(m3.amount == "8.04"_dec);
   REQUIRE_THROWS_AS(m1 / "0"_dec, std::runtime_error);
}

template <typename T>
static std::vector<T> inputs
{ T("5.5"), T("2.5"), T("1.6"), T("1.1"), T("1.0"), T("-1.0"), T("-1.1"), T("-1.6"), T("-2.5"), T("-5.5") };

template <typename T>
static std::vector<T> exp_round_up
{ T("6.0"), T("3.0"), T("2.0"), T("2.0"), T("1.0"), T("-1.0"), T("-2.0"), T("-2.0"), T("-3.0"), T("-6.0") };

template <typename T>
static std::vector<T> exp_round_down
{ T("5.0"), T("2.0"), T("1.0"), T("1.0"), T("1.0"), T("-1.0"), T("-1.0"), T("-1.0"), T("-2.0"), T("-5.0") };

template <typename T>
static std::vector<T> exp_round_ceil
{ T("6.0"), T("3.0"), T("2.0"), T("2.0"), T("1.0"), T("-1.0"), T("-1.0"), T("-1.0"), T("-2.0"), T("-5.0") };

template <typename T>
static std::vector<T> exp_round_floor
{ T("5.0"), T("2.0"), T("1.0"), T("1.0"), T("1.0"), T("-1.0"), T("-2.0"), T("-2.0"), T("-3.0"), T("-6.0") };

template <typename T>
static std::vector<T> exp_round_half_up
{ T("6.0"), T("3.0"), T("2.0"), T("1.0"), T("1.0"), T("-1.0"), T("-1.0"), T("-2.0"), T("-3.0"), T("-6.0") };

template <typename T>
static std::vector<T> exp_round_half_down
{ T("5.0"), T("2.0"), T("2.0"), T("1.0"), T("1.0"), T("-1.0"), T("-1.0"), T("-2.0"), T("-2.0"), T("-5.0") };

template <typename T>
static std::vector<T> exp_round_half_even
{ T("6.0"), T("2.0"), T("2.0"), T("1.0"), T("1.0"), T("-1.0"), T("-1.0"), T("-2.0"), T("-2.0"), T("-6.0") };

template <typename T>
static std::vector<T> exp_round_half_odd
{ T("5.0"), T("3.0"), T("2.0"), T("1.0"), T("1.0"), T("-1.0"), T("-1.0"), T("-2.0"), T("-3.0"), T("-5.0") };

TEST_CASE("Boost decimal round up test", "[rounding][boost]")
{
   for (size_t i = 0; i < inputs<decimal>.size(); ++i)
   {
      auto r = round_up()(inputs<decimal>[i]);
      REQUIRE(r == exp_round_up<decimal>[i]);
   }
}

TEST_CASE("Boost decimal round down test", "[rounding][boost]")
{
   for (size_t i = 0; i < inputs<decimal>.size(); ++i)
   {
      auto r = round_down()(inputs<decimal>[i]);
      REQUIRE(r == exp_round_down<decimal>[i]);
   }
}

TEST_CASE("Boost decimal round ceil test", "[rounding][boost]")
{
   for (size_t i = 0; i < inputs<decimal>.size(); ++i)
   {
      auto r = round_ceiling()(inputs<decimal>[i]);
      REQUIRE(r == exp_round_ceil<decimal>[i]);
   }
}

TEST_CASE("Boost decimal round floor test", "[rounding][boost]")
{
   for (size_t i = 0; i < inputs<decimal>.size(); ++i)
   {
      auto r = round_floor()(inputs<decimal>[i]);
      REQUIRE(r == exp_round_floor<decimal>[i]);
   }
}

TEST_CASE("Boost decimal round half up test", "[rounding][boost]")
{
   for (size_t i = 0; i < inputs<decimal>.size(); ++i)
   {
      auto r = round_half_up()(inputs<decimal>[i]);
      REQUIRE(r == exp_round_half_up<decimal>[i]);
   }
}

TEST_CASE("Boost decimal round half down test", "[rounding][boost]")
{
   for (size_t i = 0; i < inputs<decimal>.size(); ++i)
   {
      auto r = round_half_down()(inputs<decimal>[i]);
      REQUIRE(r == exp_round_half_down<decimal>[i]);
   }
}

TEST_CASE("Boost decimal round half even test", "[rounding][boost]")
{
   for (size_t i = 0; i < inputs<decimal>.size(); ++i)
   {
      auto r = round_half_even()(inputs<decimal>[i]);
      REQUIRE(r == exp_round_half_even<decimal>[i]);
   }
}

TEST_CASE("Boost decimal round half odd test", "[rounding][boost]")
{
   for (size_t i = 0; i < inputs<decimal>.size(); ++i)
   {
      auto r = round_half_odd()(inputs<decimal>[i]);
      REQUIRE(r == exp_round_half_odd<decimal>[i]);
   }
}

TEST_CASE("Boost decimal invalid exchange test", "[exchange][boost]")
{
   auto m = make_money(decimal(20U), currency::USD);
   REQUIRE_THROWS_AS(
      exchange_money(m, currency::EUR, decimal(0U), rounding_policy_standard(round_ceiling())),
      std::runtime_error);
   REQUIRE_THROWS_AS(
      exchange_money(m, currency::EUR, decimal(-1), rounding_policy_standard(round_ceiling())),
      std::runtime_error);
}

TEST_CASE("Boost decimal exchange same currency test", "[exchange][boost]")
{
   auto m1 = make_money(decimal(20U), currency::USD);
   auto m2 = exchange_money(m1, currency::USD, decimal(2U), rounding_policy_none(round_ceiling()));
   auto m3 = exchange_money(m1, currency::USD, decimal(2U), rounding_policy_standard(round_ceiling()));
   auto m4 = exchange_money(m1, currency::USD, decimal(2U), rounding_policy_to_currency_digits(round_ceiling()));

   REQUIRE(m1 == m2);
   REQUIRE(m1 == m3);
   REQUIRE(m1 == m4);
}

TEST_CASE("Boost decimal  exchange test", "[exchange][boost]")
{
   std::vector<std::tuple<decimal, decimal, decimal>> values
   {
      { "0.0"_dec,     "1.0"_dec,    "0.00"_dec },

      { "20.0"_dec,    "1.0"_dec,    "20.0"_dec },
      { "20.12"_dec,   "1.0"_dec,    "20.12"_dec },
      { "20.0"_dec,    "1.1"_dec,    "22.0"_dec },
      { "22.55"_dec,   "1.2345"_dec, "27.84"_dec },
      { "101.95"_dec,  "1.1149"_dec, "113.67"_dec },

      { "-20.0"_dec,   "1.0"_dec,    "-20.0"_dec },
      { "-20.12"_dec,  "1.0"_dec,    "-20.12"_dec },
      { "-20.0"_dec,   "1.1"_dec,    "-22.0"_dec },
      { "-22.55"_dec,  "1.2345"_dec, "-27.83"_dec },
      { "-101.95"_dec, "1.1149"_dec, "-113.66"_dec },

   };

   for (auto const & t : values)
   {
      auto[amount, rate, result] = t;

      auto m1 = make_money(amount, currency::USD);
      auto m2 = exchange_money(m1, currency::EUR, rate, rounding_policy_to_currency_digits(round_ceiling()));

      REQUIRE(m2.amount == result);
   }
}

TEST_CASE("Boost decimal exchange extra decimals test", "[exchange][boost]")
{
   std::vector<std::tuple<decimal, decimal, decimal>> values
   {
      { "0.0"_dec,     "1.0"_dec,    "0.0"_dec },

      { "20.0"_dec,    "1.0"_dec,    "20.0000"_dec },
      { "20.12"_dec,   "1.0"_dec,    "20.1200"_dec },
      { "20.0"_dec,    "1.1"_dec,    "22.0000"_dec },
      { "22.55"_dec,   "1.2345"_dec, "27.8380"_dec },
      { "101.95"_dec,  "1.1149"_dec, "113.6641"_dec },

      { "-20.0"_dec,   "1.0"_dec,    "-20.0000"_dec },
      { "-20.12"_dec,  "1.0"_dec,    "-20.1200"_dec },
      { "-20.0"_dec,   "1.1"_dec,    "-22.0000"_dec },
      { "-22.55"_dec,  "1.2345"_dec, "-27.8379"_dec },
      { "-101.95"_dec, "1.1149"_dec, "-113.6640"_dec },
   };

   for (auto const & t : values)
   {
      auto[amount, rate, result] = t;

      auto m1 = make_money(amount, currency::USD);
      auto m2 = exchange_money(m1, currency::CLF, rate, rounding_policy_standard(round_ceiling()));

      REQUIRE(m2.amount == result);
   }
}

#endif