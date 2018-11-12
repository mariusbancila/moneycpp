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

   {
      country_currency_map mymap{ country::currencies };

      country_unit vc{ 1, "VX", "VAX", "Virtual Country", true };
      currency_unit cu1{ "VIR", 1001, 2, "Virtual Currency 1" };
      currency_unit cu2{ "VIX", 1002, 2, "Virtual Currency 2" };

      mymap.insert({ vc, cu1 });
      mymap.insert({ vc, cu2 });

      auto s = country::find_country_currencies(mymap, vc);
      REQUIRE(s.size() == 2);
      REQUIRE(*s.begin() == cu1);
      REQUIRE(*std::next(s.begin()) == cu2);
   }
} 

TEST_CASE("Find country currency equal range test", "[country][currency]")
{
   {
      auto r = country::country_currency_equal_range(
         country::currencies,
         country::AF);

      REQUIRE(r.first != std::end(country::currencies));
      REQUIRE(r.second != std::end(country::currencies));
      REQUIRE(std::distance(r.first, r.second) == 1);
      REQUIRE(r.first->second == currency::AFN);
   }

   {
      auto r = country::country_currency_equal_range(
         country::currencies,
         country::BO);

      REQUIRE(r.first != std::end(country::currencies));
      REQUIRE(r.second != std::end(country::currencies));
      REQUIRE(std::distance(r.first, r.second) == 2);
      REQUIRE(r.first->second == currency::BOB);
      REQUIRE(std::next(r.first)->second == currency::BOV);
   }

   {
      country_currency_map mymap{ country::currencies };

      country_unit vc{ 1, "VX", "VAX", "Virtual Country", true };
      currency_unit cu1{ "VIR", 1001, 2, "Virtual Currency 1" };
      currency_unit cu2{ "VIX", 1002, 2, "Virtual Currency 2" };

      mymap.insert({ vc, cu1 });
      mymap.insert({ vc, cu2 });

      auto r = country::country_currency_equal_range(mymap, vc);

      REQUIRE(r.first != std::end(mymap));
      REQUIRE(r.second != std::end(mymap));
      REQUIRE(std::distance(r.first, r.second) == 2);
      REQUIRE(r.first->second == cu1);
      REQUIRE(std::next(r.first)->second == cu2);
   }
}

TEST_CASE("Find main country currency test", "[country][currency]")
{
   REQUIRE(country::find_country_currency(country::AF) == currency::AFN);
   REQUIRE(country::find_country_currency(country::BO) == currency::BOB);
   REQUIRE_THROWS_AS(country::find_country_currency(country::AQ), currency_not_found);
}
