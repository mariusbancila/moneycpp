#include "country.h"
#include "catch.hpp"

#include <vector>
#include <set>

using namespace moneycpp;

TEST_CASE("Equality country", "[country]")
{
   REQUIRE(country::AU == country::AU);
   REQUIRE(country::AU != country::AR);

   country_unit cu1 { 1, "VA", "VAX", "Virtual 1", true };
   country_unit cu2 { 2, "VA", "VAX", "Virtual 2", true };
   country_unit cu3 { 1, "VB", "VAX", "Virtual 1", true };
   country_unit cu4 { 1, "VA", "VBX", "Virtual 1", true };

   REQUIRE(cu1 != cu2);
   REQUIRE(cu1 != cu3);
   REQUIRE(cu1 != cu4);
}

TEST_CASE("Unique countries", "[country]")
{
   auto db = std::vector<country_unit>{ country::countries };

   std::set<int> codes;
   std::set<std::string_view> alpha2s;
   std::set<std::string_view> alpha3s;

   for (auto const & cu : db)
   {
      if (cu.code > 0)
      {
         codes.insert(cu.code);
         alpha2s.insert(cu.alpha2);
         alpha3s.insert(cu.alpha3);
      }
   }

   auto count = std::count_if(
      std::begin(db), std::end(db),
      [](country_unit const & cu) {return cu.code > 0; });

   REQUIRE(codes.size() == count);
   REQUIRE(alpha2s.size() == count);
   REQUIRE(alpha3s.size() == count);
}
