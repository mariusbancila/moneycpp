#include "currency.h"
#include "catch.hpp"

#include <vector>
#include <set>

using namespace moneycpp;

TEST_CASE("Equality currency", "[currency]")
{
   REQUIRE(currency::USD == currency::USD);
   REQUIRE(currency::USD != currency::EUR);

   currency_unit cu1{ "VIR", 1001, 2, "Virtual 1" };
   currency_unit cu2{ "VIX", 1001, 2, "Virtual 1" };
   currency_unit cu3{ "VIR", 1002, 2, "Virtual 1" };
   currency_unit cu4{ "VIR", 1001, 3, "Virtual 1" };
   currency_unit cu5{ "VIR", 1001, 2, "Virtual 2" };

   REQUIRE(cu1 != cu2);
   REQUIRE(cu1 != cu3);
   REQUIRE(cu1 != cu4);
   REQUIRE(cu1 != cu5);
}

TEST_CASE("Unique currency codes", "[currency]")
{
   auto db = std::vector<currency_unit> {currency::currencies};
   
   std::set<int> codes;
   for(auto const & cu : db)
   {
      auto result = codes.insert(cu.number);
      REQUIRE(result.second != false);
   }
}

TEST_CASE("Unique currency names", "[currency]")
{
   auto db = std::vector<currency_unit> {currency::currencies};
   
   std::set<std::string_view> codes;
   for(auto const & cu : db)
   {
      auto result = codes.insert(cu.name);
      REQUIRE(result.second != false);
   }
}

