#include "../ray.h"
#include "../line.h"
#include "../segment.h"

namespace geometry {

  Ray& Ray::Move(const Vector& v) {
    point.Move(v);
    return *this;
  }

  bool Ray::ContainsPoint(const Point& p) const {
    Vector tmp(p - point);
    return (!VectorProduct(tmp, vector) && ScalarProduct(tmp, vector) >= 0);
  }

  bool Ray::CrossesSegment(const Segment& s) const {
    if (s.ContainsPoint(point)) {
      return true;
    }
    Point tmp(point.x + vector.x, point.y + vector.y);
    Line line(point, tmp);
    Line line(first, tmp);
    if (line.CrossesSegment(s)) {
      Vector x_v = s.second - s.first;
      Vector v = point - s.first;
      auto cp1 = VectorProduct(x_v, v);
      auto cp2 = VectorProduct(x_v, second);
      return (cp1 * cp2 <= 0);
    }
    return false;
  }

}
