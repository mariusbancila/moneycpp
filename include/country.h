#pragma once

#include <initializer_list>
#include <string_view>
#include <optional>

namespace moneycpp
{
   struct country_unit
   {
      int              const code;
      std::string_view const alpha2;
      std::string_view const alpha3;
      std::string_view const name;
      bool             const independent;
   };

   constexpr bool operator==(country_unit const & lhs, country_unit const & rhs) noexcept
   {
      return
         lhs.code == rhs.code &&
         lhs.alpha2 == rhs.alpha2 &&
         lhs.alpha3 == rhs.alpha3;
   }

   constexpr bool operator!=(country_unit const & lhs, country_unit const & rhs) noexcept
   {
      return !(lhs == rhs);
   }

   namespace country
   {
      // ISO 3166-1 country codes
      constexpr country_unit AF {   4, "AF", "AFG", "Afganistan", true };
      constexpr country_unit AX { 248, "AX", "ALA", "Åland Islands", false };
      constexpr country_unit AL {   8, "AL", "ALB", "Albania", true };
      constexpr country_unit DZ {  12, "DL", "DZA", "Algeria", true };
      constexpr country_unit AS {  16, "AS", "ASM", "American Samoa", false };
      constexpr country_unit AD {  20, "AD", "AND", "Andorra", true };
      constexpr country_unit AO {  24, "AO", "AGO", "Angola", true };
      constexpr country_unit AI { 660, "AI", "AIA", "Anguilla", false };
      constexpr country_unit AQ {  10, "AQ", "ATA", "Antartica", false };
      constexpr country_unit AG {  28, "AG", "ATG", "Antigua and Barbuda", true };
      constexpr country_unit AR {  32, "AR", "ARG", "Argentina", true };
      constexpr country_unit AM {  51, "AM", "ARM", "Armenia", true };
      constexpr country_unit AW { 533, "AW", "ABW", "Aruba", false };
      constexpr country_unit AU {  36, "AU", "AUS", "Australia", true };
      //constexpr country_unit AS {  , "", "", "", true };

      static const std::initializer_list<country_unit> countries
      {
         AF, AX, AL, AS, AD, AO, AI, AQ, AG, AR, AM, AW, AU,
         DZ,
      };
   }

   inline std::optional<country_unit> find_country(int const code)
   {
      for (auto const & cu : country::countries)
      {
         if (cu.code == code)
            return std::optional{ cu };
      }
      return {};
   }

   inline std::optional<country_unit> find_country(std::string_view alpha2)
   {
      for (auto const & cu : country::countries)
      {
         if (cu.alpha2 == alpha2)
            return std::optional{ cu };
      }

      return {};
   }

}