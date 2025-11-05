#include "../circle.h"
#include "../segment.h"
#include "../line.h"

namespace geometry {

  Circle& Circle::Move(const Vector& v) {
    center.Move(v);
    return *this;
  }

  bool Circle::ContainsPoint(const Point& other) const {
    int64_t other_x = (other.x - x) * (other.x - x);
    int64_t other_y = (other.y - y) * (other.y - y);
    return other_x + other_y <= radius;
  }

  bool Circle::ContainsPoint1(const Point& other) const {
    int64_t other_x = (other.x - x) * (other.x - x);
    int64_t other_y = (other.y - y) * (other.y - y);
    return other_x + other_y <= radius;
  }

  Circle* Circle::Clone() const {
    return new Circle(*this);
  }

  std::string Circle::ToString() const {
    return MakeString("Circle", center.ToString(), radius);
  }

  bool Circle::CrossesSegment(const Segment& other) const {
    if (ContainsPoint1(other.first) || ContainsPoint1(other.second)) {
      return true;
    }
    if (ContainsPoint(other.first) && !ContainsPoint(other.second)) {
      return true;
    }
    if (!ContainsPoint(other.first) && ContainsPoint(other.second)) {
      return true;
    }
    if (ContainsPoint(other.first) && ContainsPoint(other.second)) {
      return false;
    }
    Line other_line(other.first, other.second);
    int64_t val = other_line.Distance(center);
    int64_t len = val * val;
    if (len > radius * radius * (other_line.A * other_line.A + other_line.B * other_line.B)) {
      return false;
    }
    const Vector normal = other_line.Normal();
    Point tmp(center.x + normal.x, center.y + normal.y);
    Line normal_line(center, tmp);
    return normal_line.CrossesSegment(other);
  }

}
