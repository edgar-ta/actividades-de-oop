#ifndef PARTS_WORKER_H
#define PARTS_WORKER_H

#include "employee.h"
#include <iostream>

// number of pieces times the wage per piece
class PartsWorker : public Employee {
  private:
    int number_of_pieces;
    float price_per_piece;

  public:
    PartsWorker(int, float);

    void set_number_of_pieces(int);
    int get_number_of_pieces();

    void set_price_per_piece(float);
    float get_price_per_piece();

    float get_weekly_wage() override;
    static PartsWorker* construct_from_user_input(std::ostream&, std::istream&);
};


#endif // !PARTS_WORKER_H
