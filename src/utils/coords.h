#ifndef COORDS_H
#define COORDS_H

#include "headers.h"
#include <string.h>
//#include <concepts>

//template<typename T>
//concept arithmetic = std::integral<T> or std::floating_point<T>;



using Distance = float;

 template<typename T>
struct CoordPair {
   T x;
   T y;
};



struct Coord {
  Coord() : x(-1), y(-1){};
  Coord(int _x, int _y) : x(_x), y(_y){};
  friend bool operator<(const Coord &c1, const Coord &c2);
  friend bool operator==(const Coord &c1, const Coord &c2);

  friend Coord operator+(const Coord &left, const Coord &right);
  friend Coord operator-(const Coord &left, const Coord &right);
  Coord operator/(float del);
  Coord del(float d) const;
  std::string toString() const;
  Distance length() const;
  Coord revert() const;
  int x;
  int y;
};

struct Rectangle {
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

#endif // !COORDS_H
