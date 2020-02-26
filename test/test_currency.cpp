#ifndef HAS_COUNTRY_AND_CURRENCY_DB
#define HAS_COUNTRY_AND_CURRENCY_DB
#endif

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

TEST_CASE("Unique currencies", "[currency]")
{
   auto db = std::vector<currency_unit> {currency::currencies};
   
   std::set<int> codes;
   std::set<std::string_view> names;
   for(auto const & cu : db)
   {
      if (cu.number > 0)
      {
         codes.insert(cu.number);
         names.insert(cu.name);
      }
   }

   auto count = std::count_if(
      std::begin(db), std::end(db),
      [](currency_unit const & cu) {return cu.number > 0; });

   REQUIRE(codes.size() == count);
   REQUIRE(names.size() == count);
}

TEST_CASE("Test find currency", "[find][currency]")
{
   {
      auto cu1 = find_currency("USD");
      REQUIRE(cu1.has_value());
      REQUIRE(cu1.value() == currency::USD);

      auto cu2 = find_currency("DSU");
      REQUIRE(!cu2.has_value());
   }

   {
      auto cu1 = find_currency(840);
      REQUIRE(cu1.has_value());
      REQUIRE(cu1.value() == currency::USD);

      auto cu2 = find_currency(1);
      REQUIRE(!cu2.has_value());
   }

   {
      auto cu1 = find_currency("EUR");
      auto cu2 = find_currency(978);
      REQUIRE(cu1 == cu2);
   }
}

TEST_CASE("Test find currency iter", "[find][currency]")
{
   {
      auto cu1 = find_currency(
         std::cbegin(currency::currencies),
         std::cend(currency::currencies),
         "USD");
      REQUIRE(cu1 != std::cend(currency::currencies));
      REQUIRE(*cu1 == currency::USD);

      auto cu2 = find_currency(
         std::cbegin(currency::currencies),
         std::cend(currency::currencies), 
         "DSU");
      REQUIRE(cu2 == std::cend(currency::currencies));
   }

   {
      auto cu1 = find_currency(
         std::cbegin(currency::currencies),
         std::cend(currency::currencies), 
         840);
      REQUIRE(cu1 != std::cend(currency::currencies));
      REQUIRE(*cu1 == currency::USD);

      auto cu2 = find_currency(
         std::cbegin(currency::currencies),
         std::cend(currency::currencies), 
         1);
      REQUIRE(cu2 == std::cend(currency::currencies));
   }
}

TEST_CASE("Test find my currency", "[find][currency]")
{
   std::vector<currency_unit> my_currencies{ currency::currencies };
   my_currencies.emplace_back(currency_unit{ "VIR", 1001, 2, "Virtual Currency" });

   auto cu1 = find_currency(
      std::cbegin(my_currencies),
      std::cend(my_currencies),
      "VIR");

   auto cu2 = find_currency(
      std::cbegin(my_currencies),
      std::cend(my_currencies),
      1001);

   REQUIRE(cu1 != std::cend(my_currencies));
   REQUIRE(cu1 == cu2);
}