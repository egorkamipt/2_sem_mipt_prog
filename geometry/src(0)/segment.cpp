#include "../segment.h"
#include "../line.h"

namespace geometry {

  Segment& Segment::Move(const Vector& v) {
    first.Move(v);
    second.Move(v);
    return *this;
  }

  bool Segment::ContainsPoint(const Point& p) const {
    return p.CrossesSegment(*this);
  }

  Segment* Segment::Clone() const {
    return new Segment(*this);
  }

  bool Segment::CrossesSegment(const Segment& other) const {
    Line line1(first, second);
    Line line2(other.first, other.second);
    if (line1.CrossesSegment(other) && line2.CrossesSegment(*this)) {
      bool b = std::max(first.y, second.y) >= std::min(other.first.y, other.second.y);
      bool a = std::max(first.x, second.x) >= std::min(other.first.x, other.second.x);
      return a && b;
    }
    return false;
  }

  std::string Segment::ToString() const {
    return MakeString("Segment", first.ToString(), second.ToString());
  }

}
