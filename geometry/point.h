#ifndef GEOMETRY__POINT_H_
#define GEOMETRY__POINT_H_

#include <cstdint>
#include <string>
#include <iostream>

#include "ishape.h"
#include "vector.h"

namespace geometry {

  class Point : public IShape {
   public:
    int64_t x;
    int64_t y;

    Point();
    Point(int64_t new_x, int64_t new_y);

    Point(const Point& p);

    Vector operator-(const Point& p) const;

    Point& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Point* Clone() const override;
    std::string ToString() const override;
  };

}

#endif
