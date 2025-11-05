#include <iostream>
#include <cmath>
#include <iomanip>

struct Point {
  int64_t x;
  int64_t y;
};

struct Vector {
  Point begin;
  Point end;
  double Length();
};

double Vector::Length() {
  return sqrt((end.x - begin.x) * (end.x - begin.x) + (end.y - begin.y) * (end.y - begin.y));
}

int64_t ScalarProduct(Vector a, Vector b) {
  return (a.end.x - a.begin.x) * (b.end.x - b.begin.x) + (a.end.y - a.begin.y) * (b.end.y - b.begin.y);
}

int64_t VectorProduct(Vector a, Vector b) {
  return (a.end.x - a.begin.x) * (b.end.y - b.begin.y) - (a.end.y - a.begin.y) * (b.end.x - b.begin.x);
}

bool IfIntersect(Vector ab, Vector cd) {
  Vector ca;
  ca.begin = cd.begin;
  ca.end = ab.begin;
  Vector cb;
  cb.begin = cd.begin;
  cb.end = ab.end;
  Vector ac;
  ac.begin = ab.begin;
  ac.end = cd.begin;
  Vector ad;
  ad.begin = ab.begin;
  ad.end = cd.end;
  Vector db;
  db.begin = cd.end;
  db.end = ab.end;
  Vector bd;
  bd.begin = ab.end;
  bd.end = cd.end;
  if (VectorProduct(cd, ca) * VectorProduct(cd, cb) <= 0 && VectorProduct(ab, ac) * VectorProduct(ab, ad) <= 0) {
    if (VectorProduct(cd, ca) == 0 && VectorProduct(cd, cb) == 0 && VectorProduct(ab, ac) == 0 &&
        VectorProduct(ab, ad) == 0) {
      return ScalarProduct(ac, cb) >= 0 || ScalarProduct(ad, db) >= 0 || ScalarProduct(ca, ad) >= 0 ||
             ScalarProduct(cb, bd) >= 0;
    }
    return true;
  }
  return false;
}

double Distance(Point p, Vector ab) {
  Vector ap;
  ap.begin = ab.begin;
  ap.end = p;
  if (ScalarProduct(ap, ab) <= 0) {
    return ap.Length();
  }
  Vector ba;
  ba.begin = ab.end;
  ba.end = ab.begin;
  Vector bp;
  bp.begin = ab.end;
  bp.end = p;
  if (ScalarProduct(bp, ba) <= 0) {
    return bp.Length();
  }
  return abs(VectorProduct(ap, ab)) / ab.Length();
}

int main() {
  Vector ab;
  Vector cd;
  std::cin >> ab.begin.x >> ab.begin.y >> ab.end.x >> ab.end.y;
  std::cin >> cd.begin.x >> cd.begin.y >> cd.end.x >> cd.end.y;
  if (IfIntersect(ab, cd)) {
    std::cout << 0;
  } else {
    std::cout << std::fixed;
    std::cout << std::setprecision(6);
    std::cout << std::min(std::min(Distance(ab.begin, cd), Distance(ab.end, cd)),
                          std::min(Distance(cd.end, ab), Distance(cd.begin, ab)));
  }
  return 0;
}
