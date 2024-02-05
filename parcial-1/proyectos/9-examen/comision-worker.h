#ifndef COMISION_WORKER_H
#define COMISION_WORKER_H

#include "employee.h"
#include <iostream>

// $250 + 5.7% of weekly sales
class ComisionWorker : public Employee {
  private:
    float weekly_sales;

  public:
    ComisionWorker(float);

    void set_weekly_sales(float);
    float get_weekly_sales();

    float get_weekly_wage() override;
    static ComisionWorker* construct_from_user_input(std::ostream&, std::istream&);
};

#endif // !COMISION_WORKER_H

