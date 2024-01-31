#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
  private:
    float x;
    float y;

  public:
    Coordinate(float x, float y): x(x), y(y) {};
    Coordinate(): x(0.0f), y(0.0f) {};

    inline float get_x() const { return x; }
    inline float get_y() const { return y; }

    inline void set_x(float new_value) { x = new_value; }
    inline void set_y(float new_value) { y = new_value; }
};

#endif // !COORDINATE_H





