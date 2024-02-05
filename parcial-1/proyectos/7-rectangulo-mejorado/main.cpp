#include <algorithm>
#include <array>
#include <cstdlib>
#include <cmath>
#include <utility>

namespace rectangles_and_points {

  bool rough_comparison(float a, float b, int specificity = 10) {
    return (a - b) * powf(10, specificity) < 1;
  }

  class Point {
    private:
      float x, y;

    public:
      Point(): x(0.0), y(0.0) {}
      Point(float x, float y): x(x), y(y) {}

      void set_x(float x) { this->x = x; }
      void set_y(float y) { this->y = y; }

      float get_x() { return x; }
      float get_y() { return y; }

      static float get_distance_between(const Point& first, const Point& second) {
        return hypotf(first.x - second.x, first.y - second.y);
      }
  };

  using Corners_t = std::array<Point, 4>;

  class Rectangle {
    private:
      Corners_t corners;

    public:
      Rectangle(Corners_t&& corners) {
        set_corners(std::forward<Corners_t>(corners));
      }

      static bool is_rectangle(const Corners_t& ordered_corners) {
        auto& first  = ordered_corners[0];
        auto& second = ordered_corners[1];
        auto& third  = ordered_corners[2];
        auto& fourth = ordered_corners[3];

        auto side_a = Point::get_distance_between(first, second);
        auto side_a_prime = Point::get_distance_between(third, fourth);
        if (side_a != side_a_prime) return false;

        auto side_b = Point::get_distance_between(second, third);
        auto side_b_prime = Point::get_distance_between(fourth, first);
        if (side_b != side_b_prime) return false;

        auto diagonal = Point::get_distance_between(first, third);
        return rough_comparison(
          powf(diagonal, 2), 
          powf(side_a, 2) + powf(side_b, 2)
        );
      }

      static void sort_corners(Corners_t& disordered_corners) {
        for (int i = 0; i < disordered_corners.size() - 2; i++) {
          auto& current_point = disordered_corners[i];
          std::sort(
            std::begin(disordered_corners) + i + 1,
            std::end(disordered_corners),
            [&](const Point& point) {
              return Point::get_distance_between(point, current_point);
            }
          );
        }
      }

      void set_corners(Corners_t&& corners) {
        Rectangle::sort_corners(corners);
        if (Rectangle::is_rectangle(corners)) {
          this->corners = corners;
        }
      }

      void set_corners(const Corners_t& corners) {
        auto other_corners = corners;
        set_corners(std::forward<Corners_t>(other_corners));
      }
  };
}


int main (int argc, char *argv[]) {
  
  return EXIT_SUCCESS;
}

