#include "map.h"

#include <assert.h>

#include "cell.h"
// #include "cell_holder.h"

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
  return m_cells[cd];
}

bool Map::moveUnitFromTo(const CoordPair<int>& currentPos, const CoordPair<int>& nextPos) {
  assert(nextPos < m_size);
  bool result = false;
  if (nextPos < m_size) {
    auto& cell1 = m_cells.at(currentPos);
    auto& cell2 = m_cells.at(nextPos);
    auto unit1 = cell1->getHolder();
    auto unit2 = cell2->getHolder();
    assert(unit1);
    //if (unit2) {
    //  auto interactor = unit1->getInteractor();
    //  assert(interactor);
    //  interactor->interact(unit1, unit2);
    //} else {
      //auto unit = std::dynamic_pointer_cast<Unit>(unit1);
      /*if (unit) {
        auto mover = unit->getMover();
        mover->move(unit, cell2);
      }*/
      cell2->setHolder(unit1);
      cell1->setHolder(nullptr);
      result = true;
    //}
  }
  if (result) {
    emit();
  }
  return result;
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