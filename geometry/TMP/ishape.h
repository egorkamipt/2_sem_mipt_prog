#ifndef GEOMETRY__ISHAPE_H_
#define GEOMETRY__ISHAPE_H_

#include <cstdint>
#include <string>
#include <type_traits>
#include <iostream>

namespace geometry {

  class Point;
  class Vector;
  class Segment;
  class Ray;
  class Line;
  class Polygon;
  class Circle;

  class IShape {
   public:
    virtual IShape &Move(const Vector &) = 0;
    virtual bool ContainsPoint(const Point &) const = 0;
    virtual bool CrossesSegment(const Segment &) const = 0;
    virtual IShape *Clone() const = 0;
    virtual std::string ToString() const = 0;
    virtual ~IShape() = default;
  };

  template <class T>
  std::string MakeString(T &&start, int64_t a, int64_t b, int64_t c) {
    return std::string(std::forward<T>(start)) + '(' + std::to_string(-a) + ", " + std::to_string(-b) + ", " +
           std::to_string(-c) + ')';
  }
  template <class T, class U>
  std::string MakeString(T &&start, U first, U second) {
    return std::string(std::forward<T>(start)) + '(' + std::to_string(first) + ", " + std::to_string(second) + ')';
  }
  template <class T>
  std::string MakeString(T &&start, const std::string &middle, int64_t finish) {
    return std::string(std::forward<T>(start)) + '(' + middle + ", " + std::to_string(finish) + ')';
  }
  template <class T>
  std::string MakeString(T &&start, const std::string &middle, const std::string &finish) {
    return std::string(std::forward<T>(start)) + '(' + middle + ", " + finish + ')';
  }

}

#endif
