#ifndef COORDS_H
#define COORDS_H

#include <string.h>

#include "headers.h"
// #include <concepts>

// template<typename T>
// concept arithmetic = std::integral<T> or std::floating_point<T>;

using Distance = float;

template <typename T>
struct CoordPair {
  CoordPair() : x(0), y(0){};
  CoordPair(int _x, int _y) : x(_x), y(_y){};

  bool operator<(const CoordPair& c2) {
    if (x == c2.x) {
      return y > c2.y;
    }

    return x < c2.x;
  }

  bool operator==(const CoordPair& c2) { return x == c2.x && y == c2.y; }

  CoordPair operator+(const CoordPair& right) { return CoordPair(x + right.x, y + right.y); }
  CoordPair operator-(const CoordPair& right) { return CoordPair(x - right.x, y - right.y); }

  CoordPair del(float d) const { return CoordPair(static_cast<T>(x / d), static_cast<T>(y / d)); }
  CoordPair operator/(float d) { return del(d); }

  std::string toString() const { return std::string("[") + std::to_string(x) + "," + std::to_string(y) + "]"; }
  Distance length() const { return static_cast<Distance>(sqrt(x * x + y * y)); }

  CoordPair revert() const { return {-x, -y}; }
  
  T x;
  T y;
};

struct Coord {
  Coord() : x(-1), y(-1) {};
  Coord(int _x, int _y) : x(_x), y(_y) {};
  friend bool operator<(const Coord& c1, const Coord& c2);
  friend bool operator==(const Coord& c1, const Coord& c2);

  friend Coord operator+(const Coord& left, const Coord& right);
  friend Coord operator-(const Coord& left, const Coord& right);
  Coord operator/(float del);
  Coord del(float d) const;
  std::string toString() const;
  Distance length() const;
  Coord revert() const;
  int x;
  int y;
};

struct RectangleI {
  Coord lu;
  Coord rd;
  int width() const { return rd.x - lu.x; }
  int height() const { return rd.y - lu.y; }
};
//
struct LineCord {
  Coord cord_s;
  Coord cord_e;
};

#endif  // !COORDS_H
