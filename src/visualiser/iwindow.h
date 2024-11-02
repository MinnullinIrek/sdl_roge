#ifndef IWINDOW_H
#define IWINDOW_H

#include <functional>

#include "headers.h"
#include "coords.h"

class IWindow {
 public:
  IWindow(const RectangleI& rectangle) : m_rectangle(rectangle) {}
  virtual void show(const std::function<void(Text&&, const Coord&)>& visualizator, const Coord& parentCd) = 0;
  RectangleI m_rectangle;

 protected:
};

#endif  // IWINDOW_H
