#include "currency.h"
#include "catch.hpp"

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