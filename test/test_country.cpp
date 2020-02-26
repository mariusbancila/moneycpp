#ifndef HAS_COUNTRY_AND_CURRENCY_DB
#define HAS_COUNTRY_AND_CURRENCY_DB
#endif

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

TEST_CASE("Test find country", "[find][country]")
{
   {
      auto cu1 = find_country("AU");
      REQUIRE(cu1.has_value());
      REQUIRE(cu1.value() == country::AU);

      auto cu2 = find_country("AA");
      REQUIRE(!cu2.has_value());
   }

   {
      auto cu1 = find_country(36);
      REQUIRE(cu1.has_value());
      REQUIRE(cu1.value() == country::AU);

      auto cu2 = find_country(1);
      REQUIRE(!cu2.has_value());
   }

   {
      auto cu1 = find_country("US");
      auto cu2 = find_country(840);
      REQUIRE(cu1 == cu2);
   }
}

TEST_CASE("Test find country iter", "[find][country]")
{
   {
      auto cu1 = find_country(
         std::cbegin(country::countries),
         std::cend(country::countries),
         "AU");
      REQUIRE(cu1 != std::cend(country::countries));
      REQUIRE(*cu1 == country::AU);

      auto cu2 = find_country(
         std::cbegin(country::countries),
         std::cend(country::countries), 
         "AA");
      REQUIRE(cu2 == std::cend(country::countries));
   }

   {
      auto cu1 = find_country(
         std::cbegin(country::countries),
         std::cend(country::countries), 
         36);
      REQUIRE(cu1 != std::cend(country::countries));
      REQUIRE(*cu1 == country::AU);

      auto cu2 = find_country(
         std::cbegin(country::countries),
         std::cend(country::countries), 
         1);
      REQUIRE(cu2 == std::cend(country::countries));
   }
}

TEST_CASE("Test find my country", "[find][country]")
{
   std::vector<country_unit> my_countries{country::countries};
   my_countries.emplace_back(country_unit{ 1001, "OT", "OTH", "Otheria", true });

   auto cu1 = find_country(
      std::cbegin(my_countries),
      std::cend(my_countries),
      "OT");

   auto cu2 = find_country(
      std::cbegin(my_countries),
      std::cend(my_countries),
      1001);

   REQUIRE(cu1 != std::cend(my_countries));
   REQUIRE(cu1 == cu2);
}