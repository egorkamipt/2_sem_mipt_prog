#ifndef GEOMETRY__LINE_H_
#define GEOMETRY__LINE_H_

#include <array>

#include "ishape.h"
#include "vector.h"
#include "point.h"

namespace geometry {
  class Line : public IShape {
   public:
    int64_t A;
    int64_t B;
    int64_t C;

    Line(const Line& l);

    Line(const Point&, const Point&);
    Line(const int64_t&, const int64_t&, const int64_t&);

    Line& Move(const Vector&) override;
    Line* Clone() const override;

    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;

    Vector Normal() const;
    int64_t Distance(const Point&) const;
    std::string ToString() const override;
  };

}

#endif
