#pragma once

#include <memory>

class Map;

class IMapGenerator {
 public:
  virtual ~IMapGenerator() = default;
  virtual std::shared_ptr<Map> generateMap() = 0;
};

class SimpleMapGenerator : public IMapGenerator {
 public:
  virtual std::shared_ptr<Map> generateMap() override;
};
