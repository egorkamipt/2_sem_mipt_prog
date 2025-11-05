#ifndef GEOMETRY__SEGMENT_H_
#define GEOMETRY__SEGMENT_H_

#include <cstdint>
#include <string>

#include "ishape.h"
#include "vector.h"
#include "point.h"

namespace geometry {

  class Segment : public IShape {
   public:
    Point first;
    Point second;

    Segment();

    Segment(const Segment& s);

    Segment(const Point& a, const Point& b);

    Segment& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Segment* Clone() const override;
    std::string ToString() const override;
  };

}

#endif
