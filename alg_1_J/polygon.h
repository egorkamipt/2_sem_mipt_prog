#ifndef POLYGON_H
#define POLYGON_H
#include <iostream>
#include "interface.h"

class geometry::Polygon : public geometry::IShape {
 public:
  std::vector<geometry::Point> points;
  Polygon() = default;
  ~Polygon() final;
  Polygon(const Polygon&);
  explicit Polygon(std::vector<geometry::Point>&&);
  explicit Polygon(const std::vector<geometry::Point>&);
  Polygon& Move(const geometry::Vector&) override;
  bool ContainsPoint(const geometry::Point&) const override;
  bool CrossesSegment(const geometry::Segment&) const override;
  Polygon* Clone() const override;
  std::string ToString() const override;
  Polygon& operator=(const Polygon&);
};

#endif
