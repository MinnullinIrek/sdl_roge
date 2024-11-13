#include "game.h"

#include <iostream>

#include "renderer.h"
#include "window.h"
 #include "components/transform_component.h"
#include "keyboard.h"
// #include "../lib/glm/glm.hpp"
//  #include "./constants.h"

EntityManager manager;

Game::Game(std::shared_ptr<Window> window, std::shared_ptr<Renderer> renderer)
    : m_window(window), m_renderer(renderer) {
  m_isRunning = false;
}

Game::~Game() {}

bool Game::isRunning() const { return m_isRunning; }

void Game::initialize(int width, int height) {
  m_renderer->init();

  loadLevel(0);

  m_isRunning = true;
  return;
}

void Game::loadLevel(int levelNumber) {
  Entity& newEntity(manager.AddEntity("projectile"));
  newEntity.AddComponent<TransformComponent>(0, 0, 20, 20, 32, 32, 1);
}

void Game::processInput() { 
  //auto action = m_keyboard->getAction();
  //if (action) {
  //    //do something
  //}
}

void Game::update(float dt) {


  // Clamp deltaTime to a maximum value
  dt = (dt > 0.05f) ? 0.05f : dt;

  // Sets the new ticks for the current frame to be used in the next pass
  
  manager.Update(dt);
}

void Game::render() {
  m_window->clear();
  if (manager.hasNoEntities()) {
    return;
  }

  manager.render();

  m_renderer->renderer();
}

void Game::destroy() {
  m_renderer->destroy();
  m_window->destroy();
}
