#pragma once

#include "country.h"
#include "currency.h"
#include <map>
#include <set>

namespace moneycpp
{
   namespace country
   {
      using country_currency_map = std::multimap<country_unit, currency_unit>;
      using namespace currency;

      // compiled from the following sources
      //   https://www.iban.com/currency-codes
      //   https://www.countries-ofthe-world.com/world-currencies.html
      static const country_currency_map currencies
      {
                     // A
         {AF, AFN},  // Afghanistan
         {AX, EUR},  // Aland Islands (Finland)	
         {AL, ALL},  // Albania
         {DZ, DZD},  // Algeria
         {AS, USD},  // American Samoa (USA)
         {AD, EUR},  // Andorra
         {AO, AOA},  // Angola
         {AI, XCD},  // Anguilla (UK)
         {AG, XCD},  // Antigua and Barbuda
         {AR, ARS},  // Argentina
         {AM, AMD},  // Armenia
         {AW, AWG},  // Aruba (Netherlands)
         {AU, AUD},  // Australia
         {AT, EUR},  // Austria	
         {AZ, AZN},  // Azerbaijan

                     // B
         {BS, BSD},  // Bahamas
         {BH, BHD},  // Bahrain
         {BD, BDT},  // Bangladesh
         {BB, BBD},  // Barbados
         {BY, BYN},  // Belarus
         {BE, EUR},  // Belgium
         {BZ, BZD},  // Belize
         {BJ, XOF},  // Benin
         {BM, BMD},  // Bermuda (UK)
         {BT, BTN},  // Bhutan
         {BT, INR},  // Bhutan
         {BO, BOB},  // Bolivia
         {BO, BOV},  // Bolivia
         {BQ, USD},  // Bonaire (Netherlands)
         {BA, BAM},  // Bosnia and Herzegovina	
         {BW, BWP},  // Botswana
         {BV, NOK},  // Bouvet Island (NO)
         {BR, BRL},  // Brazil
         {IO, USD},  // British Indian Ocean Territory (UK)
         {VG, USD},  // British Virgin Islands (UK)
         {BN, BND},  // Brunei
         {BG, BGN},  // Bulgaria
         {BF, XOF},  // Burkina Faso
         {BI, BIF},  // Burundi

                     // C
         {CV, CVE},  // Cabo Verde
         {KH, KHR},  // Cambodia
         {CM, XAF},  // Cameroon
         {CA, CAD},  // Canada
         {KY, KYD},  // Cayman Islands (UK)
         {CF, XAF},  // Central African Republic
         {TD, XAF},  // Chad
         {CL, CLP},  // Chile
         {CL, CLF},  // Chile
         {CN, CNY},  // China
         {CX, AUD},  // Christmas Island (Australia)
         {CC, AUD},  // Cocos (Keeling) Islands (Australia)
         {CO, COP},  // Colombia
         {CO, COU},  // Colombia
         {KM, KMF},  // Comoros
         {CD, CDF},  // Congo, Democratic Republic of the
         {CG, XAF},  // Congo, Republic of the
         {CK, NZD},  // Cook Islands (New Zealand)
         {CR, CRC},  // Costa Rica
         {CI, XOF},  // Cote d'Ivoire
         {HR, HRK},  // Croatia
         {CU, CUP},  // Cuba
         {CU, CUC},  // Cuba
         {CW, ANG},  // Curacao (Netherlands)
         {CY, EUR},  // Cyprus
         {CZ, CZK},  // Czech Republic

                     // D
         {DK, DKK},  // Denmark
         {DJ, DJF},  // Djibouti
         {DM, XCD},  // Dominica
         {DO, DOP},  // Dominican Republic

                     // E
         {EC, USD},  // Ecuador
         {EG, EGP},  // Egypt
         {SV, SVC},  // El Salvador
         {SV, USD},  // El Salvador
         {GQ, XAF},  // Equatorial Guinea
         {ER, ERN},  // Eritrea
         {EE, EUR},  // Estonia
         {SZ, SZL},  // Eswatini (formerly Swaziland)
         {ET, ETB},  // Ethiopia

                     // F
         {FK, FKP},  // Falkland Islands (UK)
         {FO, DKK},  // Faroe Islands (Denmark)
         {FJ, FJD},  // Fiji
         {FI, EUR},  // Finland
         {FR, EUR},  // France
         {GF, EUR},  // French Guiana (France)
         {PF, XPF},  // French Polynesia (France)
         {TF, EUR},  // French Southern Territories (France)

                     // G
         {GA, XAF},  // Gabon
         {GM, GMD},  // Gambia
         {GE, GEL},  // Georgia
         {DE, EUR},  // Germany
         {GH, GHS},  // Ghana
         {GI, GIP},  // Gibraltar (UK)
         {GR, EUR},  // Greece
         {GL, DKK},  // Greenland (Denmark)
         {GD, XCD},  // Grenada
         {GP, EUR},  // Guadeloupe (France)
         {GU, USD},  // Guam (USA)
         {GT, GTQ},  // Guatemala
         {GG, GBP},  // Guernsey (UK)
         {GG, GGP},  // Guernsey (UK)
         {GN, GNF},  // Guinea
         {GW, XOF},  // Guinea-Bissau
         {GY, GYD},  // Guyana

                     // H
         {HT, HTG},  // Haiti
         {HT, USD},  // Haiti
         {HM, AUD},  // Heard Island and McDonald Islands
         {VA, EUR},  // Holy See
         {HN, HNL},  // Honduras
         {HK, HKD},  // Hong Kong (China)
         {HU, HUF},  // Hungary

         //{, },  // 
      };
      
      currency_unit find_country_currency(country_unit const & cu)
      {
         auto range = currencies.equal_range(cu);
         if (range.first == range.second)
            throw currency_not_found{};

         return range.first->second;
      }

      inline std::set<currency_unit> find_country_currencies(
         country_unit const & cu)
      {
         std::set<currency_unit> result;
         auto range = currencies.equal_range(cu);
         for (auto it = range.first; it != range.second; ++it)
         {
            result.insert(it->second);
         }
         return result;
      }
      
      template <typename Map>
      inline std::pair<typename Map::iterator, typename Map::iterator> find_country_currency(
         Map map, 
         country_unit const & cu)
      {
         return map.equal_range(cu);
      }      
   }
}