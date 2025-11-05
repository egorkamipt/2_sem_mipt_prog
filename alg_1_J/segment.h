#ifndef SEGMENT_H
#define SEGMENT_H
#include <iostream>
#include "interface.h"

class geometry::Segment : public geometry::IShape {
 public:
  Point first;
  Point second;
  Segment() = default;
  ~Segment() final;
  Segment(const Point&, const Point&);
  Segment(const Segment&);
  Segment& operator=(const Segment&);
  Segment& Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Segment* Clone() const override;
  std::string ToString() const override;
};

#endif
