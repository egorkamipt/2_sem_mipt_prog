#ifndef POINT_H
#define POINT_H
#include <iostream>
#include "interface.h"

class geometry::Point : public geometry::IShape {
 public:
  int64_t x;
  int64_t y;
  Point() = default;
  ~Point() = default;
  Point(int64_t, int64_t);
  Point(const Point&);
  Point& operator=(const Point&);
  Point& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Point* Clone() const override;
  std::string ToString() const override;
};

#endif
