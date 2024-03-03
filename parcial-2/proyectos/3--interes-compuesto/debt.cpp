#include "./debt.h"

#include <iostream>
#include <cmath>
#include <iomanip>

Debt::Debt(
    double initial_amount, 
    int acquisition_year, 
    int age, 
    double interest_rate
): 
    initial_amount(initial_amount),
    acquisition_year(acquisition_year),
    age(age),
    interest_rate(interest_rate)
{
}

double Debt::get_current_debt() {
    return get_debt_at_age(age);
}

double Debt::get_debt_at_age(int age) {
    return initial_amount * pow(1 + interest_rate, age);
}

void Debt::print_inform() {
    for (int i = 1; i <= age; i++) {
        std::cout 
            << std::setprecision(50)
            << get_debt_at_age(i) 
            << " " 
            << (acquisition_year + i) 
            << " " 
            << (interest_rate * 100) 
            << "%" 
            << std::endl;
    }
    std::cout << std::endl;
}
