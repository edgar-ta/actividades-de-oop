#ifndef HOURLY_WORKER_H
#define HOURLY_WORKER_H

#include "employee.h"
#include <iostream>

// normal wage during the first 40 hours;
// 1.5x that for the remaining hours
class HourlyWorker : public Employee {
  private:
    float wage;
    float worked_hours;

  public:
    HourlyWorker(float, float);

    inline float get_wage();
    inline void set_wage(float);

    inline float get_worked_hours();
    inline void set_worked_hours(float);

    float get_weekly_wage() override;
    static HourlyWorker* construct_from_user_input(std::ostream&, std::istream&);
};


#endif // !HOURLY_WORKER_H

