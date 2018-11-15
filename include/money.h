#pragma once
#include "currency.h"
#include "rounding.h"
#include <functional>

namespace moneycpp
{

   template <typename TValue>
   struct money 
   {
      const TValue         amount;
      const currency_unit  currency;
   };

   template <typename TValue>
   inline bool operator==(money<TValue> const & lhs, money<TValue> const & rhs)
   {
      if (lhs.currency != rhs.currency) throw currency_mismatch_error();
      return lhs.amount == rhs.amount;
   }

   template <typename TValue>
   inline bool operator!=(money<TValue> const & lhs, money<TValue> const & rhs)
   {
      return !(lhs == rhs);
   }

   template <typename TValue>
   inline bool operator<(money<TValue> const & lhs, money<TValue> const & rhs)
   {
      if (lhs.currency != rhs.currency) throw currency_mismatch_error();
      return lhs.amount < rhs.amount;
   }

   template <typename TValue>
   inline bool operator>(money<TValue> const & lhs, money<TValue> const & rhs)
   {
      return rhs < lhs;
   }

   template <typename TValue>
   inline bool operator<=(money<TValue> const & lhs, money<TValue> const & rhs)
   {
      return !(rhs < lhs);
   }

   template <typename TValue>
   inline bool operator>=(money<TValue> const & lhs, money<TValue> const & rhs)
   {
      return !(lhs < rhs);
   }

   template <typename TValue1, typename TValue2>
   inline auto operator+(money<TValue1> const & lhs, money<TValue2> const & rhs)
   {
      if (lhs.currency != rhs.currency) throw currency_mismatch_error();
      return money<decltype(lhs.amount + rhs.amount)> {lhs.amount + rhs.amount, lhs.currency};
   }

   template <typename TValue1, typename TValue2>
   inline auto operator-(money<TValue1> const & lhs, money<TValue2> const & rhs)
   {
      if (lhs.currency != rhs.currency) throw currency_mismatch_error();
      return money<decltype(lhs.amount - rhs.amount)> {lhs.amount - rhs.amount, lhs.currency};
   }

   template <typename TValue1, typename TValue2>
   inline auto operator*(money<TValue1> const & lhs, TValue2 const rhs)
   {
      return money<decltype(lhs.amount * rhs)> {lhs.amount * rhs, lhs.currency};
   }

   template <typename TValue1, typename TValue2>
   inline auto operator/(money<TValue1> const & lhs, TValue2 const rhs)
   {
      if (rhs == 0) throw std::runtime_error("cannot divide by 0");
      return money<decltype(lhs.amount / rhs)> {lhs.amount / rhs, lhs.currency};
   }

   template <typename TValue>
   constexpr money<TValue> make_money(TValue const value, currency_unit const currency) noexcept
   {
      return money<TValue> { value, currency };
   }
   
   template <typename RoundFunc = round_none>
   struct rounding_policy_none
   {
      rounding_policy_none(RoundFunc = RoundFunc())
      {
      }

      template <typename TValue>
      money<TValue> operator()(money<TValue> const value)
      {
         return value;
      }
   };

   template <typename RoundFunc>
   struct rounding_policy_standard
   {
      rounding_policy_standard(RoundFunc rounding):rfun(rounding)
      {}

      template <typename TValue>
      money<TValue> operator()(money<TValue> const value)
      {
         auto c = TValue(10000.0);
         auto amount = static_cast<TValue>(value.amount * c);
         auto r = std::invoke(std::forward<RoundFunc>(rfun), amount);
         return make_money<TValue>(r / c, value.currency);
      }

   private:
      RoundFunc rfun;
   };

   template <typename RoundFunc>
   struct rounding_policy_to_currency_digits
   {
      rounding_policy_to_currency_digits(RoundFunc rounding) :rfun(rounding)
      {}

      template <typename TValue>
      money<TValue> operator()(money<TValue> const value)
      {
         auto c = std::pow(10, value.currency.minor_unit);
         auto amount = static_cast<TValue>(value.amount * c);
         auto r = std::invoke(std::forward<RoundFunc>(rfun), amount);
         return make_money<TValue>(r / c, value.currency);
      }

   private:
      RoundFunc rfun;
   };

   template <typename TValue, typename RoundPolicy>
   money<TValue> exchange_money(
      money<TValue> const & m, 
      currency_unit const currency, 
      TValue const rate,
      RoundPolicy roundingPolicy)
   {
      if(rate <= 0)
         throw std::runtime_error("Exchange rate must be positive");
      
      if(m.currency == currency)
         return m;

      auto exchange = make_money<TValue>(static_cast<TValue>(m.amount * rate), currency);

      auto result =
         std::invoke(
            std::forward<RoundPolicy>(roundingPolicy),
            exchange);

      return result;
   }

   template <typename TValue>
   inline money<TValue> const & min(money<TValue> const & a, money<TValue> const & b)
   {
      return (a < b) ? a : b;
   }

   template <typename TValue>
   inline money<TValue> const & max(money<TValue> const & a, money<TValue> const & b)
   {
      return (a > b) ? a : b;
   }
}
