#ifndef GEOMETRY__POLYGON_H_
#define GEOMETRY__POLYGON_H_

#include <vector>
#include <utility>

#include "ishape.h"
#include "point.h"
#include "vector.h"

namespace geometry {

  class Polygon : public IShape {
   public:
    std::vector<Point> points;

    Polygon (const Polygon&);

    explicit Polygon(const std::vector<Point>&);

    Polygon& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Polygon* Clone() const override;
    std::string ToString() const override;
  };

}

#endif
