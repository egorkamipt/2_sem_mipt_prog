#include <iostream>
#include <iomanip>
#include <cmath>

struct Point {
  int x;
  int y;
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

double VectorLength(Vector a) {
  return sqrt((a.end.x - a.begin.x) * (a.end.x - a.begin.x) + (a.end.y - a.begin.y) * (a.end.y - a.begin.y));
}

Vector SummaryVector(Vector a, Vector b) {
  Vector c;
  c.begin.x = 0;
  c.begin.y = 0;
  c.end.x = (a.end.x - a.begin.x) + (b.end.x - b.begin.x);
  c.end.y = (b.end.y - b.begin.y) + (a.end.y - a.begin.y);
  return c;
}

double Square(Vector a, Vector b) {
  int x = VectorProduct(a, b);
  return abs(x) / 2 + abs(x) % 2 * 0.5;
}

int main() {
  Vector a;
  Vector b;
  std::cin >> a.begin.x >> a.begin.y;
  std::cin >> a.end.x >> a.end.y;
  std::cin >> b.begin.x >> b.begin.y;
  std::cin >> b.end.x >> b.end.y;
  std::cout << std::fixed;
  std::cout << std::setprecision(6);
  std::cout << VectorLength(a) << " " << VectorLength(b);
  std::cout << '\n';
  Vector c = SummaryVector(a, b);
  std::cout << c.end.x << " " << c.end.y;
  std::cout << '\n';
  std::cout << ScalarProduct(a, b) << " " << VectorProduct(a, b);
  std::cout << '\n';
  std::cout << Square(a, b);
  return 0;
}
