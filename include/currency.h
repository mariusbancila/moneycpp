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
      constexpr currency_unit USD { "USD", 840, 2, "United States dollar" };
      constexpr currency_unit EUR { "EUR", 978, 2, "Euro" };
      constexpr currency_unit GBP { "GBP", 826, 2, "Pound sterling" };

      static const std::initializer_list<currency_unit> currencies
      {
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