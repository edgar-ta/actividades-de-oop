#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "./coordinate.h"

#include <algorithm>
#include <iterator>
#include <memory>
#include <array>
#include <ostream>

using corners_t = std::array<Coordinate, 4>;

class Rectangle {
  private:
    corners_t coordinates;

  public:
    /**
     * Constructs the `Rectangle` object by calling the `set_coordinates` function
     * with the provided coordinates
     * */
    Rectangle(corners_t);

    static float clamp(float, float, float);
    static void clamp_coordinate(Coordinate&);

    /**
     * Uses the given coordinates to set the corners of the 
     * rectangle; the coordinates are clamped so they all 
     * belong to the first quadrant of the Cartesian plane,
     * and also, they are modified so they form a valid 
     * rectangle
     * */
    void set_coordinates(const corners_t&);

    void arrange_into_rectangle();
    void clamp_corners();

    float get_width() const;
    float get_height() const;

    /**
     * Checks whether the current corner coordinates form a square; 
     * that can be done by verifying that the width and height of 
     * the rectangle are the same, but I think there may be a 
     * better solution 
     * */
    inline bool is_square()       const { return get_width() == get_height(); };
    inline float get_perimeter()  const { return 2 * (get_height() + get_width()); };
    inline float get_area()       const { return get_height() * get_width(); };

    inline const Coordinate& get_upper_left()  const { return coordinates[0]; };
    inline const Coordinate& get_lower_left()  const { return coordinates[1]; };
    inline const Coordinate& get_upper_right() const { return coordinates[2]; };
    inline const Coordinate& get_lower_right() const { return coordinates[3]; };

    inline Coordinate& get_upper_left()  { return coordinates[0]; };
    inline Coordinate& get_lower_left()  { return coordinates[1]; };
    inline Coordinate& get_upper_right() { return coordinates[2]; };
    inline Coordinate& get_lower_right() { return coordinates[3]; };

    void print_values(std::ostream&) const;
    void print_coordinates(std::ostream&) const;
};

#endif // !RECTANGLE_H


