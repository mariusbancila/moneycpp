#include "country_currency.h"
#include "catch.hpp"

using namespace moneycpp;

TEST_CASE("Find all country currencies test", "[country][currency]")
{
   {
      auto s = country::find_country_currencies(country::AF);
      REQUIRE(s.size() == 1);
      REQUIRE(*s.begin() == currency::AFN);
   }

   {
      auto s = country::find_country_currencies(country::BO);
      REQUIRE(s.size() == 2);
      REQUIRE(*s.begin() == currency::BOB);
      REQUIRE(*std::next(s.begin()) == currency::BOV);
   }
   /*
   auto r = country::find_country_currency(
      country::currencies,
      country::AF);

   REQUIRE(r.first != std::end(country::currencies));
   REQUIRE(r.second != std::end(country::currencies));
   REQUIRE(std::distance(r.first, r.second) == 1);
   REQUIRE(r.first->second == currency::AFN);
   */
} 

TEST_CASE("Find main country currency test", "[country][currency]")
{
   REQUIRE(country::find_country_currency(country::AF) == currency::AFN);
   REQUIRE(country::find_country_currency(country::BO) == currency::BOB);
   REQUIRE_THROWS_AS(country::find_country_currency(country::AQ), currency_not_found);
}
