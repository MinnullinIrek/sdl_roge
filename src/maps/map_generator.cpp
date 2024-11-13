#include "map_generator.h"

#include <string>

#include "map.h"
#include "cell_holder.h"

std::shared_ptr<Map> SimpleMapGenerator::generateMap() {
  std::shared_ptr<Map> map = std::make_shared<Map>(Coord{100, 100});

  std::string mp =
      "********************************************************************************\n"
      "*       *                                                                      *\n"
      "*       *                                                                      *\n"
      "*       *                                                                      *\n"
      "*       *                                                                      *\n"
      "*       *                                                                      *\n"
      "*         * * *****************                                                *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*       *************************                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*         *                                                                    *\n"
      "*         *                                                                    *\n"
      "*         *                                                                    *\n"
      "*         *                                                                    *\n"
      "*         *                                                                    *\n"
      "*         *                                                                    *\n"
      "*         ******************************                                       *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                     *****                                                    *\n"
      "*                     *   *                                                    *\n"
      "*                        *                                                     *\n"
      "*                       *   **                                                 *\n"
      "*                       ******                                                 *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "*                                                                              *\n"
      "********************************************************************************\n";
  int x = 0;
  int y = 0;
  for (const auto& ch : mp) {
    if (ch == '\n') {
      ++y;
      x = 0;
      continue;
    }
    ++x;
    if (ch == '*') {
      map->setCellHolder({x, y}, createWhall());
    }
  }
  return map;
}
