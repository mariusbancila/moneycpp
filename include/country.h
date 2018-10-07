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
      constexpr country_unit DK { 208, "DK", "DNK", "Demark", true };
      constexpr country_unit DJ { 262, "DJ", "DJI", "Djibouti", true };
      constexpr country_unit DM { 212, "DM", "DMA", "Dominica", true };
      constexpr country_unit DO { 214, "DO", "DOM", "Dominican Republic", true };
      constexpr country_unit EC { 218, "EC", "ECU", "Ecuador", true };
      constexpr country_unit EG { 818, "EG", "EGY", "Egypt", true };
      constexpr country_unit SV { 222, "SV", "SLV", "El Salvador", true };
      constexpr country_unit GQ { 226, "GQ", "GNQ", "Equatorial Guinea", true };
      constexpr country_unit ER { 232, "ER", "ERI", "Eritrea", true };
      constexpr country_unit EE { 233, "EE", "EST", "Estonia", true };
      constexpr country_unit SZ { 748, "SZ", "SWZ", "Eswatini", true };
      constexpr country_unit ET { 231, "ET", "ETH", "Ethiopia", true };
      constexpr country_unit FK { 238, "FK", "FLK", "Falkland Islands", false };
      constexpr country_unit FO { 234, "FO", "FRO", "Faroe Islands", false };
      constexpr country_unit FJ { 242, "FJ", "FJI", "Fiji", true };
      constexpr country_unit FI { 246, "FI", "FIN", "Finland", true };
      constexpr country_unit FR { 250, "FR", "FRA", "France", true };
      constexpr country_unit GF { 254, "GF", "GUF", "French Guiana", false };
      constexpr country_unit PF { 258, "PF", "PYF", "French Polynesia", false };
      constexpr country_unit TF { 260, "TF", "ATF", "French Southern Territories", false };
      constexpr country_unit GA { 266, "GA", "GAB", "Gabon", true };
      constexpr country_unit GM { 270, "GM", "GMB", "Gambia", true };
      constexpr country_unit GE { 268, "GE", "GEO", "Georgia", true };
      constexpr country_unit DE { 276, "DE", "DEU", "Germany", true };
      constexpr country_unit GH { 288, "GH", "GHA", "Ghana", true };
      constexpr country_unit GI { 292, "GI", "GIB", "Gibraltar", false };
      constexpr country_unit GR { 300, "GR", "GRC", "Greece", true };
      constexpr country_unit GL { 304, "GL", "GRL", "Greenland", false };
      constexpr country_unit GD { 308, "GD", "GRD", "Grenada", true };
      constexpr country_unit GP { 312, "GP", "GLP", "Guadeloupe", false };
      constexpr country_unit GU { 316, "GU", "GUM", "Guam", false };
      constexpr country_unit GT { 320, "GT", "GTM", "Guatemala", true };
      constexpr country_unit GG { 831, "GG", "GGY", "Guernsey", false };
      constexpr country_unit GN { 324, "GN", "GIN", "Guinea", true };
      constexpr country_unit GW { 624, "GW", "GNB", "Guinea-Bissau", true };
      constexpr country_unit GY { 328, "GY", "GUY", "Guyana", true };
      constexpr country_unit HT { 332, "HT", "HTI", "Haiti", true };
      constexpr country_unit HM { 334, "HM", "HMD", "Heard Island and McDonald Islands", false };
      constexpr country_unit VA { 336, "VA", "VAT", "Vatican", true };
      constexpr country_unit HN { 340, "HN", "HND", "Honduras", true };
      constexpr country_unit HK { 344, "HK", "HKG", "Hong Kong", false };
      constexpr country_unit HU { 348, "HU", "HUN", "Hungary", true };
      constexpr country_unit IS { 352, "IS", "ISL", "Iceland", true };
      constexpr country_unit IN { 356, "IN", "IND", "India", true };
      constexpr country_unit ID { 360, "ID", "IDN", "Indonesia", true };
      constexpr country_unit IR { 364, "IR", "IRN", "Iran", true };
      constexpr country_unit IQ { 368, "IQ", "IRQ", "Iraq", true };
      constexpr country_unit IE { 372, "IE", "IRL", "Ireland", true };
      constexpr country_unit IM { 833, "IM", "IMN", "Isle of Man", false };
      constexpr country_unit IL { 376, "IL", "ISR", "Israel", true };
      constexpr country_unit IT { 380, "IT", "ITA", "Italy", true };
      constexpr country_unit JM { 388, "JM", "JAM", "Jamaica", true };
      constexpr country_unit JP { 392, "JP", "JPN", "Japan", true };
      constexpr country_unit JE { 832, "JE", "JEY", "Jersey", false };
      constexpr country_unit JO { 400, "JO", "JOR", "Jordan", true };
      constexpr country_unit KZ { 398, "KZ", "KAZ", "Kazakhstan", true };
      constexpr country_unit KE { 404, "KE", "KEN", "Kenya", true };
      constexpr country_unit KI { 296, "KI", "KIR", "Kiribati", true };
      constexpr country_unit KP { 408, "KP", "PRK", "Democratic People's Republic of Korea", true };
      constexpr country_unit KR { 410, "KR", "KOR", "Republic of Korea", true };
      constexpr country_unit KW { 414, "KW", "KWT", "Kuwait", true };
      constexpr country_unit KG { 417, "KG", "KGZ", "Kyrgystan", true };
      constexpr country_unit LA { 418, "LA", "LAO", "Lao", true };
      constexpr country_unit LV { 428, "LV", "LVA", "Latvia", true };
      constexpr country_unit LB { 422, "LB", "LBN", "Lebanon", true };
      constexpr country_unit LS { 426, "LS", "LSO", "Lesotho", true };
      constexpr country_unit LR { 430, "LR", "LBR", "Liberia", true };
      constexpr country_unit LY { 434, "LY", "LBY", "Libya", true };
      constexpr country_unit LI { 438, "LI", "LIE", "Liechtenstein", true };
      constexpr country_unit LT { 440, "LT", "LTU", "Lithuania", true };
      constexpr country_unit LU { 442, "LU", "LUX", "Luxembourg", true };
      constexpr country_unit MO { 446, "MO", "MAC", "Macao", false };
      constexpr country_unit MK { 807, "MK", "MKD", "Macedonia", true };
      constexpr country_unit MG { 450, "MG", "MDG", "Madagascar", true };
      constexpr country_unit MW { 454, "MW", "MWI", "Malawi", true };
      constexpr country_unit MY { 458, "MY", "MYS", "Malaysia", true };
      constexpr country_unit MV { 462, "MV", "MDV", "Maldives", true };
      constexpr country_unit ML { 466, "ML", "MLI", "Mali", true };
      constexpr country_unit MT { 470, "MT", "MLT", "Malta", true };
      constexpr country_unit MH { 584, "MH", "MHL", "Marshall Islands", true };
      constexpr country_unit MQ { 474, "MQ", "MTQ", "Martinique", false };
      constexpr country_unit MR { 478, "MR", "MRT", "Mauritania", true };
      constexpr country_unit MU { 480, "MU", "MUS", "Mauritius", true };
      constexpr country_unit YT { 175, "YT", "MYT", "Mayotte", false };
      constexpr country_unit MX { 484, "MX", "MEX", "Mexico", true };
      constexpr country_unit FM { 583, "FM", "FSM", "Micronesia", true };
      constexpr country_unit MD { 498, "MD", "MDA", "Moldova", true };
      constexpr country_unit MC { 492, "MC", "MCO", "Monaco", true };
      constexpr country_unit MN { 496, "MN", "MNG", "Mongolia", true };
      constexpr country_unit ME { 499, "ME", "MNE", "Montenegro", true };
      constexpr country_unit MS { 500, "MS", "MSR", "Montserrat", false };
      constexpr country_unit MA { 504, "MA", "MAR", "Morocco", true };
      constexpr country_unit MZ { 508, "MZ", "MOZ", "Mozambique", true };
      constexpr country_unit MM { 104, "MM", "MMR", "Myanmar", true };
      constexpr country_unit NA { 516, "NA", "NAM", "Namibia", true };
      constexpr country_unit NR { 520, "NR", "NRU", "Nauru", true };
      constexpr country_unit NP { 524, "NP", "NPL", "Nepal", true };
      constexpr country_unit NL { 528, "NL", "NLD", "Netherlands", true };
      constexpr country_unit NC { 540, "NC", "NCL", "New Caledonia", false };
      constexpr country_unit NZ { 554, "NZ", "NZL", "New Zealand", true };
      constexpr country_unit NI { 558, "NI", "NIC", "Nicaragua", true };
      constexpr country_unit NE { 562, "NE", "NER", "Niger", true };
      constexpr country_unit NG { 566, "NG", "NGA", "Nigeria", true };
      constexpr country_unit NU { 570, "NU", "NIU", "Niue", false };
      constexpr country_unit NF { 574, "NF", "NFK", "Norfolk Island", false };
      constexpr country_unit MP { 580, "MP", "MNP", "Northern Mariana Islands", false };
      constexpr country_unit NO { 578, "NO", "NOR", "Norway", true };

      //constexpr country_unit  {  , "", "", "", true };

      static const std::initializer_list<country_unit> countries
      {
         AF, AX, AL, AS, AD, AO, AI, AQ, AG, AR, AM, AW, AU, AT, AZ,
         BS, BH, BD, BB, BY, BE, BZ, BJ, BM, BT, BO, BQ, BA, BW, BV, BR, BN, BG, BF, BI,
         CV, CM, CA, CF, CL, CN, CX, CC, CO, CG, CD, CK, CR, CI, CU, CW, CY, CZ, 
         DZ, DK, DJ, DM, DO, DE, 
         EC, EG, ER, EE, ET, 
         FK, FO, FJ, FI, FR, FM, 
         GQ, GF, GA, GM, GE, GH, GI, GR, GL, GD, GP, GU, GT, GG, GN, GW, GY, 
         HR, HT, HM, HN, HK, HU, 
         IO, IS, IN, ID, IR, IQ, IE, IM, IL, IT,
         JM, JP, JE, JO, 
         KH, KY, KM, KZ, KE, KI, KP, KR, KW, KG, 
         LA, LV, LB, LS, LR, LY, LI, LT, LU,
         MO, MK, MG, MW, MY, MV, ML, MT, MH, MQ, MR, MU, MX, MD, MC, MN, ME, MS, MA, MZ, MM, MP, 
         NA, NR, NP, NL, NC, NZ, NI, NE, NG, NU, NF, NO, 
         PF, 
         SV, SZ, 
         TD, TF, 
         VA, 
         YT,
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