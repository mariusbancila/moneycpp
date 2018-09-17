#pragma once

#include <vector>
#include <string_view>

namespace moneycpp
{
   struct currency_unit
   {
      const std::string_view  code;
      const int               number;
      const int               minor_unit;
      const std::string_view  name;
   };

   constexpr bool operator==(currency_unit const & lhs, currency_unit const & rhs) noexcept
   {
      return 
         lhs.number == rhs.number &&
         lhs.code == rhs.code &&
         lhs.minor_unit == rhs.minor_unit &&
         lhs.name == rhs.name;
   }

   constexpr bool operator!=(currency_unit const & lhs, currency_unit const & rhs) noexcept
   {
      return !(lhs == rhs);
   }

   namespace currency
   {
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

      //constexpr currency_unit{ "", , 2, "" };

      constexpr currency_unit USD { "USD", 840, 2, "United States dollar" };
      constexpr currency_unit EUR { "EUR", 978, 2, "Euro" };
      constexpr currency_unit GBP { "GBP", 826, 2, "Pound sterling" };

      static const std::initializer_list<currency_unit> currencies
      {
         AED, AFN, ALL, AMD, ANG, AOA, ARS, AUD, AWG, AZN,
         BAM, BBD, BDT, BGN, BHD, BIF, BMD, BND, BOB, BOV, BRL, BSD, BTN, BWP, BYN, BZD,
         CAD, CDF, CHE, CHF, CHW, CLF, CLP, CNY, COP, COU, CRC, CUC, CUP, CVE, CZK,
         USD,
         EUR,
         GBP
      };
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