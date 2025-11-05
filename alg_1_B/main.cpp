#include <iostream>
#include <iomanip>
#include <cmath>

struct Point {
  int x = 0;
  int y = 0;
};

struct Vector {
  Point begin;
  Point end;
};

struct Line {
  int a;
  int b;
  int c;
  Vector Direction();
};

Vector Line::Direction() {
  Vector v;
  v.end.x = b;
  v.end.y = -a;
  return v;
}

double FindDistance(Line a, Line b) {
  if (a.a == 0) {
    return abs(a.c / a.b - b.c / b.b);
  }
  return abs(a.c - a.a * b.c / b.a) / sqrt(a.b * a.b + a.a * a.a);
}

bool Parallel(Line a, Line b) {
  return a.b * b.a == a.a * b.b;
}

int main() {
  Line first;
  Line second;
  std::cin >> first.a >> first.b >> first.c;
  std::cin >> second.a >> second.b >> second.c;
  std::cout << std::fixed;
  std::cout << std::setprecision(6);
  Vector first_dir = first.Direction();
  Vector second_dir = second.Direction();
  std::cout << first_dir.end.x << " " << first_dir.end.y;
  std::cout << "\n";
  std::cout << second_dir.end.x << " " << second_dir.end.y;
  std::cout << "\n";
  if (Parallel(first, second)) {
    std::cout << FindDistance(first, second);
    std::cout << "\n";
  } else {
    double det = first.a * second.b - second.a * first.b;
    std::cout << (second.c * first.b - first.c * second.b) / det << " "
              << -(second.c * first.a - first.c * second.a) / det;
  }
  return 0;
}
