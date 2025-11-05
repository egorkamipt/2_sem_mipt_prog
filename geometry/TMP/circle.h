#ifndef GEOMETRY__CIRCLE_H_
#define GEOMETRY__CIRCLE_H_

#include <vector>
#include "ishape.h"
#include "point.h"
#include "vector.h"

namespace geometry {

  class Circle : public IShape {
   public:
    Point center;
    int64_t radius;

    Circle(const Circle&);

    Circle(const Point&, int64_t);

    Circle& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool ContainsPoint1(const Point&) const;
    bool CrossesSegment(const Segment&) const override;
    Circle* Clone() const override;
    std::string ToString() const override;
  };

}

#endif
