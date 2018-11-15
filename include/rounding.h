#pragma once

#include <cmath>

namespace moneycpp
{
   // Rounding Algorithms 101 Redux
   // https://www.eetimes.com/document.asp?doc_id=1274515
   // Clive Maxfield - 2006

   // round away from zero
   // input:  -5.5, -2.5, -1.6, -1.1, -1.0, 1.0, 1.1, 1.6, 2.5, 5.5
   // result: -6.0, -3.0, -2.0, -2.0, -1.0, 1.0, 2.0, 2.0, 3.0, 6.0
   struct round_up
   {
      template <typename T>
      inline T operator()(T const) const;
   };

   // round towards zero
   // input:  -5.5, -2.5, -1.6, -1.1, -1.0, 1.0, 1.1, 1.6, 2.5, 5.5
   // result: -5.0, -2.0, -1.0, -1.0, -1.0, 1.0, 1.0, 1.0, 2.0, 5.0
   struct round_down
   {
      template <typename T>
      inline T operator()(T const) const;
   };

   // round towards positive infinity
   // input:  -5.5, -2.5, -1.6, -1.1, -1.0, 1.0, 1.1, 1.6, 2.5, 5.5
   // result: -5.0, -2.0, -1.0, -1.0, -1.0, 1.0, 2.0, 2.0, 3.0, 6.0
   struct round_ceiling
   {
      template <typename T>
      inline T operator()(T const) const;
   };

   // round towards negative infinity
   // input:  -5.5, -2.5, -1.6, -1.1, -1.0, 1.0, 1.1, 1.6, 2.5, 5.5
   // result: -6.0, -3.0, -2.0, -2.0, -1.0, 1.0, 1.0, 1.0, 2.0, 5.0
   struct round_floor
   {
      template <typename T>
      inline T operator()(T const) const;
   };

   // round towards "nearest neighbor" unless both neighbors are equidistant, in which case round up
   // input:  -5.5, -2.5, -1.6, -1.1, -1.0, 1.0, 1.1, 1.6, 2.5, 5.5
   // result: -6.0, -3.0, -2.0, -1.0, -1.0, 1.0, 1.0, 2.0, 3.0, 6.0
   struct round_half_up
   {
      template <typename T>
      inline T operator()(T const) const;
   };

   // round towards "nearest neighbor" unless both neighbors are equidistant, in which case round down
   // input:  -5.5, -2.5, -1.6, -1.1, -1.0, 1.0, 1.1, 1.6, 2.5, 5.5
   // result: -5.0, -2.0, -2.0, -1.0, -1.0, 1.0, 1.0, 2.0, 2.0, 5.0
   struct round_half_down
   {
      template <typename T>
      inline T operator()(T const) const;
   };

   // round towards the "nearest neighbor" unless both neighbors are equidistant, in which case, round towards the even neighbor
   // input:  -5.5, -2.5, -1.6, -1.1, -1.0, 1.0, 1.1, 1.6, 2.5, 5.5
   // result: -6.0, -2.0, -2.0, -1.0, -1.0, 1.0, 1.0, 2.0, 2.0, 6.0
   struct round_half_even
   {      
      template <typename T>
      inline T operator()(T const) const;
   };

   // round towards the "nearest neighbor" unless both neighbors are equidistant, in which case, round towards the odd neighbor
   // input:  -5.5, -2.5, -1.6, -1.1, -1.0, 1.0, 1.1, 1.6, 2.5, 5.5
   // result: -5.0, -3.0, -2.0, -1.0, -1.0, 1.0, 1.0, 2.0, 3.0, 5.0
   struct round_half_odd
   {
      template <typename T>
      inline T operator()(T const) const;
   };

   // round nothing
   struct round_none
   {
      template <typename T>
      constexpr inline T operator()(T const value) const { return value; }
   };

   // specialization

   template <>
   inline float round_up::operator()(float const value) const
   {
      return value > 0.0f ? std::ceil(value) : std::floor(value);
   }

   template <>
   inline double round_up::operator()(double const value) const
   {
      return value > 0.0 ? std::ceil(value) : std::floor(value);
   }

   template <>
   inline long double round_up::operator()(long double const value) const
   {
      return value > 0.0l ? std::ceil(value) : std::floor(value);
   }

   template <>
   inline float round_down::operator()(float const value) const
   {
      return value > 0.0f ? std::floor(value) : std::ceil(value);
   }

   template <>
   inline double round_down::operator()(double const value) const
   {
      return value > 0.0 ? std::floor(value) : std::ceil(value);
   }

   template <>
   inline long double round_down::operator()(long double const value) const
   {
      return value > 0.0l ? std::floor(value) : std::ceil(value);
   }

   template <>
   inline float round_ceiling::operator()(float const value) const
   {
      return std::ceil(value);
   }

   template <>
   inline double round_ceiling::operator()(double const value) const
   {
      return std::ceil(value);
   }

   template <>
   inline long double round_ceiling::operator()(long double const value) const
   {
      return std::ceil(value);
   }

   template <>
   inline float round_floor::operator()(float const value) const
   {
      return std::floor(value);
   }

   template <>
   inline double round_floor::operator()(double const value) const
   {
      return std::floor(value);
   }

   template <>
   inline long double round_floor::operator()(long double const value) const
   {
      return std::floor(value);
   }

   template <>
   inline float round_half_up::operator()(float const value) const
   {
      return value > 0.0f ? std::floor(value + 0.5f) : std::ceil(value - 0.5f);
   }

   template <>
   inline double round_half_up::operator()(double const value) const
   {
      return value > 0.0 ? std::floor(value + 0.5) : std::ceil(value - 0.5);
   }

   template <>
   inline long double round_half_up::operator()(long double const value) const
   {
      return value > 0.0l ? std::floor(value + 0.5l) : std::ceil(value - 0.5l);
   }

   template <>
   inline float round_half_down::operator()(float const value) const
   {
      return value > 0.0f ? std::ceil(value - 0.5f) : std::floor(value + 0.5f);
   }

   template <>
   inline double round_half_down::operator()(double const value) const
   {
      return value > 0.0 ? std::ceil(value - 0.5) : std::floor(value + 0.5);
   }

   template <>
   inline long double round_half_down::operator()(long double const value) const
   {
      return value > 0.0l ? std::ceil(value - 0.5l) : std::floor(value + 0.5l);
   }

   template <>
   inline float round_half_even::operator()(float const value) const
   {      
      return value - std::remainder(value, 1.0f);
   }

   template <>
   inline double round_half_even::operator()(double const value) const
   {
      return value - std::remainder(value, 1.0);
   }

   template <>
   inline long double round_half_even::operator()(long double const value) const
   {
      return value - std::remainder(value, 1.0l);
   }

   template <>
   inline float round_half_odd::operator()(float const value) const
   {
      auto r = std::remainder(value, 1.0f);
      return std::abs(r) == 0.5f ? value + r : std::floor(value + 0.5f);
   }

   template <>
   inline double round_half_odd::operator()(double const value) const
   {
      auto r = std::remainder(value, 1.0);
      return std::abs(r) == 0.5 ? value + r : std::floor(value + 0.5);
   }

   template <>
   inline long double round_half_odd::operator()(long double const value) const
   {
      auto r = std::remainder(value, 1.0l);
      return std::abs(r) == 0.5l ? value + r : std::floor(value + 0.5l);
   }
}
