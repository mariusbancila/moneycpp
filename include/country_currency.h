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