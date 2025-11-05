#ifndef GEOMETRY__RAY_H_
#define GEOMETRY__RAY_H_

#include <cstdint>
#include <string>

#include "ishape.h"
#include "vector.h"
#include "point.h"

namespace geometry {

  class Ray : public IShape {
   public:
    Point point;
    Vector vector;

    Ray();
    Ray(const Point&, const Point&);

    Ray(const Point&, const Vector&);

    Ray(const Ray&);

    Ray& Move(const Vector&) override;
    bool ContainsPoint(const Point&) const override;
    bool CrossesSegment(const Segment&) const override;
    Ray* Clone() const override;
    std::string ToString() const override;

    Ray& operator=(const Ray&);
  };

}

#endif
