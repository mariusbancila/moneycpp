#pragma once

#include <initializer_list>
#include <string_view>
#include <optional>

namespace moneycpp
{
   struct currency_unit
   {
      std::string_view const code;
      int              const number;
      int              const minor_unit;
      std::string_view const name;
   };

   inline constexpr bool operator==(currency_unit const & lhs, currency_unit const & rhs) noexcept
   {
      return 
         lhs.number == rhs.number &&
         lhs.code == rhs.code &&
         lhs.minor_unit == rhs.minor_unit &&
         lhs.name == rhs.name;
   }

   inline constexpr bool operator!=(currency_unit const & lhs, currency_unit const & rhs) noexcept
   {
      return !(lhs == rhs);
   }

   inline constexpr bool operator<(currency_unit const & lhs, currency_unit const & rhs) noexcept
   {
      return lhs.number < rhs.number;
   }

   namespace currency
   {
      // active ISO 4217 currency codes 
      constexpr currency_unit AED { "AED", 784, 2, "United Arab Emirates dirham" };
      constexpr currency_unit AFN { "AFN", 971, 2, "Afghan afghani" };
      constexpr currency_unit ALL { "ALL",   8, 2, "Albanian lek" };
      constexpr currency_unit AMD { "AMD",  51, 2, "Armenian dram" };
      constexpr currency_unit ANG { "ANG", 532, 2, "Netherlands Antillean guilder" };
      constexpr currency_unit AOA { "AOA", 973, 2, "Angolan kwanza" };
      constexpr currency_unit ARS { "ARS",  32, 2, "Argentine peso" };
      constexpr currency_unit AUD { "AUD",  36, 2, "Australian dollar" };
      constexpr currency_unit AWG { "AWG", 533, 2, "Aruban florin" };
      constexpr currency_unit AZN { "AZN", 944, 2, "Azerbaijani manat" };
      constexpr currency_unit BAM { "BAM", 977, 2, "Bosnia and Herzegovina convertible mark" };
      constexpr currency_unit BBD { "BBD",  52, 2, "Barbados dollar" };
      constexpr currency_unit BDT { "BDT",  50, 2, "Bangladeshi taka" };
      constexpr currency_unit BGN { "BGN", 975, 2, "Bulgarian lev" };
      constexpr currency_unit BHD { "BHD",  48, 3, "Bahraini dinar" };
      constexpr currency_unit BIF { "BIF", 108, 0, "Burundian franc" };
      constexpr currency_unit BMD { "BMD",  60, 2, "Bermudian dollar" };
      constexpr currency_unit BND { "BND",  96, 2, "Brunei dollar" };
      constexpr currency_unit BOB { "BOB",  68, 2, "Boliviano" };
      constexpr currency_unit BOV { "BOV", 984, 2, "Bolivian Mvdol" };
      constexpr currency_unit BRL { "BRL", 986, 2, "Brazilian real" };
      constexpr currency_unit BSD { "BSD",  44, 2, "Bahamian dollar" };
      constexpr currency_unit BTN { "BTN",  64, 2, "Bhutanese ngultrum" };
      constexpr currency_unit BWP { "BWP",  72, 2, "Botswana pula" };
      constexpr currency_unit BYN { "BYN", 933, 2, "Belarusian ruble" };
      constexpr currency_unit BZD { "BZD",  84, 2, "Belize dollar" };
      constexpr currency_unit CAD { "CAD", 124, 2, "Canadian dollar" };
      constexpr currency_unit CDF { "CDF", 976, 2, "Congolese franc" };
      constexpr currency_unit CHE { "CHE", 947, 2, "WIR Euro" };
      constexpr currency_unit CHF { "CHF", 756, 2, "Swiss franc" };
      constexpr currency_unit CHW { "CHW", 948, 2, "WIR Franc" };
      constexpr currency_unit CLF { "CLF", 990, 4, "Unidad de Fomento" };
      constexpr currency_unit CLP { "CLP", 152, 0, "Chilean peso" };
      constexpr currency_unit CNY { "CNY", 156, 2, "Renminbi" };
      constexpr currency_unit COP { "COP", 170, 2, "Colombian peso" };
      constexpr currency_unit COU { "COU", 970, 2, "Unidad de Valor Real" };
      constexpr currency_unit CRC { "CRC", 188, 2, "Costa Rican colon" };
      constexpr currency_unit CUC { "CUC", 931, 2, "Cuban convertible peso" };
      constexpr currency_unit CUP { "CUP", 192, 2, "Cuban peso" };
      constexpr currency_unit CVE { "CVE", 132, 0, "Cape Verde escudo" };
      constexpr currency_unit CZK { "CZK", 203, 2, "Czech koruna" };
      constexpr currency_unit DJF { "DJF", 262, 0, "Djiboutian franc" };
      constexpr currency_unit DKK { "DKK", 208, 2, "Danish krone" };
      constexpr currency_unit DOP { "DOP", 214, 2, "Dominican peso" };
      constexpr currency_unit DZD { "DZD",  12, 2, "Algerian dinar" };
      constexpr currency_unit EGP { "EGP", 818, 2, "Egyptian pound" };
      constexpr currency_unit ERN { "ERN", 232, 2, "Eritrean nakfa" };
      constexpr currency_unit ETB { "ETB", 230, 2, "Ethiopian birr" };
      constexpr currency_unit EUR { "EUR", 978, 2, "Euro" };
      constexpr currency_unit FJD { "FJD", 242, 2, "Fiji dollar" };
      constexpr currency_unit FKP { "FKP", 238, 2, "Falkland Islands pound" };
      constexpr currency_unit GBP { "GBP", 826, 2, "Pound sterling" };
      constexpr currency_unit GEL { "GEL", 981, 2, "Georgian lari" };
      constexpr currency_unit GHS { "GHS", 936, 2, "Ghanaian cedi" };
      constexpr currency_unit GIP { "GIP", 292, 2, "Gibraltar pound" };
      constexpr currency_unit GMD { "GMD", 270, 2, "Gambian dalasi" };
      constexpr currency_unit GNF { "GNF", 324, 0, "Guinean franc" };
      constexpr currency_unit GTQ { "GTQ", 320, 2, "Guatemalan quetzal" };
      constexpr currency_unit GYD { "GYD", 328, 2, "Guyanese dollar" };
      constexpr currency_unit HKD { "HKD", 344, 2, "Hong Kong dollar" };
      constexpr currency_unit HNL { "HNL", 340, 2, "Honduran lempira" };
      constexpr currency_unit HRK { "HRK", 191, 2, "Croatian kuna" };
      constexpr currency_unit HTG { "HTG", 332, 2, "Haitian gourde" };
      constexpr currency_unit HUF { "HUF", 348, 2, "Hungarian forint" };
      constexpr currency_unit IDR { "IDR", 360, 2, "Indonesian rupiah" };
      constexpr currency_unit ILS { "ILS", 376, 2, "Israeli new shekel" };
      constexpr currency_unit INR { "INR", 356, 2, "Indian rupee" };
      constexpr currency_unit IQD { "IQD", 368, 2, "Iraqi dinar" };
      constexpr currency_unit IRR { "IRR", 364, 2, "Iranian rial" };
      constexpr currency_unit ISK { "ISK", 352, 2, "Icelandic krona" };
      constexpr currency_unit JMD { "JMD", 388, 2, "Jamaican dollar" };
      constexpr currency_unit JOD { "JOD", 400, 3, "Jordanian dinar" };
      constexpr currency_unit JPY { "JPY", 392, 0, "Japanese yen" };
      constexpr currency_unit KES { "KES", 404, 2, "Kenyan shilling" };
      constexpr currency_unit KGS { "KGS", 417, 2, "Kyrgyzstani som" };
      constexpr currency_unit KHR { "KHR", 116, 2, "Cambodian riel" };
      constexpr currency_unit KMF { "KMF", 174, 0, "Comoro franc" };
      constexpr currency_unit KPW { "KPW", 408, 2, "North Korean won" };
      constexpr currency_unit KRW { "KRW", 410, 0, "South Korean won" };
      constexpr currency_unit KWD { "KWD", 414, 3, "Kuwaiti dinar" };
      constexpr currency_unit KYD { "KYD", 136, 2, "Cayman Islands dollar" };
      constexpr currency_unit KZT { "KZT", 398, 2, "Kazakhstani tenge" };
      constexpr currency_unit LAK { "LAK", 418, 2, "Lao kip" };
      constexpr currency_unit LBP { "LBP", 422, 2, "Lebanese pound" };
      constexpr currency_unit LKR { "LKR", 144, 2, "Sri Lankan rupee" };
      constexpr currency_unit LRD { "LRD", 430, 2, "Liberian dollar" };
      constexpr currency_unit LSL { "LSL", 426, 2, "Lesotho loti" };
      constexpr currency_unit LYD { "LYD", 434, 3, "Libyan dinar" };
      constexpr currency_unit MAD { "MAD", 504, 2, "Moroccan dirham" };
      constexpr currency_unit MDL { "MDL", 498, 2, "Moldovan leu" };
      constexpr currency_unit MGA { "MGA", 969, 1, "Malagasy ariary" };
      constexpr currency_unit MKD { "MKD", 807, 2, "Macedonian denar" };
      constexpr currency_unit MMK { "MMK", 104, 2, "Myanmar kyat" };
      constexpr currency_unit MNT { "MNT", 496, 2, "Mongolian tšgršg" };
      constexpr currency_unit MOP { "MOP", 446, 2, "Macanese pataca" };
      constexpr currency_unit MRU { "MRU", 929, 1, "Mauritanian ouguiya" };
      constexpr currency_unit MUR { "MUR", 480, 2, "Mauritian rupee" };
      constexpr currency_unit MVR { "MVR", 462, 2, "Maldivian rufiyaa" };
      constexpr currency_unit MWK { "MWK", 454, 2, "Malawian kwacha" };
      constexpr currency_unit MXN { "MXN", 484, 2, "Mexican peso" };
      constexpr currency_unit MXV { "MXV", 979, 2, "Mexican Unidad de Inversion" };
      constexpr currency_unit MYR { "MYR", 458, 2, "Malaysian ringgit" };
      constexpr currency_unit MZN { "MZN", 943, 2, "Mozambican metical" };
      constexpr currency_unit NAD { "NAD", 516, 2, "Namibian dollar" };
      constexpr currency_unit NGN { "NGN", 566, 2, "Nigerian naira" };
      constexpr currency_unit NIO { "NIO", 558, 2, "Nicaraguan cordoba" };
      constexpr currency_unit NOK { "NOK", 578, 2, "Norwegian krone" };
      constexpr currency_unit NPR { "NPR", 524, 2, "Nepalese rupee" };
      constexpr currency_unit NZD { "NZD", 554, 2, "New Zealand dollar" };
      constexpr currency_unit OMR { "OMR", 512, 3, "Omani rial" };
      constexpr currency_unit PAB { "PAB", 590, 2, "Panamanian balboa" };
      constexpr currency_unit PEN { "PEN", 604, 2, "Peruvian sol" };
      constexpr currency_unit PGK { "PGK", 598, 2, "Papua New Guinean kina" };
      constexpr currency_unit PHP { "PHP", 608, 2, "Philippine peso" };
      constexpr currency_unit PKR { "PKR", 586, 2, "Pakistani rupee" };
      constexpr currency_unit PLN { "PLN", 985, 2, "Polish zloty" };
      constexpr currency_unit PYG { "PYG", 600, 0, "Paraguayan guarani" };
      constexpr currency_unit QAR { "QAR", 634, 2, "Qatari riyal" };
      constexpr currency_unit RON { "RON", 946, 2, "Romanian leu" };
      constexpr currency_unit RSD { "RSD", 941, 2, "Serbian dinar" };
      constexpr currency_unit RUB { "RUB", 643, 2, "Russian ruble" };
      constexpr currency_unit RWF { "RWF", 646, 0, "Rwandan franc" };
      constexpr currency_unit SAR { "SAR", 682, 2, "Saudi riyal" };
      constexpr currency_unit SBD { "SBD",  90, 2, "Solomon Islands dollar" };
      constexpr currency_unit SCR { "SCR", 690, 2, "Seychelles rupee" };
      constexpr currency_unit SDG { "SDG", 938, 2, "Sudanese pound" };
      constexpr currency_unit SEK { "SEK", 752, 2, "Swedish krona" };
      constexpr currency_unit SGD { "SGD", 702, 2, "Singapore dollar" };
      constexpr currency_unit SHP { "SHP", 654, 2, "Saint Helena pound" };
      constexpr currency_unit SLL { "SLL", 694, 2, "Sierra Leonean leone" };
      constexpr currency_unit SOS { "SOS", 706, 2, "Somali shilling" };
      constexpr currency_unit SRD { "SRD", 968, 2, "Surinamese dollar" };
      constexpr currency_unit SSP { "SSP", 728, 2, "South Sudanese pound" };
      constexpr currency_unit STN { "STN", 930, 2, "Sao Tome and Principe dobra" };
      constexpr currency_unit SVC { "SVC", 222, 2, "Salvadoran colon" };
      constexpr currency_unit SYP { "SYP", 760, 2, "Syrian pound" };
      constexpr currency_unit SZL { "SZL", 748, 2, "Swazi lilangeni" };
      constexpr currency_unit THB { "THB", 764, 2, "Thai baht" };
      constexpr currency_unit TJS { "TJS", 972, 2, "Tajikistani somoni" };
      constexpr currency_unit TMT { "TMT", 934, 2, "Turkmenistan manat" };
      constexpr currency_unit TND { "TND", 788, 3, "Tunisian dinar" };
      constexpr currency_unit TOP { "TOP", 776, 2, "Tongan pa'anga" };
      constexpr currency_unit TRY { "TRY", 949, 2, "Turkish lira" };
      constexpr currency_unit TTD { "TTD", 780, 2, "Trinidad and Tobago dollar" };
      constexpr currency_unit TWD { "TWD", 901, 2, "New Taiwan dollar" };
      constexpr currency_unit TZS { "TZS", 834, 2, "Tanzanian shilling" };
      constexpr currency_unit UAH { "UAH", 980, 2, "Ukrainian hryvnia" };
      constexpr currency_unit UGX { "UGX", 800, 2, "Ugandan shilling" };
      constexpr currency_unit USD { "USD", 840, 2, "United States dollar" };
      constexpr currency_unit USN { "USN", 997, 2, "United States dollar (next day) " };
      constexpr currency_unit UYI { "UYI", 940, 0, "Uruguay Peso en Unidades Indexadas " };
      constexpr currency_unit UYU { "UYU", 858, 2, "Uruguayan peso" };
      constexpr currency_unit UYW { "UYW", 927, 4, "Unidad previsional" };
      constexpr currency_unit UZS { "UZS", 860, 2, "Uzbekistan som" };
      constexpr currency_unit VES { "VES", 928, 2, "Venezuelan bolívar soberano" };
      constexpr currency_unit VND { "VND", 704, 0, "Vietnamese dong" };
      constexpr currency_unit VUV { "VUV", 548, 0, "Vanuatu vatu" };
      constexpr currency_unit WST { "WST", 882, 2, "Samoan tala" };
      constexpr currency_unit XAF { "XAF", 950, 0, "CFA franc BEAC" };
      constexpr currency_unit XAG { "XAG", 961,-1, "Silver" };
      constexpr currency_unit XAU { "XAU", 959,-1, "Gold" };
      constexpr currency_unit XBA { "XBA", 955,-1, "European Composite Unit (EURCO)" };
      constexpr currency_unit XBB { "XBB", 956,-1, "European Monetary Unit" };
      constexpr currency_unit XBC { "XBC", 957,-1, "European Unit of Account 9" };
      constexpr currency_unit XBD { "XBD", 958,-1, "European Unit of Account 17" };
      constexpr currency_unit XCD { "XCD", 951, 2, "East Caribbean dollar" };
      constexpr currency_unit XDR { "XDR", 960,-1, "Special drawing rights" };
      constexpr currency_unit XOF { "XOF", 952, 0, "CFA franc BCEAO" };
      constexpr currency_unit XPD { "XPD", 964,-1, "Palladium" };
      constexpr currency_unit XPF { "XPF", 953, 0, "CFP franc" };
      constexpr currency_unit XPT { "XPT", 962,-1, "Platinum" };
      constexpr currency_unit XSU { "XSU", 994,-1, "SUCRE" };
      constexpr currency_unit XTS { "XTS", 963,-1, "Reserved for testing" };
      constexpr currency_unit XUA { "XUA", 965,-1, "ADB Unit of Account" };
      constexpr currency_unit XXX { "XXX", 999,-1, "" };
      constexpr currency_unit YER { "YER", 886, 2, "Yemeni rial" };
      constexpr currency_unit ZAR { "ZAR", 710, 2, "South African rand" };
      constexpr currency_unit ZMW { "ZMW", 967, 2, "Zambian kwacha" };
      constexpr currency_unit ZWL { "ZWL", 932, 2, "Zimbabwean dollar" };

      // unofficial codes
      constexpr currency_unit CNH { "CNH", 0, 2, "Chinese yuan" };
      constexpr currency_unit CNT { "CNT", 0, 2, "Chinese yuan" };
      constexpr currency_unit GGP { "GGP", 0, 2, "Guernsey pound" };
      constexpr currency_unit IMP { "IMP", 0, 2, "Isle of Man pound" };
      constexpr currency_unit JEP { "JEP", 0, 2, "Jersey pound" };
      constexpr currency_unit KID { "KID", 0, 2, "Kiribati dollar" };
      constexpr currency_unit NIS { "NIS", 0, 2, "Israeli new shekel" };
      constexpr currency_unit NTD { "NTD", 0, 2, "New Taiwan dollar" };
      constexpr currency_unit PRB { "PRB", 0, 2, "Transnistrian ruble" };
      constexpr currency_unit SLS { "SLS", 0, 2, "Somaliland shilling" };
      constexpr currency_unit RMB { "RMB", 0, 2, "Renminbi (Chinese) yuan" };
      constexpr currency_unit TVD { "TVD", 0, 2, "Tuvalu dollar" };

      // crypto-currencies
      constexpr currency_unit DASH { "DASH", 0,  8, "Dash" };
      constexpr currency_unit ETH  { "ETH",  0, 18, "Ether" };
      constexpr currency_unit VTC  { "VTC",  0,  8, "Vertcoin" };
      constexpr currency_unit XBC_ { "XBC_", 0,  8, "Bitcoin Cash" };
      constexpr currency_unit XBT  { "XBT",  0,  8, "Bitcoin" };
      constexpr currency_unit XLM  { "XLM",  0,  8, "Stellar Lumen" };
      constexpr currency_unit XMR  { "XMR",  0, 12, "Monero" };
      constexpr currency_unit XRP  { "XRP",  0,  6, "Ripple" };
      constexpr currency_unit ZEC  { "ZEC",  0,  8, "Zcash" };

      static const std::initializer_list<currency_unit> currencies
      {
         // official
         AED, AFN, ALL, AMD, ANG, AOA, ARS, AUD, AWG, AZN,
         BAM, BBD, BDT, BGN, BHD, BIF, BMD, BND, BOB, BOV, BRL, BSD, BTN, BWP, BYN, BZD,
         CAD, CDF, CHE, CHF, CHW, CLF, CLP, CNY, COP, COU, CRC, CUC, CUP, CVE, CZK,
         DJF, DKK, DOP, DZD,
         EGP, ERN, ETB, EUR,
         FJD, FKP,
         GBP, GEL, GHS, GIP, GMD, GNF, GTQ, GYD,
         HKD, HNL, HRK, HTG, HUF,
         IDR, ILS, INR, IQD, IRR, ISK,
         JMD, JOD, JPY,
         KES, KGS, KHR, KMF, KPW, KRW, KWD, KYD,
         LAK, LBP, LKR, LRD, LSL, LYD,
         MAD, MDL, MGA, MKD, MMK, MNT, MOP, MRU, MUR, MVR, MWK, MXN, MXV, MYR, MZN,
         NAD, NGN, NIO, NOK, NPR, NZD,
         OMR,
         PAB, PEN, PGK, PHP, PKR, PLN, PYG,
         QAR,
         RON, RSD, RUB, RWF,
         SAR, SBD, SCR, SDG, SEK, SGD, SHP, SLL, SOS, SRD, SSP, STN, SVC, SYP, SZL,
         THB, TJS, TMT, TND, TOP, TRY, TTD, TWD, TZS,
         UAH, UGX, USD, USN, UYI, UYU, UYW, UZS, 
         VES, VND, VUV,
         WST,
         XAF, XAG, XAU, XBA, XBB, XBC, XBD, XCD, XDR, XOF, XPD, XPF, XPT, XSU, XTS, XUA, XXX,
         YER,
         ZAR, ZMW, ZWL,

         // unofficial
         CNH, CNT, GGP, IMP, JEP, KID, NIS, NTD, PRB, SLS, RMB, TVD, 

         // crypto-currencies
         DASH, ETH, VTC, XBC_, XBT, XLM, XMR, XRP, ZEC
      };
   }

   template <typename Iter>
   inline Iter find_currency(Iter first, Iter last, std::string_view code)
   {
      for (auto it = first; it != last; ++it)
      {
         if (it->code == code)
            return it;
      }

      return last;
   }

   inline std::optional<currency_unit> find_currency(std::string_view code)
   {
      auto it = find_currency(
         std::cbegin(currency::currencies),
         std::cend(currency::currencies),
         code);

      if (it != std::cend(currency::currencies))
         return std::optional<currency_unit>{ *it };

      return {};
   }

   template <typename Iter>
   inline Iter find_currency(Iter first, Iter last, int const number)
   {
      for (auto it = first; it != last; ++it)
      {
         if (it->number == number)
            return it;
      }

      return last;
   }

   inline std::optional<currency_unit> find_currency(int const number)
   {
      auto it = find_currency(
         std::cbegin(currency::currencies),
         std::cend(currency::currencies),
         number);

      if (it != std::cend(currency::currencies))
         return std::optional<currency_unit>{ *it };

      return {};
   }

   struct bad_currency_error : public std::runtime_error
   {
      explicit bad_currency_error(std::string const & message)
         : std::runtime_error(message)
      {
      }

      explicit bad_currency_error(const char * message)
         : std::runtime_error(message)
      {
      }
   };

   struct currency_mismatch_error : bad_currency_error
   {
      currency_mismatch_error()
         : bad_currency_error("Currencies do not match") 
      {}
   };
}
