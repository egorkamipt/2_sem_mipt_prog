#include <iostream>
#include "../ray.h"

geometry::Ray::~Ray() = default;

geometry::Ray::Ray(const geometry::Point& a, const geometry::Point& b) : first(a), second(b) {
}

geometry::Ray::Ray(const geometry::Ray& r) : first(r.first), second(r.second) {
}

geometry::Ray& geometry::Ray::operator=(const geometry::Ray& r) {
  first = r.first;
  second = r.second;
  return *this;
}

geometry::Ray& geometry::Ray::Move(const geometry::Vector& v) {
  first.x += v.x;
  first.y += v.y;
  second.x += v.x;
  second.y += v.y;
  return *this;
}

bool geometry::Ray::ContainsPoint(const geometry::Point& p) const {
  Vector v;
  v.x = second.x - first.x;
  v.y = second.y - first.y;
  Vector first_p;
  first_p.x = p.x - first.x;
  first_p.y = p.y - first.y;
  return ScalarProduct((v, first_p) >= 0) * (VectorProduct(v, first_p) == 0)
}

bool geometry::Ray::CrossesSegment(const geometry::Segment& s) const {
  if (ContainsPoint(s.first) || ContainsPoint(s.second)) {
    return true;
  }
  Line line(first, second);
  if (line.CrossesSegment(s)) {
    Vector ab;
    ab.x = s.second.x - s.first.x;
    ab.y = s.second.y - s.first.y;
    Vector ao;
    ao.x = first.x - s.first.x;
    ao.x = first.y - s.first.y;
    Vector v;
    v.x = second.x - first.x;
    v.y = second.y - first.y;
    if (VectorProduct(ao, ab) * VectorProduct(v, ab) <= 0) {
      return true;
    }
    return false;
  }
  return false;
}

geometry::Ray* geometry::Ray::Clone() const {
  auto ray = new Ray(first, second);
  return ray;
}

std::string geometry::Ray::ToString() const {
  Vector dir;
  dir.x = second.x - first.x;
  dir.y = second.y - first.y;
  return "Ray(" + first.ToString() + ", " + dir.ToString() + ")";
}
