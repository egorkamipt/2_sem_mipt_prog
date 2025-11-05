#include <iostream>
#include "../vector.h"

geometry::Vector::Vector(const Point& a, const Point& b) : x(b.x - a.x), y(b.y - a.y) {
}

int64_t ScalarProduct(const geometry::Vector& a, const geometry::Vector& b) {
  return a.x * b.x + a.y * b.y;
}

int64_t VectorProduct(const geometry::Vector& a, const geometry::Vector& b) {
  return a.x * b.y - a.y * b.x;
}

geometry::Vector geometry::Vector::operator+() {
  return *this;
}

geometry::Vector geometry::Vector::operator-() {
  x = -x;
  y = -y;
  return *this;
}

geometry::Vector geometry::Vector::operator+(const geometry::Vector& a) const {
  Vector sum;
  sum.x = a.x + x;
  sum.y = a.y + y;
  return sum;
}

geometry::Vector geometry::Vector::operator-(const geometry::Vector& a) const {
  Vector res;
  res.x = x - a.x;
  res.y = y - a.y;
  return res;
}

geometry::Vector geometry::Vector::operator*(int64_t num) {
  Vector res;
  res.x = x * num;
  res.y = y * num;
  return res;
}

geometry::Vector geometry::Vector::operator/(int64_t num) {
  Vector res;
  res.x = x / num;
  res.y = y / num;
  return res;
}

geometry::Vector geometry::Vector::operator+=(const Vector& a) {
  x += a.x;
  y += a.y;
  return *this;
}

geometry::Vector geometry::Vector::operator-=(const Vector& a) {
  x -= a.x;
  y -= a.y;
  return *this;
}

geometry::Vector geometry::Vector::operator*=(const int64_t* a) {
  x *= a;
  y *= a;
  return *this;
}

geometry::Vector geometry::Vector::operator/=(const int64_t* a) {
  x /= a;
  y /= a;
  return *this;
}

bool geometry::Vector::operator==(const Vector& a) const {
  return (x == a.x) && (y == a.y);
}
