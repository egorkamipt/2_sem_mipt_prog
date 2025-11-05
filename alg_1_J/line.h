#ifndef LINE_H
#define LINE_H
#include <iostream>
#include "interface.h"

class geometry::Line : public geometry::IShape {
 public:
  Point first;
  Point second;
  Line() = default;
  ~Line() final;
  Line(const Point&, const Point&);
  Line(const Line&);
  Line& operator=(const Line&);
  Line& Move(const geometry::Vector&) override;
  bool ContainsPoint(const geometry::Point&) const override;
  bool CrossesSegment(const geometry::Segment&) const override;
  Line* Clone() const override;
  std::string ToString() const override;
};

#endif
