#pragma once

#include <unordered_map>

#include "headers.h"
#include "subscriber.h"

enum class CharType {
  hp = 0,
  manna = 1,
  endurance = 2,

  b_strength = 3,
  b_dexterity = 4,
  b_constitution,
  b_intelligence,
  b_will,
  b_wisdom,

  s_sword,
  s_bigweapon,
  s_smallweapon,

  s_wooden,
  s_range,
  s_twoHand,

  s_silent,
  s_alert,
  s_trap,
};

using CharValue = float;

class BaseChar : public Publisher {
 public:
  BaseChar() : m_value(0), m_chType(0) {}
  BaseChar(CharValue value, int chType = 0) : m_value(value), m_chType(chType) {}

  //bool operator==(const BaseChar& bch) const { return m_value == bch.m_value; }
  //bool operator<(const BaseChar& bch) const { return m_value < bch.m_value; }
  auto operator<=>(const BaseChar& bch) const { return m_value <=> bch.m_value; }

  BaseChar& operator=(const BaseChar& bch) {
    if (m_value != bch.m_value) {
      m_value = bch.m_value;
      emit();
    }

    return *this;
  }

  BaseChar operator+(const BaseChar& bch) const { return BaseChar(m_value + bch.m_value); }
  BaseChar operator-(const BaseChar& bch) const { return BaseChar(m_value - bch.m_value); }
  BaseChar operator*(float bch) const { return BaseChar(m_value * bch); }
  BaseChar operator/(float bch) const { return BaseChar(m_value / bch); }
  operator CharValue() const { return m_value; }

 private:
  CharValue m_value;
  int m_chType = 0;
};

class Chars final : public Publisher {
 public:
  Chars() = default;
  ~Chars() = default;
  Chars(const std::unordered_map<int, BaseChar>& bch) : m_chars(bch) {

  }
  void setValue(int chType, CharValue value) { m_chars[chType] = BaseChar(value, chType); }
  CharValue getValue(int chType, CharValue defaultValue = 0) {
    if (m_chars.contains(static_cast<int>(chType))) {
      return m_chars.at(static_cast<int>(chType));
    }

    return defaultValue;
  }
  BaseChar& getChar(int chType) { return m_chars.at(chType); }

  bool exist(int chType) { return m_chars.contains(chType); }

 private:
  std::unordered_map<int, BaseChar> m_chars;
};
