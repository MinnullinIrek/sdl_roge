#pragma once

using Action = int;

class Keyboard {
 public:
  virtual Action getAction();
};