#include "mover.h"

#include <assert.h>

#include "cell.h"
#include "map.h"

void SimpleMover::moveInDirection(const CoordPair<int>& coord) {
  m_map->moveUnitFromTo(m_coord, coord);
  emit();
}
void SimpleMover::setCoord(const CoordPair<int>& currentPos) {
  m_coord = currentPos;
  emit();
}
const CoordPair<int>& SimpleMover::getCoord() const { return m_coord; }
std::weak_ptr<Map> SimpleMover::getMap() { return m_map; }
void SimpleMover::changeMap(std::weak_ptr<Map> map) {
  m_map = map.lock();
  emit();
}
