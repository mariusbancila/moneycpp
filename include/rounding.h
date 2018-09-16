#pragma once

#include <cmath>

namespace moneycpp
{
   template <typename TValue>
   TValue round_up(TValue const);
   
   template <typename TValue>
   TValue round_down(TValue const);
   
   template <typename TValue>
   TValue round_ceiling(TValue const);
   
   template <typename TValue>
   TValue round_floor(TValue const);
   
   template <typename TValue>
   TValue round_half_up(TValue const);
   
   template <typename TValue>
   TValue round_half_down(TValue const);
   
   template <typename TValue>
   TValue round_half_even(TValue const);
   
   template <>
   double round_ceiling(double const value)
   {
      return std::ceil(value);
   }
   
   template <>
   double round_floor(double const value)
   {
      return std::floor(value);
   }
}
