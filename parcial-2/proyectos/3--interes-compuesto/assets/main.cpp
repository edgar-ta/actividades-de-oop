#include <iostream>

int main() {
    const int purchase_year = 1626;
    const int current_year = 2024;
    const double initial_credit = 24.0;

    for (int interest_rate = 5; interest_rate <= 10; interest_rate++) {
        std::cout 
            << "CON UNA TASA DE INTERÉS DEL " 
            << interest_rate 
            << "%: " 
            << std::endl;

        double current_amount = initial_credit;

        for (int year = purchase_year + 1; year < current_year; year++) {
            current_amount *= (100.0 + interest_rate) / 100.0;

            std::wcout 
                << L"\tPara el final del año " 
                << year 
                << L" el valor inicial ascendería a: $"
                << current_amount
                << std::endl;
        }

        current_amount *= (100 + interest_rate) / 100;
        std::cout 
            << "Al final de este año, la cantidad será de: $" ;
    }

    return 0;
}
