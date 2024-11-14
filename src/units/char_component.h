#pragma once
#include "base_char.h"
#include "component.h"
#include "subscriber.h"

class Chars;

class CharComponent : public Component, public Subscriber {
 public:
  CharComponent(const std::unordered_map<int, BaseChar>& types) { m_chars = std::make_shared<Chars>(types); };

  std::shared_ptr<Chars> m_chars;
};
