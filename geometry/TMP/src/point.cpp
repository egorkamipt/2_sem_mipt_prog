#include "../point.h"
#include "../vector.h"
#include <string>
#include "../segment.h"
#include "../ishape.h"

namespace geometry {

  Point::Point() : x(0), y(0) {
  }

  Vector Point::operator-(const Point& p) const {
    Vector tmp(x - p.x, y - p.y);
    return tmp;
  }

  Point::Point(const Point& p) : x(p.x), y(p.y) {
  }

  Point::Point(int64_t new_x, int64_t new_y) : x(new_x), y(new_y) {
  }

  Point& Point::Move(const Vector& a) {
    x += a.x;
    y += a.y;
    return *this;
  }

  bool Point::ContainsPoint(const Point& p) const {
    return x == p.x && y == p.y;
  }

  bool Point::CrossesSegment(const Segment& s) const {
    Vector tmp_vec1(s.second - *this);
    Vector tmp_vec2(*this - s.first);
    return !(VectorProduct(tmp_vec1, tmp_vec2)) && ScalarProduct(tmp_vec1, tmp_vec2) >= 0;
  }

  Point* Point::Clone() const {
    return new Point(*this);
  }

  std::string Point::ToString() const {
    return MakeString("Point", x, y);
  }

}
