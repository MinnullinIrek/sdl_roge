#include "keyboard.h"

// #include <sddl.h>
// #include <libtcod.hpp>
// #include "SDL_keyboard.h"
// #include "../SDL/include/SDL_keyboard.h"
// #include <SDL_keycode.h>


// #include "game_struct.h"
// #include "header.h"
 #include "actor/actor.h"
// #include "utils/visualEffect.h"


Keyboard::Keyboard(std::shared_ptr<Actor> actor) : m_actor(actor) {}

Keyboard::~Keyboard() {}

void Keyboard::setActor(std::shared_ptr<Actor> actor) { m_actor = actor; }

void Keyboard::setKey(EAction key, bool down) {
  // pushKeys(key, down);
  if (!down) {
    return;
  }
  EAction action = key;
  
  m_lastKeys = key;
  if (action != EAction::none) {
    m_actor->doKey(action);
  }
}

void Keyboard::pushKeys(EAction key, bool down) {
  if (down) {
    m_pressedKeys.emplace(key);
  } else {
    m_pressedKeys.erase(key);
  }
}
