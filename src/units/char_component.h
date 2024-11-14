#pragma once
#include "base_char.h"
#include "component.h"

class CharComponent : public Component, public Subscriber {
 public:
  CharComponent(const std::unordered_map<int, BaseChar>& types);

  std::shared_ptr<Chars> m_chars;
};
