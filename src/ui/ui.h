#include "coords.h"

enum class FigureType {
  Dot,
  Line,
  Square,
  Circle,
};

class Figure {
public:
  virtual ~Figure() = default;
  FigureType figure;
  int width;
  std::vector<Coord> coors;
};
