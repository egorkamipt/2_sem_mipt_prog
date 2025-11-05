#ifndef GEOMETRY__VECTOR_H_
#define GEOMETRY__VECTOR_H_

#include <iostream>
#include "ishape.h"
#include <utility>
#include <cstdint>
#include <string>
#include "point.h"

namespace geometry {

  class Vector {
   public:
    int64_t x;
    int64_t y;
    Vector();
    Vector(const Vector&);
    Vector(int64_t new_x, int64_t new_y);

    Vector(const Point& a, const Point& b);

    explicit Vector(const Point& p);

    friend Vector& operator+=(Vector&, const Vector&);
    friend Vector& operator-=(Vector&, const Vector&);
    friend Vector& operator*=(Vector&, int64_t);
    friend Vector& operator/=(Vector&, int64_t);
    friend Vector operator+(const Vector&);
    friend Vector operator-(const Vector&);
    friend Vector operator+(const Vector&, const Vector&);
    friend Vector operator-(const Vector&, const Vector&);
    friend Vector operator*(const Vector&, int64_t);
    friend Vector operator/(const Vector&, int64_t);
    friend bool operator==(const Vector&, const Vector&);
    friend int64_t ScalarProduct(const Vector&, const Vector&);
    friend int64_t VectorProduct(const Vector&, const Vector&);
    std::string ToString() const;
  };

}

#endif
