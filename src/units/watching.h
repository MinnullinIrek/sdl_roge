#pragma once

#include <memory>
#include <unordered_map>

#include "coords.h"
#include "subscriber.h"
#include "component.h"


class Map;

class IWatching : public Component {
 public:
  virtual std::unordered_map<CoordPair<int>, bool, HashFunctionCoord>& getWatchingCoords() = 0;
 protected:
  virtual void lookAround(const std::shared_ptr<Map>& map, const CoordPair<int>&) = 0;
  
};

class SimpleWatching : public IWatching, public Subscriber {
 public:
  std::unordered_map<CoordPair<int>, bool, HashFunctionCoord>& getWatchingCoords() override;

 protected:
  void notify(std::weak_ptr<Publisher> publisher) override;
  void lookAround(const std::shared_ptr<Map>& map,  const CoordPair<int>& coord) override;
 private:
  CoordPair<int> m_coord;
  std::shared_ptr<Map> m_map;
  std::unordered_map<CoordPair<int>, bool, HashFunctionCoord> m_watchingCoords;
};

