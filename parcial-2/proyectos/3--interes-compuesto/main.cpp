#include <iostream>
#include <cmath>
#include "./debt.h"

#define YEARS_SINCE(given_year) (2024 - given_year)

int main() {
    const double leased_amount = 24.0;

    Debt first_case(leased_amount, 1626, YEARS_SINCE(1626), 0.05);
    first_case.print_inform();

    Debt second_case(leased_amount, 1626, YEARS_SINCE(1626), 0.10);
    second_case.print_inform();

    Debt third_case((double) 100000.0, 2014, YEARS_SINCE(2014), 0.05);
    third_case.print_inform();

    return 0;
}
