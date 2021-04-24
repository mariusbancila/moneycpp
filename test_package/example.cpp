#define HAS_COUNTRY_AND_CURRENCY_DB

#include <moneycpp/money.h>
#include <moneycpp/currency.h>
#include <iostream>

template <typename TValue>
std::string to_string(moneycpp::money<TValue> const& m)
{
    return std::to_string(m.amount);
}

std::string_view to_string(moneycpp::currency_unit const& c)
{
    return c.code;
}

int main()
{
    using namespace moneycpp;

    // create and operate with money values
    auto const m1 = make_money(20.0, currency::USD);
    auto const m2 = make_money(30.0, currency::USD);

    auto const m3 = m1 + m2;

    std::cout << to_string(m1) << '+' << to_string(m2) << '=' << to_string(m3) << ' ' << to_string(m3.currency) << std::endl;
    return 0;
}
