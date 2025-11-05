#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class geometry::Vector {
 public:
  int64_t x;
  int64_t y;
  Vector() = default;
  ~Vector() = default;
  Vector(const Vector&) = default;
  Vector& operator=(const Vector&) = default;
  Vector(const Point&, const Point&);
  Vector operator+();
  Vector operator-();
  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
  Vector operator*(const int&);
  Vector operator/(const int&);
  Vector& operator+=(const Vector&);
  Vector& operator-=(const Vector&);
  Vector& operator*=(const int&);
  Vector& operator/=(const int&);
  bool operator==(const Vector&) const;
};

int64_t VectorProduct(const geometry::Vector& a, const geometry::Vector& b);
int64_t ScalarProduct(const geometry::Vector& a, const geometry::Vector& b);

#endif
