#include <iostream>
#include "../polygon.h"

geometry::Polygon::~Polygon() = default;

geometry::Polygon::Polygon(std::vector<Point>&& vector) : points(std::move(vector)) {
}

geometry::Polygon::Polygon(const std::vector<geometry::Point>& vector) : points(vector) {
}

geometry::Polygon::Polygon(const geometry::Polygon& other) : points(other.points) {
}

geometry::Polygon& geometry::Polygon::Move(const geometry::Vector& v) {
  int64_t number = static_cast<int64_t>(points.size());
  for (int64_t i = 0; i < number; ++i) {
    points[i].x += v.x;
    points[i].y += v.y;
  }
  return *this;
}

bool geometry::Polygon::ContainsPoint(const geometry::Point& p) const {
  bool flag = false;
  int64_t number = static_cast<int64_t>(points.size());
  int64_t count = 0;
  Point tmp_p;
  tmp_p.x = p.x + 1;
  tmp_p.y = p.y;
  Vector v;
  v.x = 1;
  v.y = 0;
  Ray ray(p, tmp_p);
  for (int64_t i = 0; i < number - 1; ++i) {
    if (p.CrossesSegment(Segment(points[i], points[i + 1]))) {
      flag = true;
    }
    if (!flag) {
      if (ray.CrossesSegment(Segment(points[i], points[i + 1]))) {
        if (VectorProduct(v, Vector(points[i], points[i + 1])) != 0) {
          if (points[i].y < points[i + 1].y) {
            if (!ray.ContainsPoint(points[i])) {
              ++count;
            }
          } else {
            if (!ray.ContainsPoint(points[i + 1])) {
              ++count;
            }
          }
        }
      }
    }
  }
  if (p.CrossesSegment(Segment(points[number - 1], points[0]))) {
    flag = true;
  }
  if (!flag) {
    if (VectorProduct(v, Vector(points[number - 1], points[0])) != 0) {
      if (ray.CrossesSegment(Segment(points[number - 1], points[0]))) {
        if (points[number - 1].y < points[0].y) {
          if (!ray.ContainsPoint(points[number - 1])) {
            ++count;
          }
        } else {
          if (!ray.ContainsPoint(points[0])) {
            ++count;
          }
        }
      }
    }
  }
  if (!flag) {
    if (count % 2 != 0) {
      flag = true;
    }
  }
  return flag;
}

bool geometry::Polygon::CrossesSegment(const geometry::Segment& s) const {
  bool flag = false;
  int64_t number = static_cast<int64_t>(points.size());
  for (int64_t i = 0; i < number - 1; ++i) {
    if (Segment(points[i], points[i + 1]).CrossesSegment(s)) {
      flag = true;
      break;
    }
  }
  if (Segment(points[number - 1], points[0]).CrossesSegment(s)) {
    flag = true;
  }
  return flag;
}

geometry::Polygon* geometry::Polygon::Clone() const {
  auto new_polygon = new Polygon;
  new_polygon->points = points;
  return new_polygon;
}

std::string geometry::Polygon::ToString() const {
  int64_t number = static_cast<int64_t>(points.size());
  std::string message = "Polygon(" + points[0].ToString();
  for (int64_t i = 1; i < number; ++i) {
    message += ", " + points[i].ToString();
  }
  message += ")";
  return message;
}

geometry::Polygon& geometry::Polygon::operator=(const Polygon& polygon) {
  points = polygon.points;
  return *this;
}
