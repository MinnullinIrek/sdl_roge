#pragma once

#include <memory>

#include "coords.h"
#include "subscriber.h"
#include "component.h"
#include "subscriber.h"

class Map;

class IMover : public Component, public Publisher {
 public:
  virtual void moveInDirection(const CoordPair<int>&) = 0;
  virtual void setCoord(const CoordPair<int>& currentPos) = 0;
  virtual const CoordPair<int>& getCoord() const = 0;
  virtual std::weak_ptr<Map> getMap() = 0;
  virtual void changeMap(std::weak_ptr<Map> map) = 0;
};

class SimpleMover : public IMover {
 public:
  void moveInDirection(const CoordPair<int>& coord) override;
  void setCoord(const CoordPair<int>& currentPos) override;
  const CoordPair<int>& getCoord() const override;
  std::weak_ptr<Map> getMap() override;
  void changeMap(std::weak_ptr<Map> map) override;

 private:
  CoordPair<int> m_coord;
  std::shared_ptr<Map> m_map;
};

