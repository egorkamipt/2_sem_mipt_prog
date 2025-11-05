#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <string>
#include "vector.h"

namespace geometry {
  class Point;
  class Segment;
  class Line;
  class Ray;
  class Polygon;
  class Circle;
  class IShape {
   public:
    virtual ~IShape() = default;
    virtual IShape& Move(const Vector& vector) = 0;
    virtual bool ContainsPoint(const Point& point) const = 0;
    virtual bool CrossesSegment(const Segment& segment) const = 0;
    virtual IShape* Clone() const = 0;
    virtual std::string ToString() = 0;
  };
}

#endif
