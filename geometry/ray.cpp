#include "../ray.h"
#include "../line.h"
#include "../segment.h"
#include "../vector.h"
#include "../point.h"
#include "../ishape.h"


namespace geometry {

  Ray::Ray() = default;

  Ray::Ray(const Point& p, const Vector& v) : point(p), vector(v) {
  }

  Ray::Ray(const Ray& r) : point(r.point), vector(r.vector) {
  }

  Ray::Ray(const Point& a, const Point& b) : point(a), vector(Vector(b.x - a.x, b.y - a.y)) {
  }

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
    if (line.CrossesSegment(s)) {
      Vector x_v = s.second - s.first;
      Vector v = point - s.first;
      auto cp1 = VectorProduct(x_v, v);
      auto cp2 = VectorProduct(x_v, vector);
      return (cp1 * cp2 <= 0);
    }
    return false;
  }

  Ray* Ray::Clone() const {
    return new Ray(*this);
  }

  std::string Ray::ToString() const {
    return MakeString("Ray", point.ToString(), vector.ToString());
  }
  Ray& Ray::operator=(const Ray& other) {
    point = other.point;
    vector = other.vector;
    return *this;
  }

}
