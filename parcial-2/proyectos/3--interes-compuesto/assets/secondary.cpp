#include <iostream>


int main() {
    const int purchase_year = 1626;
    const int current_year = 2024;
    const double initial_credit = 24.0;

    for (int interest_rate = 5; interest_rate <= 10; interest_rate += 5) {
        double current_amount = initial_credit;

        for (int year = purchase_year + 1; year <= current_year; year++) {
            current_amount *= (100.0 + interest_rate) / 100.0;

            std::cout << "$" << current_amount << " " << year << " " << interest_rate << "%" << std::endl;
        }
        std::cout << "---" << std::endl;
    }

    return 0;
}
