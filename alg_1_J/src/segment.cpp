#include <iostream>
#include "../segment.h"

geometry::Segment::~Segment() = default;

int64_t ScalarProduct(const geometry::Segment& a, const geometry::Segment& b) {
  return (a.end.x - a.begin.x) * (b.end.x - b.begin.x) + (a.end.y - a.begin.y) * (b.end.y - b.begin.y);
}

int64_t VectorProduct(const geometry::Segment& a, const geometry::Segment& b) {
  return (a.end.x - a.begin.x) * (b.end.y - b.begin.y) - (a.end.y - a.begin.y) * (b.end.x - b.begin.x);
}

bool IfIntersect(const geometry::Segment& ab, const geometry::Segment& cd) {
  Segment ca;
  ca.begin = cd.begin;
  ca.end = ab.begin;
  Segment cb;
  cb.begin = cd.begin;
  cb.end = ab.end;
  Segment ac;
  ac.begin = ab.begin;
  ac.end = cd.begin;
  Segment ad;
  ad.begin = ab.begin;
  ad.end = cd.end;
  Segment db;
  db.begin = cd.end;
  db.end = ab.end;
  Segment bd;
  bd.begin = ab.end;
  bd.end = cd.end;
  if (VectorProduct(cd, ca) * VectorProduct(cd, cb) <= 0 && VectorProduct(ab, ac) * VectorProduct(ab, ad) <= 0) {
    if (VectorProduct(cd, ca) * VectorProduct(cd, cb) * VectorProduct(ab, ac) * VectorProduct(ab, ad) == 0) {
      return ScalarProduct(ac, cb) >= 0 || ScalarProduct(ad, db) >= 0 || ScalarProduct(ca, ad) >= 0 ||
             ScalarProduct(cb, bd) >= 0;
    }
    return true;
  }
  return false;
}

geometry::Segment::Segment(const geometry::Point& a, const geometry::Point& b) : first(a), second(b) {
}

geometry::Segment::Segment(const geometry::Segment& a) : first(a.first), second(a.second) {
}

geometry::Segment& geometry::Segment::operator=(const geometry::Segment& s) {
  first = s.first;
  second = s.second;
}

geometry::Segment& geometry::Segment::Move(const geometry::Vector& v) {
  first.x += v.x;
  first.y += v.y;
  second.x += v.x;
  second.y += v.y;
  return *this;
}

bool geometry::Segment::ContainsPoint(const geometry::Point& p) const {
  Vector ap;
  ap.x = p.x - first.x;
  ap.y = p.y - first.y;
  Vector pb;
  pb.x = second.x - p.x;
  pb.y = second.y - p.y;
  return (VectorProduct(ap, pb) == 0) * (ScalarProduct(ap, pb) >= 0);
}

bool geometry::Segment::CrossesSegment(const geometry::Segment& s) const {
  return IfIntersect(s, *this);
}

geometry::Segment* geometry::Segment::Clone() const {
  auto s = new Segment(first, second);
  return s;
}

std::string geometry::Segment::ToString() const {
  return "Segment(" + first.ToString() + ", " + second.ToString() + ")";
}
