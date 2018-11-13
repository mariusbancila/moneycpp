#pragma once

#include "country.h"
#include "currency.h"
#include <map>
#include <set>

namespace moneycpp
{
   using country_currency_map = std::multimap<country_unit, currency_unit>;

   namespace country
   {
      using namespace currency;

      template <typename Map = country_currency_map>
      inline std::set<currency_unit> find_country_currencies(
         Map const & map,
         country_unit const & cu)
      {
         std::set<currency_unit> result;
         auto range = map.equal_range(cu);
         for (auto it = range.first; it != range.second; ++it)
         {
            result.insert(it->second);
         }
         return result;
      }

      template <typename Map>
      inline std::pair<typename Map::const_iterator, typename Map::const_iterator> country_currency_equal_range(
         Map const & map,
         country_unit const & cu)
      {
         return map.equal_range(cu);
      }

#ifdef HAS_COUNTRY_AND_CURRENCY_DB

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
         {BQ, USD},  // Bonaire, Sint Eustatius and Saba (Netherlands)
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

                     // I
         {IS, ISK},  // Iceland
         {IN, INR},  // India
         {ID, IDR},  // Indonesia
         {IR, IRR},  // Iran
         {IQ, IQD},  // Iraq
         {IE, EUR},  // Ireland
         {IM, GBP},  // Isle of Man (UK)
         {IM, IMP},  // Isle of Man (UK)
         {IL, ILS},  // Israel
         {IT, EUR},  // Italy

                     // J
         {JM, JMD},  // Jamaica
         {JP, JPY},  // Japan
         {JE, GBP},  // Jersey (UK)	
         {JE, JEP},  // Jersey (UK)	
         {JO, JOD},  // Jordan

                     // K
         {KZ, KZT},  // Kazakhstan
         {KE, KES},  // Kenya
         {KI, AUD},  // Kiribati
         {KP, KPW},  // Democratic People's Republic of Korea
         {KR, KRW},  // Republic of Korea
         {KW, KWD},  // Kuwait
         {KG, KGS},  // Kyrgyzstan

                     // L
         {LA, LAK},  // Laos
         {LV, EUR},  // Latvia
         {LB, LBP},  // Lebanon
         {LS, LSL},  // Lesotho
         {LS, ZAR},  // Lesotho
         {LR, LRD},  // Liberia
         {LY, LYD},  // Libya
         {LI, CHF},  // Liechtenstein
         {LT, EUR},  // Lithuania
         {LU, EUR},  // Luxembourg

                     // M
         {MO, MOP},  // Macau (China)
         {MK, MKD},  // Macedonia (FYROM)
         {MG, MGA},  // Madagascar
         {MW, MWK},  // Malawi
         {MY, MYR},  // Malaysia
         {MV, MVR},  // Maldives
         {ML, XOF},  // Mali
         {MT, EUR},  // Malta
         {MH, USD},  // Marshall Islands
         {MQ, EUR},  // Martinique (France)
         {MR, MRU},  // Mauritania
         {MU, MUR},  // Mauritius
         {YT, EUR},  // Mayotte (France)
         {MX, MXN},  // Mexico
         {MX, MXV},  // Mexico
         {FM, USD},  // Micronesia
         {MD, MDL},  // Moldova
         {MC, EUR},  // Monaco
         {MN, MNT},  // Mongolia
         {ME, EUR},  // Montenegro
         {MS, XCD},  // Montserrat (UK)
         {MA, MAD},  // Morocco
         {MZ, MXN},  // Mozambique
         {MM, MMK},  // Myanmar

                     // N
         {NA, NAD},  // Namibia
         {NA, ZAR},  // Namibia
         {NR, AUD},  // Nauru
         {NP, NPR},  // Nepal
         {NL, EUR},  // Netherlands
         {NC, XPF},  // New Caledonia (France)
         {NZ, NZD},  // New Zealand
         {NI, NIO},  // Nicaragua
         {NE, XOF},  // Niger
         {NG, NGN},  // Nigeria
         {NU, NZD},  // Niue (New Zealand)
         {NF, AUD},  // Norfolk Island (Australia)
         {MP, USD},  // Northern Mariana Islands (USA)
         {NO, NOK},  // Norway

                     // O
         {OM, OMR},  // Oman

         {PK, PKR},  // Pakistan
         {PW, USD},  // Palau
         {PS, ILS},  // Palestine
         {PA, PAB},  // Panama
         {PA, USD},  // Panama
         {PG, PGK},  // Papua New Guinea
         {PY, PYG},  // Paraguay
         {PE, PEN},  // Peru
         {PH, PHP},  // Philippines
         {PN, NZD},  // Pitcairn Islands (UK)
         {PL, PLN},  // Poland
         {PT, EUR},  // Portugal
         {PR, USD},  // Puerto Rico (USA)

                     // Q
         {QA, QAR},  // Qatar

                     // R
         {RE, EUR},  // Reunion (France)
         {RO, RON},  // Romania
         {RU, RUB},  // Russia
         {RW, RWF},  // Rwanda

                     // S
         {BL, EUR},  // Saint Barthelemy (France)
         {SH, SHP},  // Saint Helena, Ascension and Tristan da Cunha (UK)
         {KN, XCD},  // Saint Kitts and Nevis
         {LC, XCD},  // Saint Lucia
         {MF, EUR},  // Saint Martin (France)
         {PM, EUR},  // Saint Pierre and Miquelon (France)
         {VC, XCD},  // Saint Vincent and the Grenadines
         {WS, WST},  // Samoa
         {SM, EUR},  // San Marino
         {ST, STN},  // Sao Tome and Principe
         {SA, SAR},  // Saudi Arabia
         {SN, XOF},  // Senegal
         {RS, RSD},  // Serbia
         {SC, SCR},  // Seychelles
         {SL, SLL},  // Sierra Leone
         {SG, SGD},  // Singapore
         {SX, ANG},  // Sint Maarten (Netherlands)
         {SK, EUR},  // Slovakia
         {SI, EUR},  // Slovenia
         {SB, SBD},  // Solomon Islands
         {SO, SOS},  // Somalia
         {ZA, ZAR},  // South Africa
         {GS, GBP},  // South Georgia Island (UK)
         {SS, SSP},  // South Sudan
         {ES, EUR},  // Spain
         {LK, LKR},  // Sri Lanka
         {SD, SDG},  // Sudan
         {SR, SRD},  // Suriname
         {SJ, NOK},  // Svalbard and Jan Mayen (Norway)
         {SE, SEK},  // Sweden
         {CH, CHF},  // Switzerland
         {CH, CHE},  // Switzerland
         {CH, CHW},  // Switzerland
         {SY, SYP},  // Syria

                     // T
         {TW, TWD},  // Taiwan
         {TJ, TJS},  // Tajikistan
         {TZ, TZS},  // Tanzania
         {TH, THB},  // Thailand
         {TL, USD},  // Timor-Leste
         {TG, XOF},  // Togo
         {TK, NZD},  // Tokelau (New Zealand)
         {TO, TOP},  // Tonga
         {TT, TTD},  // Trinidad and Tobago
         {TN, TND},  // Tunisia
         {TR, TRY},  // Turkey
         {TM, TMT},  // Turkmenistan
         {TC, USD},  // Turks and Caicos Islands (UK)
         {TV, AUD},  // Tuvalu

                     // U
         {UG, UGX},  // Uganda
         {UA, UAH},  // Ukraine
         {AE, AED},  // United Arab Emirates
         {GB, GBP},  // United Kingdom
         {US, USD},  // United States of America
         {US, USN},  // United States of America
         {UM, USD},  // United States Minor Outlying Islands
         {VI, USD},  // US Virgin Islands (USA)
         {UY, UYU},  // Uruguay
         {UY, UYI},  // Uruguay
         {UZ, UZS},  // Uzbekistan

                     // V
         {VU, VUV},  // Vanuatu
         {VA, EUR},  // Vatican City (Holy See)
         {VE, VES},  // Venezuela
         {VN, VND},  // Vietnam

                     // W
         {WF, XPF},  // Wallis and Futuna (France)
         {EH, MAD},  // Western Sahara

                     // Y
         {YE, YER},  // Yemen

                     // X
         {ZM, ZMW},  // Zambia
         {ZW, USD},  // Zimbabwe
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
         return find_country_currencies(currencies, cu);
      }

      inline std::pair<typename country_currency_map::const_iterator, typename country_currency_map::const_iterator> country_currency_equal_range(
         country_unit const & cu)
      {
         return country_currency_equal_range(currencies, cu);
      }

#endif
   }
}