#include "../line.h"
#include "../segment.h"

namespace geometry {

  Line::Line(const Point& a, const Point& b) {
    A = a.y - b.y;
    B = -a.x + b.x;
    C = (a.x - b.x) * b.y - (a.y - b.y) * b.x;
  }

  Line::Line(const int64_t& a, const int64_t& b, const int64_t& c) {
    A = a;
    B = b;
    C = c;
  }

  Line& Line::Move(const Vector& vector) {
    C = C - A * vector.x - B * vector.y;
    return *this;
  }

  bool Line::ContainsPoint(const Point& p) const {
    return A * p.x + B * p.y + C == 0;
  }

  bool Line::CrossesSegment(const Segment& other) const {
    int64_t a = A * other.first.x + B * other.first.y + C;
    int64_t b = A * other.second.x + B * other.second.y + C;
    return (a * b <= 0);
  }

  Line* Line::Clone() const {
    return new Line(*this);
  }

  Vector Line::Normal() const {
    Vector tmp(A, B);
    return tmp;
  }

  int64_t Line::Distance(const Point& p) const {
    return B * p.y + C + A * p.x;
  }

  std::string Line::ToString() const {
    return MakeString("Line", A, B, C);
  }

}
