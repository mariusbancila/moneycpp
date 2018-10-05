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
      constexpr country_unit AX { 248, "AX", "ALA", "Aland Islands", false };
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
      constexpr country_unit AT {  40, "AT", "AUT", "Austria", true };
      constexpr country_unit AZ {  31, "AZ", "AZE", "Azerbaijan", true };
      constexpr country_unit BS {  44, "BS", "BHS", "Bahamas", true };
      constexpr country_unit BH {  48, "BH", "BHR", "Bahrain", true };
      constexpr country_unit BD {  50, "BD", "BGD", "Bangladesh", true };
      constexpr country_unit BB {  52, "BB", "BRB", "Barbados", true };
      constexpr country_unit BY { 112, "BY", "BLR", "Belarus", true };
      constexpr country_unit BE {  56, "BE", "BEL", "Belgium", true };
      constexpr country_unit BZ {  84, "BZ", "BLZ", "Belize", true };
      constexpr country_unit BJ { 204, "BJ", "BEN", "Benin", true };
      constexpr country_unit BM {  60, "BM", "BMU", "Bermuda", false };
      constexpr country_unit BT {  64, "BT", "BTN", "Bhutan", true };
      constexpr country_unit BO {  68, "BO", "BOL", "Bolivia", true };
      constexpr country_unit BQ { 535, "BQ", "BES", "Bonaire, Sint Eustatius and Saba", false };
      constexpr country_unit BA {  70, "BA", "BIH", "Bosmia and Herzegovina", true };
      constexpr country_unit BW {  72, "BW", "BWA", "Botswana", true };
      constexpr country_unit BV {  74, "BV", "BVT", "Bouvet Island", false };
      constexpr country_unit BR {  76, "BR", "BRA", "Brazil", true };
      constexpr country_unit IO {  86, "IO", "IOT", "British Indian Ocean Teritory", false };
      constexpr country_unit BN {  96, "BN", "BRN", "Brunei Darussalam", true };
      constexpr country_unit BG { 100, "BG", "BGR", "Bulgaria", true };
      constexpr country_unit BF { 854, "BF", "BFA", "Burkina Faso", true };
      constexpr country_unit BI { 108, "BI", "BDI", "Burundi", true };
      constexpr country_unit CV { 132, "CV", "CPV", "Cabo Verde", true };
      constexpr country_unit KH { 116, "KH", "KHM", "Cambodia", true };
      constexpr country_unit CM { 120, "CM", "CMR", "Cameroon", true };
      constexpr country_unit CA { 124, "CA", "CAN", "Canada", true };
      constexpr country_unit KY { 136, "KY", "CYM", "Cayman Islands", false };
      constexpr country_unit CF { 140, "CF", "CAF", "Central African Republic", true };
      constexpr country_unit TD { 148, "TD", "TDC", "Chad", true };
      constexpr country_unit CL { 152, "CL", "CHL", "Chile", true };
      constexpr country_unit CN { 156, "CN", "CHN", "China", true };
      constexpr country_unit CX { 162, "CX", "CXR", "Christmas Island", false };
      constexpr country_unit CC { 166, "CC", "CCK", "Cocos Islands", false };
      constexpr country_unit CO { 170, "CO", "COL", "Colombia", true };
      constexpr country_unit KM { 174, "KM", "COM", "Comoros", true };
      constexpr country_unit CG { 178, "CG", "COG", "Congo", true };
      constexpr country_unit CD { 180, "CD", "COD", "Congo (Democratic Republic of the)", true };
      constexpr country_unit CK { 184, "CK", "COK", "Cook Islands", false };
      constexpr country_unit CR { 188, "CR", "CRI", "Costa Rica", true };
      constexpr country_unit CI { 384, "CI", "CIV", "Côte d'Ivoire", true };
      constexpr country_unit HR { 191, "HR", "HRV", "Croatia", true };
      constexpr country_unit CU { 192, "CU", "CUB", "Cuba", true };
      constexpr country_unit CW { 531, "CW", "CUW", "Curaçao", false };
      constexpr country_unit CY { 196, "CY", "CYP", "Cyprus", true };
      constexpr country_unit CZ { 203, "CZ", "CZE", "Czechia", true };
      //constexpr country_unit  {  , "", "", "", true };

      static const std::initializer_list<country_unit> countries
      {
         AF, AX, AL, AS, AD, AO, AI, AQ, AG, AR, AM, AW, AU, AT, AZ,
         BS, BH, BD, BB, BY, BE, BZ, BJ, BM, BT, BO, BQ, BA, BW, BV, BR, BN, BG, BF, BI,
         CV, CM, CA, CF, CL, CN, CX, CC, CO, CG, CD, CK, CR, CI, CU, CW, CY, CZ, 
         DZ,
         HR,
         IO,
         KH, KY, KM, 
         TD, 
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