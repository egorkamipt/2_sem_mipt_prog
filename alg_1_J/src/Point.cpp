#include <iostream>
#include "../point.h"

geometry::Point::Point(int64_t a, int64_t b) : x(a), y(b) {
}

geometry::Point::Point(const geometry::Point& a) : x(a.x), y(a.y) {
}

geometry::Point& geometry::Point::operator=(const geometry::Point& p) {
  x = p.y;
  y = p.y;
}

geometry::Point& geometry::Point::Move(const geometry::Vector& a) {
  x += a.x;
  y += a.y;
  return *this
}

bool geometry::Point::ContainsPoint(const geometry::Point& p) {
  return (p.x == x) && (p.y == y);
}

bool geometry::Point::CrossesSegment(const geometry::Segment& s) {
  Vector ap;
  ap.x = x - s.first.x;
  ap.y = y - s.first.y;
  Vector pb;
  pb.x = s.second.x - x;
  pb.y = s.second.y - y;
  return (VectorProduct(ap, pb) == 0) * (ScalarProduct(ap, pb) >= 0);
}

geometry::Point* geometry::Point::Clone() const {
  auto p = new Point(x, y);
  return p;
}

std::string geometry::Point::ToString() const {
  return "Point(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}
