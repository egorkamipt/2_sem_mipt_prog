#include "../vector.h"
#include <cstdint>
#include "../ishape.h"

namespace geometry {

  Vector& operator+=(Vector& a, const Vector& b) {
    a.x += b.x;
    a.y += b.y;
    return a;
  }

  geometry::Vector& operator-=(Vector &a, const Vector &b) {
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
    a.x = -a.x;
    a.y = -a.y;
    return a;
  }

  // Binary operators
  Vector operator+(const Vector& a, const Vector& b) {
    return Vector(a.x + b.x, a.y + b.y);
  }

  Vector operator-(const Vector& a, const Vector& b) {
    return Vector(a.x - b.x, a.y - b.y);
  }

  Vector operator*(const Vector& a, int64_t b) {
    return Vector(a.x * b, a.y * b);
  }

  Vector operator/(const Vector& a, int64_t b) {
    return Vector(a.x / b, a.y / b);
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
