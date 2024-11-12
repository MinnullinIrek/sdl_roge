#ifndef MAP_H
#define MAP_H

#include <memory>

#include <unordered_map>

#include "coords.h"
#include "subscriber.h"


class Cell;
class CellHolder;

class MapIterator {
 public:
  MapIterator(const std::unordered_map<CoordPair<int>, std::shared_ptr<Cell>>::iterator& it) : cellIterator(it) {}
  MapIterator& operator++() {
    ++cellIterator;
    return *this;
  }

  MapIterator& operator--() {
    --cellIterator;
    return *this;
  }

  const std::pair<CoordPair<int>, std::shared_ptr<Cell>>& operator*() { return *cellIterator; }
  bool operator!=(const MapIterator& it) const { return cellIterator != it.cellIterator; }

 private:
  std::unordered_map<CoordPair<int>, std::shared_ptr<Cell>>::iterator cellIterator;
};



class Map : public Publisher {
 public:
  Map(const CoordPair<int>& size);
  ~Map() = default;

  void setCellHolder(const CoordPair<int>& coord, std::shared_ptr<CellHolder> holder);
  MapIterator begin();
  MapIterator end();
  std::shared_ptr<Cell> getCell(const CoordPair<int>& cd);
  bool moveUnitFromTo(const CoordPair<int>& currentPos, const CoordPair<int>& nextPos);
  void setSeen(const CoordPair<int>&);
  bool isWall(const CoordPair<int>& cd) const;
  Identifier getIdentifier(const Coord& cd);

 protected:
  CoordPair<int> m_size;
  std::unordered_map<CoordPair<int>, std::shared_ptr<Cell>, HashFunctionCoord> m_cells;
};

#endif  // MAP_H
