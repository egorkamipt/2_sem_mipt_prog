#ifndef RAY_H
#define RAY_H
#include <iostream>
#include "interface.h"

class geometry::Ray : public geometry::IShape {
 public:
  Point first;
  Point second;
  Ray() = default;
  ~Ray() final;
  Ray(const Point&, const Point&);
  Ray(const Ray&);
  Ray operator=(const Ray&);
  Ray&  Move(const Vector&) override;
  bool ContainsPoint(const Point&) const override;
  bool CrossesSegment(const Segment&) const override;
  Ray& Clone() const override;
  std::string ToString() const override;
};

#endif
