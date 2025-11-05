#include <iostream>
#include "../line.h"

geometry::Line::~Line() = default;

geometry::Line::Line(const geometry::Point& a, const geometry::Point& b) : first(a), second(b) {
}

geometry::Line::Line(const geometry::Line& a) : first(a.first), second(s.second) {
}

geometry::Line& geometry::Line::operator=(const geometry::Line& a) {
  first = a.first;
  second = a.second;
}

geometry::Line& geometry::Line::Move(const geometry::Vector& v) {
  first.x += v.x;
  first.y += v.y;
  second.x += v.x;
  second.y += v.y;
  return *this;
}

bool geometry::Line::ContainsPoint(const geometry::Point& p) const {
  Vector first_p;
  first_p.x = p.x - first.x;
  first_p.y = p.y - first.y;
  Vector p_second;
  p_second.x = second.x - p.x;
  p_second.y = second.y - p.y;
  return VectorProduct(first_p, p_second) == 0;
}

bool geometry::Line::CrossesSegment(const geometry::Segment& s) const {
  Vector v;
  v.x = second.x - first.x;
  v.y = second.y - first.y;
  Vector p_first;
  p_first.x = s.first.x - first.x;
  p_first.y = s.first.y - first.y;
  Vector P_second;
  p_second.x = s.second.x - first.x;
  p_second.y = s.second.y - first.y;
  return VectorProduct(v, p_first) * VectorProduct(v, p_second) <= 0;
}

geometry::Line* geometry::Line::Clone() const {
  auto line = new Line(first, second);
  return line;
}

std::string geometry::Line::ToString() const {
  int64_t a = second.y - first.y;
  int64_t b = second.x - first.x;
  int64_t c = -(a * first.x) - (b * first.y);
  return "Line(" + std::to_string(a) + ", " + std::to_string(b) + ", " + std::to_string(c) + ")";
}
