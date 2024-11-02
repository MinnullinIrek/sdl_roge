#ifndef GAME_H
#define GAME_H

#include "game_components/component.h"
#include "game_components/entity.h"
#include "game_components/entityManager.h"

class Renderer;
class Window;
class Keyboard;

class Game {
 private:
  bool m_isRunning;
  std::shared_ptr<Window> m_window;
  std::shared_ptr<Renderer> m_renderer;
  std::shared_ptr<Keyboard> m_keyboard;

 public:
  Game(std::shared_ptr<Window> window, std::shared_ptr<Renderer> renderer);
  ~Game();
  int ticksLastFrame = 0;
  bool isRunning() const;
  void loadLevel(int levelNumber);
  void initialize(int width, int height);
  void processInput();
  void update(float dt);
  void render();
  void destroy();
};

#endif
