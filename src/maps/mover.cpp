#include "mover.h"

#include <assert.h>

#include "cell.h"
#include "map.h"

void SimpleMover::moveInDirection(const CoordPair<int>& coord) {
  setCoord(m_map->moveUnitFromTo(m_coord, m_coord + coord));
}
void SimpleMover::setCoord(const CoordPair<int>& currentPos) {
  if (m_coord != currentPos) {
    m_coord = currentPos;
    emit();
  }
}
const CoordPair<int>& SimpleMover::getCoord() const { return m_coord; }
std::weak_ptr<Map> SimpleMover::getMap() { return m_map; }
void SimpleMover::changeMap(std::weak_ptr<Map> map) {
  m_map = map.lock();
  emit();
}
