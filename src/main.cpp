#include "SDL.h"
#include "log.h"
#include <cmath>
#include "console.h"
#include "headers.h"
#include "unit.h"


int main(int argc, char **argv) {
  ConsoleGame game;
  Color c(255, 0, 0);
  Color cb(0, 0, 0);

  IUnit unit;
  unit.color = c;
  unit.bgColor = cb;
  unit.charId = '@';
  unit.name = "name";
  unit.description = "description";



  game.fill(1, 10, unit.charId, unit.color, unit.bgColor);
  game.DrawBuffer();

  return 0;
}
