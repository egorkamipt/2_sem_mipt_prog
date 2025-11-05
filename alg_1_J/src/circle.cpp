#include <iostream>
#include "../circle.h"
#include <cmath>

geometry::Circle::Circle(const Circle& circle) : center(circle.center), radius(circle.radius) {
}

geometry::Circle& geometry::Circle::operator=(const Circle& circle) {
  center = circle.center;
  radius = circle.radius;
  return *this;
}

geometry::Circle::Circle(const Point& p, const int64_t& r) : center(p), radius(r) {
}

geometry::Circle& geometry::Circle::Move(const Vector& vector) {
  center.x += vector.x;
  center.y += vector.y;
  return *this;
}

double geometry::Circle::DistanceFromCenterToSegment(const Segment& segment) {
  Vector ac;
  ac.x = center.x - segment.first.x;
  ac.y = center.y - segment.first.y;
  Vector ab;
  ab.x = segment.second.x - segment.first.x;
  ab.y = segment.second.y - segment.first.y;
  Vector bc;
  bc.x = center.x - segment.second.x;
  bc.y = center.y - segment.second.y;
  Vector ba;
  ba.x = segment.first.x - segment.second.x;
  ba.y = segment.first.y - segment.second.y;
  if (ScalarProduct(ac, ab) >= 0 && ScalarProduct(bc, ba) >= 0) {
    int num = abs(VectorProduct(ac, ab));
    return static_cast<double>(num) / sqrt(pow(segment.second.y - segment.first.y, 2) + pow(segment.second.x - segment.first.x, 2));
  }
  if (ScalarProduct(ac, ab) >= 0) {
    return sqrt(pow(center.y - segment.second.y, 2) + pow(center.x - segment.second.x, 2));
  }
  return sqrt(pow(center.y - segment.first.y, 2) + pow(center.x - segment.first.x, 2));
}

bool geometry::Circle::ContainsPoint(const Point& p) const {
  return (p.x - center.x) * (p.x - center.x) + (p.y - center.y) * (p.y - center.y) <= radius * radius;
}

bool geometry::Circle::CrossesSegment(const Segment& s) const {
  if ((ContainsPoint(s.first) && !ContainsPoint(s.second)) || (ContainsPoint(s.second) && !ContainsPoint(s.first))) {
    return true;
  }
  if (!ContainsPoint(s.first) && !ContainsPoint(s.second) && DistanceFromCenterToSegment(s) <= radius) {
    return true;
  }
  return false;
}

geometry::Circle* geometry::Circle::Clone() const {
  auto new_circle = new Circle(center, radius);
  return new_circle;
}

std::string geometry::Circle::ToString() const {
  return "Circle(" + center.ToString() + ", " + std::to_string(r) + ")";
}
