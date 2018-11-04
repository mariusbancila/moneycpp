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
      static const country_currency_map currencies
      {
         {AF, AFN},
         //{AX, },
         {AL, ALL},
         {DZ, DZD},
         {AS, USD},
         {AD, EUR},
         {AO, AOA},
      };
      
      inline std::set<currency_unit> find_country_currency(
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
      
      template <typename ForwardIter>
      inline std::pair<ForwardIter, ForwardIter> find_country_currency(
         ForwardIter first, ForwardIter last, 
         country_unit const & cu)
      {
         return std::equal_range(first, last, cu);
      }
      
   }
}