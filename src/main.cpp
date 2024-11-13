#include <cmath>

#include "SDL.h"
#include "actor/actor.h"
#include "actor/actor_strategy_map.h"
#include "console.h"
#include "game_struct.h"
#include "headers.h"
#include "keyboard.h"
#include "log.h"
#include "log_window.h"
#include "main_window.h"
#include "map.h"
#include "map_window.h"
#include "mover.h"
#include "unit.h"
#include "visualization_unit.h"
#include "watching.h"
#include "window.h"

void initMapState(MainWindow& mainWindow) {
  gameStruct.actor->setStrategy(gameStruct.m_strategies.at(fsm_cxx::GameState::MapState).get());
  // gameStruct.actor->setStrategy(gameStruct.m_strategies[fsm_cxx::GameState::MapState].get());
  mainWindow.setCurrent(EMainWindows::emap);
}

void gameLoop(
    MainWindow& mw,
    ConsoleGame& game,
    std::shared_ptr<IWindow> logWindow,
    std::shared_ptr<IWindow> mapWindow,
    float fps = 60) {
  auto l = [&game](Text&& t, const Coord& cd) { game.DrawWords(cd.x, cd.y, t.m_text, t.m_color, t.m_bgColor); };

  auto time = clock();
  while (true) {
    if (clock() - time > 1 / fps) {
      mw.show(l, {0, 0});
      game.DrawFrame(logWindow->m_rectangle, FrameType::SINGLE, Color{125, 125, 125}, Color{0, 0, 0});
      game.DrawFrame(mapWindow->m_rectangle, FrameType::SINGLE, Color{125, 125, 125}, Color{0, 0, 0});

      game.DrawBuffer();

      auto act = game.getPressed();
      if (act != EAction::none) {
        gameStruct.keyboard->setKey(act, true);
      }
    }
    time = clock();
  }
}

int main(int argc, char** argv) {
  ConsoleGame game;
  Color c(255, 0, 0);
  Color cb(0, 0, 0);

  EntityManager manager;
  Entity* player = new Entity(manager);

  player->AddComponent<IUnit>();
  std::shared_ptr<IUnit> unit = player->GetComponent<IUnit>();
  //(new IUnit());

  player->addComponent<VisualizationUnit>(
      std::make_shared<VisualizationUnit>(Identifier{"", '@', {255, 255, 255}, {0, 0, 0}}));
  unit->name = "name";
  unit->description = "description";

  // unit->mover = std::make_shared<SimpleMover>();
  auto mover = std::make_shared<SimpleMover>();
  player->addComponent<IMover>(mover);

  auto watching = std::make_shared<SimpleWatching>();
  player->addComponent<IWatching>(watching);

  std::shared_ptr<Map> m(new Map({100, 100}));

  LogWindow::init({{0, 43}, {80, 80}});

  std::shared_ptr<LogWindow> logWindow = LogWindow::instance();
  std::shared_ptr<MapWindow> mapWindow = std::make_shared<MapWindow>(RectangleI{{5, 5}, {80, 40}});
  auto mo = unit->owner->GetComponent<IMover>();
  gameStruct.hero = unit;

  // unit->mover->addSubscriber(mapWindow);
  mo->changeMap(m);
  mover->addSubscriber(watching);
  mo->addSubscriber(mapWindow);

  MainWindow mw(RectangleI{{0, 0}, {80, 80}});
  mw.addWindow(EMainWindows::elog, logWindow);
  mw.addWindow(EMainWindows::emap, mapWindow);

  m->setCellHolder({2, 10}, unit);
  mo->setCoord({2, 10});

  auto mapStrategy = std::make_unique<ActorStrategyMap>();
  mapStrategy->init(
      [](const Coord& cd) { gameStruct.hero->owner->GetComponent<IMover>()->moveInDirection(cd); },
      [](const Coord& cd) { gameStruct.hero->owner->GetComponent<IMover>()->moveInDirection(cd.revert()); }

  );
  gameStruct.m_strategies[fsm_cxx::GameState::MapState] = std::move(mapStrategy);

  gameStruct.actor = std::make_shared<Actor>();
  gameStruct.keyboard = std::make_shared<Keyboard>(gameStruct.actor);

  initMapState(mw);
  LOG("first coment");
  LOG("first coment");
  LOG("first coment");
  LOG("first coment");
  LOG("first coment");
  LOG("some ", "message");
  LOG("second ", "message");

  gameLoop(mw, game, logWindow, mapWindow, 60);

 /* while (true) {
    mw.show(l, {0, 0});
    game.DrawFrame(logWindow->m_rectangle, FrameType::SINGLE, Color{125, 125, 125}, Color{0, 0, 0});
    game.DrawFrame(mapWindow->m_rectangle, FrameType::SINGLE, Color{125, 125, 125}, Color{0, 0, 0});

    game.DrawBuffer();

    auto act = game.getPressed();
    if (act != EAction::none) {
      gameStruct.keyboard->setKey(act, true);
    }
  }*/

  return 0;
}
