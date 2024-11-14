#include "map.h"

#include <assert.h>

#include "cell.h"
// #include "cell_holder.h"
#include "group.h"

Map::Map(const CoordPair<int>& size) : m_size(size) {}

MapIterator Map::begin() { return MapIterator(m_cells.begin()); }

MapIterator Map::end() { return MapIterator(m_cells.end()); }

void Map::setCellHolder(const CoordPair<int>& coord, std::shared_ptr<CellHolder> holder) {
  assert(coord < m_size);
  if (!m_cells.contains(coord)) {
    m_cells.emplace(coord, new Cell());
  }

  m_cells[coord]->setHolder(holder);

  emit();
}

std::shared_ptr<Cell> Map::getCell(const CoordPair<int>& cd) {
  assert(cd < m_size);
  if (!m_cells.contains(cd)) {
    return nullptr;
  }
  return m_cells[cd];
}

Coord Map::moveUnitFromTo(const CoordPair<int>& currentPos, const CoordPair<int>& nextPos) {
  assert(nextPos < m_size);
  Coord result = currentPos;
  if (nextPos < m_size) {
    auto cell1 = getCellOrCreate(currentPos);
    auto cell2 = getCellOrCreate(nextPos);
    auto unit1 = cell1->getHolder();
    auto unit2 = cell2->getHolder();
    assert(unit1);
    if (unit2) {
      unit1->owner->GetComponent<Group>()->doAction(unit1, unit2);
    } else {
      cell2->setHolder(unit1);
      cell1->setHolder(nullptr);
      result = nextPos;
    }
  }
  if (result != currentPos) {
    emit();
  }
  return result;
}

std::shared_ptr<Cell> Map::getCellOrCreate(const CoordPair<int>& cd) {
  if (!m_cells.contains(cd)) {
    m_cells.emplace(cd, std::make_shared<Cell>());
  }
  return m_cells.at(cd);
}

void Map::setSeen(const CoordPair<int>& cd) {
  if (cd < m_size) {
    if (!m_cells.contains(cd)) {
      m_cells.emplace(cd, std::make_shared<Cell>());
    }
    m_cells.at(cd)->setSeen(true);
  }
}

bool Map::isWall(const CoordPair<int>& cd) const {
  if (m_cells.contains(cd)) {
    auto cell = m_cells.at(cd);
    return false;  // cell && cell->isWall();
  }

  return false;
}

Identifier Map::getIdentifier(const Coord& cd) {
  if (m_cells.contains(cd)) {
    auto cell = m_cells.at(cd);
    if (cell) {
      return cell->toIdentifier();  // cell && cell->isWall();
    }
  }
  static Identifier empty{"", ' ', Color{0, 0, 0}, Color{0, 0, 0}};
  return empty;
}
