#include "../polygon.h"
#include <vector>
#include "../segment.h"
#include "../ray.h"
#include "../line.h"

namespace geometry {

  Polygon &Polygon::Move(const Vector& v) {
    for (auto& i : points)
      i.Move(v);
    return *this;
  }

  bool Polygon::ContainsPoint(const Point& p) const {
    Point point(10002, p.y + 1);
    Ray ray(p, point);
    Line line(p, point);
    int64_t count = 0;
    for (size_t i = 0; i < points.size() - 1; ++i) {
      if (Segment(points[i], points[i + 1]).ContainsPoint(ray.point)) {
        return true;
      }

      if (ray.CrossesSegment(Segment(points[i], points[i + 1]))) {
        ++count;
      }
    }
    if (ray.CrossesSegment(Segment(points[0], points[points.size() - 1]))) {
      if (Segment(points[0], points[points.size() - 1]).ContainsPoint(ray.point)) {
        return true;
      }
      ++count;
    }
    return bool(count % 2);
  }

  bool Polygon::CrossesSegment(const Segment& s) const {
    for (size_t i = 0; i < points.size() - 1; ++i) {
      if (s.CrossesSegment(Segment(points[i], points[i + 1])) {
        return true;
      }
      if (s.CrossesSegment(Segment(points[points.size() - 1], points[0]))) {
        return true;
      }
    }
    return false;
  }

  Polygon* Polygon::Clone() const {
    return new Polygon(*this);
  }

  std::string Polygon::ToString() const {
    std::string s = "Polygon(";
    for (auto& i : points)
      s += i.ToString() + ", ";
    s.pop_back();
    s.pop_back();
    s.push_back(')');
    return s;
  }

}
