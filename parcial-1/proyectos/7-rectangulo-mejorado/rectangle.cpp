#include "./rectangle.h"
#include <algorithm>
#include <iterator>
#include <utility>
#include <iostream>

void Rectangle::set_coordinates(const corners_t& coordinates) {
  this->coordinates = coordinates;
  clamp_corners();
  arrange_into_rectangle();
}

void Rectangle::clamp_corners() {
  std::for_each(
    std::begin(this->coordinates), 
    std::end(this->coordinates),
    [](Coordinate& coordinate) {
      Rectangle::clamp_coordinate(coordinate);
    }
  );
}

void Rectangle::arrange_into_rectangle() {
  std::sort(
      std::begin(this->coordinates),
      std::end(this->coordinates),
      [](const Coordinate& first, const Coordinate& second) {
      return first.get_x() - second.get_x() < 0;
      }
      );

  auto& upper_left = get_upper_left();
  auto& lower_left = get_lower_left();

  auto& upper_right = get_upper_right();
  auto& lower_right = get_lower_right();

  if (upper_left.get_y() < lower_left.get_y()) {
    std::swap(upper_left, lower_left);
  }

  if (upper_right.get_y() < lower_right.get_y()) {
    std::swap(upper_right, lower_right);
  }

  upper_left = get_upper_left();
  lower_left = get_lower_left();
  upper_right = get_upper_right();
  lower_right = get_lower_right();

  lower_left.set_x(upper_left.get_x());
  lower_right.set_x(upper_right.get_x());

  upper_right.set_y(upper_left.get_y());
  lower_right.set_y(lower_left.get_y());
}

float Rectangle::get_width() const {
  const auto& upper_left = get_upper_left();
  const auto& upper_right = get_upper_right();
  return upper_right.get_x() - upper_left.get_x();
}

float Rectangle::get_height() const {
  const auto& upper_left = get_upper_left();
  const auto& lower_left = get_lower_left();
  return upper_left.get_y() - lower_left.get_y();
}

Rectangle::Rectangle(corners_t coordinates) {
  set_coordinates(coordinates);
}

void Rectangle::print_values(std::ostream& cout) const {
  cout << "The height of the rectangle is: " << get_height() << std::endl;
  cout << "The width of the rectangle is: " << get_width() << std::endl;
  cout << "The area of the rectangle is: " << get_area() << std::endl;
  cout << "The perimeter of the rectangle is: " << get_perimeter() << std::endl;
  cout << "Is the rectangle a square? " << std::boolalpha << is_square() << std::endl;
}

void Rectangle::print_coordinates(std::ostream& cout) const {
  std::for_each(std::begin(coordinates), std::end(coordinates), [&](const Coordinate& coordinate) {
      cout << "(" << coordinate.get_x() << ", " << coordinate.get_y() << ")" << std::endl;
      });
}

/// STATIC METHODS ///

void Rectangle::clamp_coordinate(Coordinate &coordinate) {
  coordinate.set_x(Rectangle::clamp(0.0f, 20.0f, coordinate.get_x()));
  coordinate.set_y(Rectangle::clamp(0.0f, 20.0f, coordinate.get_y()));
}

float Rectangle::clamp(float minimum, float maximum, float value) {
  if (value < minimum) return minimum;
  if (value > maximum) return maximum;
  return value;
}


