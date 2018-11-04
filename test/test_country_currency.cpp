#include "country_currency.h"
#include "catch.hpp"

using namespace moneycpp;

TEST_CASE("Basic country currency test", "[country][currency]")
{
   auto s = country::find_country_currency(country::AF);
   REQUIRE(s.size() == 1);
   REQUIRE(*s.begin() == currency::AFN);

   //auto r = country::find_country_currency(
   //   std::begin(country::currencies),
   //   std::end(country::currencies), 
   //   country::AF);

   //REQUIRE(r.first != std::end(country::currencies));
   //REQUIRE(r.second != std::end(country::currencies));
   //REQUIRE(std::distance(r.first, r.second) == 1);
   //REQUIRE(r.first->second == currency::AFN);
} 