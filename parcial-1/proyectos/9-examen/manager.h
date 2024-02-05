#ifndef MANAGER_H
#define MANAGER_H

#include "employee.h"
#include <iostream>

// has a fixed weekly wage
class Manager : public Employee {
  private:
    float wage;

  public:
    Manager(float);

    inline float get_wage();
    inline void set_wage(float);
    float get_weekly_wage() override;

    static Manager* construct_from_user_input(std::ostream&, std::istream&);
};

#endif

