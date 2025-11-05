#include "../vector.h"
#include <iostream>
#include <cstdint>
#include "../ishape.h"
#include "../point.h"

namespace geometry {

  Vector::Vector(const Vector& v) = default;

  Vector::Vector() : x(0), y(0) {
  }

  Vector::Vector(const Point& p) : x(p.x), y(p.y) {
  }

  Vector::Vector(const Point& a, const Point& b) : x(b.x - a.x), y(b.y - a.y) {
  }

  Vector::Vector(int64_t new_x, int64_t new_y) : x(new_x), y(new_y) {
  }

  Vector& operator+=(Vector& a, const Vector& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
  }

  Vector& operator-=(Vector &a, const Vector &b) {
    a.x -= b.x;
    a.y -= b.y;
    return a;
  }

  Vector& operator*=(Vector& a, int64_t b) {
    a.x *= b;
    a.y *= b;
    return a;
  }

  Vector& operator/=(Vector& a, int64_t b) {
    a.x /= b;
    a.y /= b;
    return a;
  }

  // Unary operators
  Vector operator+(const Vector& a) {
    return a;
  }

  Vector operator-(const Vector& a) {
    Vector tmp(-a.x, -a.y);
    return tmp;
  }

  // Binary operators
  Vector operator+(const Vector& a, const Vector& b) {
    Vector tmp(a.x + b.x, a.y + b.y);
    return tmp;
  }

  Vector operator-(const Vector& a, const Vector& b) {
    Vector tmp(a.x - b.x, a.y - b.y);
    return tmp;
  }

  Vector operator*(const Vector& a, int64_t b) {
    Vector tmp(a.x * b, a.y * b);
    return tmp;
  }

  Vector operator/(const Vector& a, int64_t b) {
    Vector tmp(a.x / b, a.y / b);
    return tmp;
  }

  // Equal operator
  bool operator==(const Vector& a, const Vector& b) {
    return a.x == b.x && a.y == b.y;
  }

  // Products
  int64_t ScalarProduct(const Vector& a, const Vector& b) {
    return a.x * b.x + a.y * b.y;
  }

  int64_t VectorProduct(const Vector& a, const Vector& b) {
    return a.x * b.y - a.y * b.x;
  }

  std::string Vector::ToString() const {
    return MakeString("Vector", x, y);
  }

}
