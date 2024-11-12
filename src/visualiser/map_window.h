#ifndef MAP_WINDOW_H
#define MAP_WINDOW_H

#include <unordered_map>

#include "headers.h"
#include "subscriber.h"
#include "iwindow.h"

class MapWindow : public IWindow, public Subscriber {
 public:
  const std::string name = "mapwindow";
  MapWindow(const RectangleI& r);
  virtual void show(const std::function<void(Text&&, const Coord&)>& visualizator, const Coord& parentCd) override;

  void notify(std::weak_ptr<Publisher> publisher) override;

 private:
  std::unordered_map<Coord, Identifier, HashFunctionCoord> m_cells;
};

#endif  // MAP_WINDOW_H
