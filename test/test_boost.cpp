#include "money.h"
#include "catch.hpp"

#ifdef USE_BOOST_MULTIPRECISION
#include "boost\multiprecision\cpp_dec_float.hpp"
using decimal = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<50>>;

namespace
{
   inline decimal operator""_dec(char const * str, std::size_t)
   {
      return decimal(str);
   }
}

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

#endif