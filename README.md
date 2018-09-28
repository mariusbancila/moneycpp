# moneycpp
A C++ 17 header-only, cross-platform library for handling monetary values, currencies, rounding and other related features.

**THIS PROJECT IS UNDER CONSTRUCTION!**

## Core requirements
The library is intended for being used in a variety of types of application including ERP systems, banking, finance, insurrance, games, and others.

The following is a list of its core requirements:
* Provide an API for handing and calculating with monetary amounts.
* Support different numeric capabilities.
* Provide a default set of rounding algorithms and policies and support additional user-defined ones.
* Support the entire ISO 4217 list of currencies.
* Support the entire ISO 3166-1 list of countries.
* It should be possible for users to add new (virtual) currencies and countries.
* Format and parse monetary values.

## Library API
The following are examples for using the library:

```cpp
// create and operate with money values
auto m = make_money(20.0, currency::USD);
m += make_money(10.5, currency::USD);
m *= 2.5;

// round money values
m = rounding_policy_standard(round_ceiling())(m);

// convert between currencies 
auto ex = exchange_money(
   m, 
   currency::EUR, 0.86,
   rounding_policy_standard(round_ceiling()));  
```

Floating point types are not appropriate for monetary values because they cannot exactly represent real numbers. Over time, or large number of transactions, the small differences can add up to important values. Because of this, the library supports 3rd party libraries that provide better representations, such as boost::multiprecision.
```cpp
using decimal = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<50>>;

inline decimal operator""_dec(char const * str, std::size_t)
{ return decimal(str); }

auto m = make_money("20.99"_dec, currency::USD);

auto ex = exchange_money(
   m, 
   currency::EUR, "0.8649"_dec,
   rounding_policy_to_currency_digits(round_half_even()));
```