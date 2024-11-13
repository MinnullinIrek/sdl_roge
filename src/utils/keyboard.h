#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <memory>
#include <set>
#include "headers.h"
class Actor;

class Keyboard {
 public:
  Keyboard(std::shared_ptr<Actor> actor);
  ~Keyboard();
  void setActor(std::shared_ptr<Actor> actor);
  void setKey(EAction key, bool down);
  void pushKeys(EAction key, bool down);
 protected:
  std::shared_ptr<Actor> m_actor;
  std::set<EAction> m_pressedKeys;
  EAction m_lastKeys = EAction::none;
};
#endif
