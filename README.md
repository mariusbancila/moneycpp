# moneycpp
A C++ 17 header-only, cross-platform library for handling monetary values, currencies, rounding and other related features.

## Core requirements
The library is intended for being used in a variety of types of application including ERP systems, banking, finance, insurrance, games, and others.

The following is a list of its core requirements:
* Provide an API for handing and calculating with monetary amounts.
* Support different numeric capabilities.
* Provide a default set of rounding algorithms and policies and support additional user-defined ones.
* Support the entire ISO 4217 list of currencies.
* Support the entire ISO 3166-1 list of countries.
* It should be possible for users to add new (virtual) currencies and countries.

## Overview
The library is built around several core components:
* `money` that holds a monetary value
* `currency_unit` that contains currency information for a monetary value as per ISO 4217
* `country_unit` that contains country information in relation to currencies, as per ISO 3166-1
* rounding algorithms - that specify how values are rounded, and policies - that specify how monetary values are rounded using a rounding algorithm

## Library API
### Monetary values

A monetary value has two dimensions: the actual amount and the currency that it represents. A monetary value is represented by the `money` class.
The following are examples for working with monetary values:

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

The examples above use the type `double` for numerical values. This is a floating point type and can only represent exact decimal values for numbers that are a sum of inverse powers of two. That means floating point types can exactly represent values such as 0.5, 1.25, or 42.90625 but cannot do the same for values such as 0.10 or 19.99. Therefore, floating point types are not appropriate for monetary values because they cannot exactly represent most real numbers. This can be an important aspect in financial applications or, in general, in applications that deal with monetary transactions because over time, or over a large number of transactions, the small differences can add up to important values. Because of this, the library supports 3rd party libraries that provide better representations of real numbers, such as `boost::multiprecision`. All the rouding algorithms are specialized for the `boost::multiprecision::cpp_dec_float`, aliased as `decimal`, as shown below.

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

### Countries and Currencies
The library provides a full database of ISO recognized countries and currencies and functions to look them up. Information about a country is represented by the `country_unit` class and information about a currency by the `currency_unit` class. Below are several examples for searching these lists:

```cpp
// finding a currency
auto cu1 = find_currency("EUR");
auto cu2 = find_currency(978);
assert(cu1 == cu2);
assert(cu1 == currency::EUR);
assert(cu1.value().code == "EUR");
```

```cpp
// finding a country
auto cu1 = find_country("US");
auto cu2 = find_country(840);
assert(cu1 == cu2);
assert(cu1 == country::US);
assert(cu1.value().alpha2 == "US")
```

```cpp
// finding the (main) currency of a country
auto cu1 = country::find_country_currency(country::AF);
assert(cu1 == currency::AFN);

auto cu2 = country::find_country_currency(country::BO);
assert(cu2 == currency::BOB);
```

```cpp
// finding all the currencies from a country as a set
auto s = country::find_country_currencies(country::BO);
assert(s.size() == 2);
assert(*s.begin() == currency::BOB);
assert(*std::next(s.begin()) == currency::BOV);
```

```cpp
// finding all the currencies from a country as a range
auto r = country::country_currency_equal_range(
         country::currencies,
         country::US);
assert(std::distance(r.first, r.second) == 2);
assert(r.first->second == currency::USD);
assert(std::next(r.first)->second == currency::USN);
```

The built-in databases for countries, currencies, and country currencies can be extended with additional units. In this case, you can use overloaded versions of these functions that use iterators to define the range to search. The following example shows how to do so with the currencies database, but the same apply for countries (`find_country` ovarload) and country currencies (`find_country_currencies` and `country_currency_equal_range` overloads):
```cpp
std::vector<currency_unit> my_currencies{ currency::currencies };
my_currencies.emplace_back(currency_unit{ "VIR", 1001, 2, "Virtual Currency" });

auto cu1 = find_currency(std::cbegin(my_currencies), std::cend(my_currencies), "VIR");
auto cu2 = find_currency(std::cbegin(my_currencies), std::cend(my_currencies), 1001);

assert(cu1 != std::cend(my_currencies));
assert(cu1 == cu2);
assert(cu1->alpha2 == "VIR");
```

## Rounding
Several rounding algorithms are provided with the library. These algorithms transform a numerical value from a greater precision (e.g. 19.99128) to a lesser precision (e.g. 19.99). In addition to these, any user-defined rounding algorithm can be used with the library. The rounding algorithms, implemented as functors, are as follows:

| Name | Description | Functor |
| --- | --- | --- |
| None | no rounding | `round_none` |
| Up | rounds away from zero | `round_up` |
| Down | rounds towards zero | `round_down` |
| Ceiling | rounds towards positive infinity | `round_ceiling` |
| Floor | rounds towards negative infinity | `round_floor` |
| Half up | rounds towards "nearest neighbour" unless both neighbours are equidistant, in which case round up | `round_half_up` |
| Half down | rounds towards "nearest neighbour" unless both neighbours are equidistant, in which case round down | `round_half_down` |
| Half even | rounds towards the "nearest neighbour" unless both neighbours are equidistant, in which case, round towards the even neighbour | `round_half_even` |
| Half odd | rounds towards the "nearest neighbour" unless both neighbours are equidistant, in which case, round towards the odd neighbour | `round_half_odd` |

The following is a table with numerical examples for each rounding algorithm:

| Algorithm / Value | -5.5 | -2.5 | -1.6 | -1.1 | -1.0 | 1.0 | 1.1 | 1.6 | 2.5 | 5.5 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| Up | -6.0 | -3.0 | -2.0 | -2.0 | -1.0 | 1.0 | 2.0 | 2.0 | 3.0 | 6.0 |
| Down | -5.0 | -2.0 | -1.0 | -1.0 | -1.0 | 1.0 | 1.0 | 1.0 | 2.0 | 5.0 |
| Ceiling | -5.0 | -2.0 | -1.0 | -1.0 | -1.0 | 1.0 | 2.0 |  2.0 | 3.0 | 6.0 |
| Floor | -6.0 | -3.0 | -2.0 | -2.0 | -1.0 | 1.0 | 1.0 | 1.0 | 2.0 | 5.0 |
| Half up | -6.0 | -3.0 | -2.0 | -1.0 | -1.0 | 1.0 | 1.0 | 2.0 | 3.0 | 6.0 |
| Half down | -5.0 | -2.0 | -2.0 | -1.0 | -1.0 | 1.0 | 1.0 | 2.0 | 2.0 | 5.0 |
| Half even | -6.0 | -2.0 | -2.0 | -1.0 | -1.0 | 1.0 | 1.0 | 2.0 | 2.0 | 6.0 |
| Half odd | -5.0 | -3.0 | -2.0 | -1.0 | -1.0 | 1.0 | 1.0 | 2.0 | 3.0 | 5.0 |

More about these rounding algorithms can be found in the article [Rounding Algorithms 101 Redux](https://www.eetimes.com/document.asp?doc_id=1274515).

Apart from the rounding algorithms, the library provides several rounding policies that define how a `money` value should be rounded. The available policies are:

| Type name | Description |
| --- | --- |
| `rounding_policy_none`| No rounding is performed |
| `rounding_policy_standard` | Rounding to 4 decimal digits |
| `rounding_policy_to_currency_digits` | Rounding to the number of digits (i.e. minor unit) as defined for the currency |

Any additional user-defined policy can be used instead of the ones supplied with the library.

## Using the library
The library is composed of several headers and uses C++ 17 features (such as <tt>string_view</tt>, <tt>optional</tt>, structured bindings). You need a compiler that supports these features.

The library works with:
* the build-in floating point types, `float`, `double`, and `long double`
* `boost::multiprecision` library, with particular specializations for `boost::multiprecision::cpp_dec_float<50>`, aliased as `decimal`
* any 3rd library provided that you specialize the rounding function object templates

In order to use `boost::multiprecision` you must:
* define the macro `USE_BOOST_MULTIPRECISION`
* make the path to the `boost` library available in the include search path

The library is accompanied by unit tests (build with Catch2). CMake is used for creating projects to build and run the unit tests. You can do the following to build it with support for `boost::multiprecision`:
* clone or download and unzip the `moneycpp` library
* create a `build` folder
* download and unzip [Boost](https://www.boost.org/)
* run CMake from the `build` folder
* open the project in the IDE (such as Visual Studio or Xcode), build the project, and run it

Here is an example for creating a project for VS2017 with `boost` available at `C:\libraries\boost_1_68_0\` (make sure to include the trailing `\`).
```
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017" -DBOOST_MULTIPRECISION=ON -DBOOST_INCLUDE_DIR=C:\libraries\boost_1_68_0\
```

## Related projects
The following libraries are used:
* [Catch2](https://github.com/catchorg/Catch2/) - unit testing framework
* [Boost](https://www.boost.org/) - optional (but recommended) library
