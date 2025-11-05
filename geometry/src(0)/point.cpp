#include "../point.h"

#include <string>
#include "../segment.h"

namespace geometry {

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
    return (VectorProduct(temp_vec1, temp_vec2) == 0) && (ScalarProduct(temp_vec1, temp_vec2) >= 0);
  }

  Point* Point::Clone() const {
    return new Point(*this);
  }

  std::string Point::ToString() const {
    return MakeString("Point", x, y);
  }

}
