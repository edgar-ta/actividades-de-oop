#if !defined(__DEBT_H__)
#define __DEBT_H__

class Debt {
    private:

    double initial_amount;
    int    acquisition_year;
    int    age;
    double interest_rate;

    public:

    Debt(double, int, int, double);

    double get_current_debt();
    double get_debt_at_age(int);
    void print_inform();
};

#endif // __DEBT_H__
