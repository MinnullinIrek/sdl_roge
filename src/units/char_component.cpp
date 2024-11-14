#include "char_component.h"

CharComponent::CharComponent(const std::unordered_map<int, BaseChar>& types) {
  m_chars = std::make_shared<Chars>(types);
}
