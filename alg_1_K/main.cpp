#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

struct Point {
  int64_t x;
  int64_t y;
};

struct Vector {
  int64_t x;
  int64_t y;
  Vector();
  Vector(const Point& first, const Point& second);
  double Len() const;
};

Vector::Vector() {
  x = 0;
  y = 0;
}

Vector::Vector(const Point& first, const Point& second) {
  x = second.x - first.x;
  y = second.y - first.y;
}

double Vector::Len() const {
  return sqrt(x * x + y * y);
}

int64_t VectorProduct(const Vector& first, const Vector& second) {
  return first.x * second.y - first.y * second.x;
}

void FindFirstPoint(std::vector<Point>& points, const int& n) {
  for (int i = 1; i < n; ++i) {
    if (points[i].x < points[0].x || (points[i].x == points[0].x && points[i].y < points[0].y)) {
      std::swap(points[0], points[i]);
    }
  }
}

void SortForAngle(std::vector<Point>& points) {
  std::sort(points.begin() + 1, points.end(), [&points](const Point& first, const Point& second) {
    return VectorProduct(Vector(points[0], first), Vector(points[0], second)) > 0 ||
           (VectorProduct(Vector(points[0], first), Vector(points[0], second)) == 0 &&
            Vector(points[0], first).Len() < Vector(points[0], second).Len());
  });
}

void BuildHull(std::vector<Point>& hull, std::vector<Point>& points, const int& n) {
  for (int i = 2; i < n; ++i) {
    while (hull.size() >= 2 && VectorProduct(Vector(hull[hull.size() - 2], hull[hull.size() - 1]),
                                             Vector(hull[hull.size() - 1], points[i])) <= 0) {
      hull.pop_back();
    }
    hull.push_back(points[i]);
  }
}

long double CalculateHullSquare(std::vector<Point>& hull) {
  long double square = 0;
  for (size_t i = 1; i < hull.size() - 1; ++i) {
    square += VectorProduct(Vector(hull[0], hull[i]), Vector(hull[0], hull[i + 1]));
  }
  return square;
}

int main() {
  int n;
  std::cin >> n;
  std::vector<Point> points(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> points[i].x >> points[i].y;
  }
  FindFirstPoint(points, n);
  SortForAngle(points);
  std::vector<Point> hull = {points[0], points[1]};
  BuildHull(hull, points, n);
  std::cout << hull.size() << "\n";
  std::cout << hull[0].x << " " << hull[0].y << "\n";
  for (size_t i = hull.size() - 1; i > 0; --i) {
    std::cout << hull[i].x << " " << hull[i].y << "\n";
  }
  long double square = CalculateHullSquare(hull);
  std::cout << std::setprecision(1) << std::fixed << square / 2 << std::endl;
  return 0;
}
