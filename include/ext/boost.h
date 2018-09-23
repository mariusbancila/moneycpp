#pragma once

#ifdef USE_BOOST_MULTIPRECISION

#include "rounding.h"
#include "boost\multiprecision\cpp_dec_float.hpp"

namespace moneycpp
{
   using decimal = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<50>>;

   inline decimal operator""_dec(char const * str, std::size_t)
   {
      return decimal(str);
   }

   template <>
   inline decimal round_up::operator()(decimal const value) const
   {
      if (value > decimal(0u))
         return boost::multiprecision::ceil(value);
      else
         return boost::multiprecision::floor(value);
   }

   template <>
   inline decimal round_down::operator()(decimal const value) const
   {
      if (value > decimal(0u))
         return boost::multiprecision::floor(value);
      else
         return boost::multiprecision::ceil(value);
   }

   template <>
   inline decimal round_ceiling::operator()(decimal const value) const
   {
      return boost::multiprecision::ceil(value);
   }

   template <>
   inline decimal round_floor::operator()(decimal const value) const
   {
      return boost::multiprecision::floor(value);
   }

   template <>
   inline decimal round_half_up::operator()(decimal const value) const
   {
      if (value > decimal(0u))
      {
         return boost::multiprecision::floor(value + "0.5"_dec);
      }
      else
      {
         return boost::multiprecision::ceil(value - "0.5"_dec);
      }
   }

   template <>
   inline decimal round_half_down::operator()(decimal const value) const
   {
      if (value > decimal(0u))
      {
         return boost::multiprecision::ceil(value - "0.5"_dec);
      }
      else
      {
         return boost::multiprecision::floor(value + "0.5"_dec);
      }
   }

   template <>
   inline decimal round_half_even::operator()(decimal const value) const
   {
      return value - boost::multiprecision::remainder(value, 1.0);
   }

   template <>
   inline decimal round_half_odd::operator()(decimal const value) const
   {
      auto r = boost::multiprecision::remainder(value, 1.0);
      if (boost::multiprecision::abs(r) == "0.5"_dec)
         return value + r;
      else
         return boost::multiprecision::floor(value + "0.5"_dec);
   }
}

#endif