#include "rounding.h"
#include "catch.hpp"
#include <vector>

using namespace moneycpp;

template <typename T>
static std::vector<T> inputs
{ T(5.5), T(2.5), T(1.6), T(1.1), T(1.0), T(-1.0), T(-1.1), T(-1.6), T(-2.5), T(-5.5) };

template <typename T>
static std::vector<T> exp_round_up
{ T(6.0), T(3.0), T(2.0), T(2.0), T(1.0), T(-1.0), T(-2.0), T(-2.0), T(-3.0), T(-6.0) };

template <typename T>
static std::vector<T> exp_round_down 
{ T(5.0), T(2.0), T(1.0), T(1.0), T(1.0), T(-1.0), T(-1.0), T(-1.0), T(-2.0), T(-5.0) };

template <typename T>
static std::vector<T> exp_round_ceil 
{ T(6.0), T(3.0), T(2.0), T(2.0), T(1.0), T(-1.0), T(-1.0), T(-1.0), T(-2.0), T(-5.0) };

template <typename T>
static std::vector<T> exp_round_floor 
{ T(5.0), T(2.0), T(1.0), T(1.0), T(1.0), T(-1.0), T(-2.0), T(-2.0), T(-3.0), T(-6.0) };

template <typename T>
static std::vector<T> exp_round_half_up
{ T(6.0), T(3.0), T(2.0), T(1.0), T(1.0), T(-1.0), T(-1.0), T(-2.0), T(-3.0), T(-6.0) };

template <typename T>
static std::vector<T> exp_round_half_down
{ T(5.0), T(2.0), T(2.0), T(1.0), T(1.0), T(-1.0), T(-1.0), T(-2.0), T(-2.0), T(-5.0) };

template <typename T>
static std::vector<T> exp_round_half_even
{ T(6.0), T(2.0), T(2.0), T(1.0), T(1.0), T(-1.0), T(-1.0), T(-2.0), T(-2.0), T(-6.0) };

template <typename T>
static std::vector<T> exp_round_half_odd
{ T(5.0), T(3.0), T(2.0), T(1.0), T(1.0), T(-1.0), T(-1.0), T(-2.0), T(-3.0), T(-5.0) };

TEST_CASE("Test round up", "[rounding]")
{  
   for (size_t i = 0; i < inputs<float>.size(); ++i)
   {
      auto r = round_up()(inputs<float>[i]);
      REQUIRE(r == exp_round_up<float>[i]);
   }

   for (size_t i = 0; i < inputs<double>.size(); ++i)
   {
      auto r = round_up()(inputs<double>[i]);
      REQUIRE(r == exp_round_up<double>[i]);
   }

   for (size_t i = 0; i < inputs<long double>.size(); ++i)
   {
      auto r = round_up()(inputs<long double>[i]);
      REQUIRE(r == exp_round_up<long double>[i]);
   }
}

TEST_CASE("Test round down", "[rounding]")
{
   for (size_t i = 0; i < inputs<float>.size(); ++i)
   {
      auto r = round_down()(inputs<float>[i]);
      REQUIRE(r == exp_round_down<float>[i]);
   }

   for (size_t i = 0; i < inputs<double>.size(); ++i)
   {
      auto r = round_down()(inputs<double>[i]);
      REQUIRE(r == exp_round_down<double>[i]);
   }

   for (size_t i = 0; i < inputs<long double>.size(); ++i)
   {
      auto r = round_down()(inputs<long double>[i]);
      REQUIRE(r == exp_round_down<long double>[i]);
   }
}

TEST_CASE("Test round ceil", "[rounding]")
{
   for (size_t i = 0; i < inputs<float>.size(); ++i)
   {
      auto r = round_ceiling()(inputs<float>[i]);
      REQUIRE(r == exp_round_ceil<float>[i]);
   }

   for (size_t i = 0; i < inputs<double>.size(); ++i)
   {
      auto r = round_ceiling()(inputs<double>[i]);
      REQUIRE(r == exp_round_ceil<double>[i]);
   }

   for (size_t i = 0; i < inputs<long double>.size(); ++i)
   {
      auto r = round_ceiling()(inputs<long double>[i]);
      REQUIRE(r == exp_round_ceil<long double>[i]);
   }
}

TEST_CASE("Test round floor", "[rounding]")
{
   for (size_t i = 0; i < inputs<float>.size(); ++i)
   {
      auto r = round_floor()(inputs<float>[i]);
      REQUIRE(r == exp_round_floor<float>[i]);
   }

   for (size_t i = 0; i < inputs<double>.size(); ++i)
   {
      auto r = round_floor()(inputs<double>[i]);
      REQUIRE(r == exp_round_floor<double>[i]);
   }

   for (size_t i = 0; i < inputs<long double>.size(); ++i)
   {
      auto r = round_floor()(inputs<long double>[i]);
      REQUIRE(r == exp_round_floor<long double>[i]);
   }
}

TEST_CASE("Test round half up", "[rounding]")
{
   for (size_t i = 0; i < inputs<float>.size(); ++i)
   {
      auto r = round_half_up()(inputs<float>[i]);
      REQUIRE(r == exp_round_half_up<float>[i]);
   }

   for (size_t i = 0; i < inputs<double>.size(); ++i)
   {
      auto r = round_half_up()(inputs<double>[i]);
      REQUIRE(r == exp_round_half_up<double>[i]);
   }

   for (size_t i = 0; i < inputs<long double>.size(); ++i)
   {
      auto r = round_half_up()(inputs<long double>[i]);
      REQUIRE(r == exp_round_half_up<long double>[i]);
   }
}

TEST_CASE("Test round half down", "[rounding]")
{
   for (size_t i = 0; i < inputs<float>.size(); ++i)
   {
      auto r = round_half_down()(inputs<float>[i]);
      REQUIRE(r == exp_round_half_down<float>[i]);
   }

   for (size_t i = 0; i < inputs<double>.size(); ++i)
   {
      auto r = round_half_down()(inputs<double>[i]);
      REQUIRE(r == exp_round_half_down<double>[i]);
   }

   for (size_t i = 0; i < inputs<long double>.size(); ++i)
   {
      auto r = round_half_down()(inputs<long double>[i]);
      REQUIRE(r == exp_round_half_down<long double>[i]);
   }
}

TEST_CASE("Test round half even", "[rounding]")
{
   for (size_t i = 0; i < inputs<float>.size(); ++i)
   {
      auto r = round_half_even()(inputs<float>[i]);
      REQUIRE(r == exp_round_half_even<float>[i]);
   }

   for (size_t i = 0; i < inputs<double>.size(); ++i)
   {
      auto r = round_half_even()(inputs<double>[i]);
      REQUIRE(r == exp_round_half_even<double>[i]);
   }

   for (size_t i = 0; i < inputs<long double>.size(); ++i)
   {
      auto r = round_half_even()(inputs<long double>[i]);
      REQUIRE(r == exp_round_half_even<long double>[i]);
   }
}

TEST_CASE("Test round half odd", "[rounding]")
{
   for (size_t i = 0; i < inputs<float>.size(); ++i)
   {
      auto r = round_half_odd()(inputs<float>[i]);
      REQUIRE(r == exp_round_half_odd<float>[i]);
   }

   for (size_t i = 0; i < inputs<double>.size(); ++i)
   {
      auto r = round_half_odd()(inputs<double>[i]);
      REQUIRE(r == exp_round_half_odd<double>[i]);
   }

   for (size_t i = 0; i < inputs<long double>.size(); ++i)
   {
      auto r = round_half_odd()(inputs<long double>[i]);
      REQUIRE(r == exp_round_half_odd<long double>[i]);
   }
}
