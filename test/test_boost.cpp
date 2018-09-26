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

TEST_CASE("Boost decimal rounding policy none test", "[policy][boost]")
{
   std::vector<std::pair<decimal, decimal>> values
   {
      { "0.0"_dec, "0.0"_dec },
      { "1.5"_dec, "1.5"_dec },
      { "1.1"_dec, "1.1"_dec },
      { "-1.12345"_dec, "-1.12345"_dec }
   };

   for (auto const p : values)
   {
      auto m = make_money(p.first, currency::USD);
      auto r = rounding_policy_none()(m);

      REQUIRE(p.second == r.amount);
   }
}

TEST_CASE("Boost decimal rounding policy standard test", "[policy][boost]")
{
   std::vector<std::pair<decimal, decimal>> values
   {
      { "0.0"_dec, "0.0"_dec },
      { "1.5"_dec, "1.5"_dec },
      { "1.1"_dec, "1.1"_dec },
      { "-1.12345"_dec, "-1.1234"_dec },
      { "-2.234567"_dec, "-2.2345"_dec },
      { "4.88999"_dec, "4.8900"_dec }
   };

   for (auto const p : values)
   {
      auto m = make_money(p.first, currency::USD);
      auto r = rounding_policy_standard(round_ceiling())(m);

      REQUIRE(p.second == r.amount);
   }
}

TEST_CASE("Boost decimal rounding policy to currency digits test", "[policy][boost]")
{
   std::vector<std::pair<decimal, decimal>> values
   {
      { "0.00"_dec, "0.00"_dec },
      { "1.50"_dec, "1.50"_dec },
      { "1.10"_dec, "1.10"_dec },
      { "-1.12345"_dec, "-1.12"_dec },
      { "-2.234567"_dec, "-2.23"_dec },
      { "4.88999"_dec, "4.89"_dec },
      { "3.12001"_dec, "3.13"_dec },
   };

   for (auto const p : values)
   {
      auto m = make_money(p.first, currency::USD);
      auto r = rounding_policy_to_currency_digits(round_ceiling())(m);

      REQUIRE(p.second == r.amount);
   }
}

TEST_CASE("Boost decimal rounding policy to currency with multi digits test", "[policy][boost]")
{
   std::vector<std::pair<decimal, decimal>> values
   {
      {  "12.123456789012345678901"_dec,  "12.123456789012345678"_dec },
      { "-12.123456789012345678901"_dec, "-12.123456789012345679"_dec },
   };

   for (auto const p : values)
   {
      auto m = make_money(p.first, currency::ETH);
      auto r = rounding_policy_to_currency_digits(round_floor())(m);

      REQUIRE(p.second == r.amount);
   }
}

#endif