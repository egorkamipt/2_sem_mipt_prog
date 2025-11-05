#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include "interface.h"

class geometry::Circle : public::IShape {
 public:
  Point center;
  int64_t radius;
  Circle() = default;
  ~Circle() = default;
  Circle(const Circle&);
  Circle& operator=(const Circle&);
  Circle(const Point&, const int64_t&);
  Circle& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  double DistanceFromCenterToSegment(const Segment&) const override;
  Circle* Clone() const override;
  std::string ToString() const override;
};

#endif
