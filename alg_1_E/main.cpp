#include <iostream>

struct Point {
  int x = 0;
  int y = 0;
};

struct Vector {
  Point begin;
  Point end;
};

int ScalarProduct(Vector a, Vector b) {
  return (a.end.x - a.begin.x) * (b.end.x - b.begin.x) + (a.end.y - a.begin.y) * (b.end.y - b.begin.y);
}

int VectorProduct(Vector a, Vector b) {
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
    if (VectorProduct(cd, ca) * VectorProduct(cd, cb) * VectorProduct(ab, ac) * VectorProduct(ab, ad) == 0) {
      return ScalarProduct(ac, cb) >= 0 || ScalarProduct(ad, db) >= 0 || ScalarProduct(ca, ad) >= 0 ||
             ScalarProduct(cb, bd) >= 0;
    }
    return true;
  }
  return false;
}

int main() {
  Vector ab;
  Vector cd;
  std::cin >> ab.begin.x >> ab.begin.y >> ab.end.x >> ab.end.y;
  std::cin >> cd.begin.x >> cd.begin.y >> cd.end.x >> cd.end.y;
  if (IfIntersect(ab, cd)) {
    std::cout << "YES";
  } else {
    std::cout << "NO";
  }
  return 0;
}
