#pragma once

#include <iostream>
#include <string_view>

#include "utils/coords.h"

using Time = float;
using WindowSize = int;

class IPort {
 public:
  virtual void update(const Time dt) = 0;
  virtual void drawBorder(const RectangleI& borders, std::string_view headerText = "") = 0;
  virtual void render() = 0;
  virtual void init(const WindowSize w, const WindowSize h) = 0;
  virtual WindowSize getWidth() = 0;
  virtual WindowSize getHeight() = 0;
  virtual void drawText(const WindowSize x, const WindowSize y) = 0;
};
