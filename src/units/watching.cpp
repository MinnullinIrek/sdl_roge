#include "watching.h"

#include <assert.h>

#include "cell.h"
#include "map.h"
#include "mover.h"

void SimpleWatching::lookAround(const std::shared_ptr<Map>& map, const CoordPair<int>& coord, bool see) {
  auto watchingLength = 10;  // m_chars->getValue(static_cast<int>(ECharTypes::perception)) / 2;
  // if (watchingLength == 0) {
  //   // throw "person is blind";
  //   watchingLength = 5;
  // }
  const auto& heroCoord = coord;

  CoordPair<int> cd = coord;
  std::initializer_list<CoordPair<int>> tempCoords{
      {-1, 1}, {-1, 0}, {-1, -1}, {0, 1}, {0, -1}, {1, 1}, {1, 0}, {1, -1}};

  auto isFar = [&heroCoord](const CoordPair<int>& lastCd, const CoordPair<int>& nextCd) -> bool {
    return ((lastCd - heroCoord).length() + 0.8 /*SF("visibilityMagic"))*/) <= (nextCd - heroCoord).length();
  };

  m_watchingCoords.clear();
  m_watchingCoords[cd] = see;
  map->setSeen(cd);

  std::list<CoordPair<int>> checkingCoords;
  checkingCoords.push_back(heroCoord);

  for (int i = 0; i < watchingLength; ++i) {
    for (auto it = checkingCoords.begin(); it != checkingCoords.end();) {
      auto wCd = *it;
      it = checkingCoords.erase(it);

      if (!map->isWall(wCd)) {
        for (const auto& ct : tempCoords) {
          auto cdTemp = wCd + ct;
          if (isFar(wCd, cdTemp)) {
            m_watchingCoords[cdTemp] = true;
            map->setSeen(cdTemp);
            if ((heroCoord - cdTemp).length() <= watchingLength) {
              checkingCoords.push_front(cdTemp);
            }
          }
        }
      }
    }
    }
 /* } else {
    m_watchingCoords.clear();
  }*/
}

void SimpleWatching::notify(std::weak_ptr<Publisher> publisher) {
  assert(publisher.lock());
  auto mover = std::dynamic_pointer_cast<IMover>(publisher.lock());
  if (mover) {
    lookAround(mover->getMap().lock(), m_lastCoord, false);
    lookAround(mover->getMap().lock(), mover->getCoord(), true);
    m_lastCoord = mover->getCoord();
  }
}

std::unordered_map<CoordPair<int>, bool, HashFunctionCoord>& SimpleWatching::getWatchingCoords() {
  return m_watchingCoords;
}