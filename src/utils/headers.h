#pragma once
#ifndef HEADERS_H
#define HEADERS_S

#include <cstdint>
#include <string>

enum class ERelationType { none, whall, neutral, enemy, ally, compnion };
enum class EAction { none, left, right, up, down, inventory, map, undo, charAction, effect };

using TranslatableText = std::string;
using Description = std::string;
using Resource = std::string;
using SymbIdentifier = char;

struct Name {
  Description name;
  Description description;
};

struct Color {
  Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0, uint8_t a = 255) : r(r), g(g), b(b), a(a) {}
  uint8_t r, g, b, a;
  bool operator==(const Color& c) const { return c.r == r && c.b == b && c.g == g; }
  static Color white;
  static Color black;
  static Color gray;
};

struct Identifier {
  Resource adress;
  SymbIdentifier charId = ' ';
  Color color;
  Color bgColor;
};

class ToString {
 public:
  virtual Description toString() const = 0;
};

class ToIdentifier {
 public:
  virtual Identifier toIdentifier() const = 0;
};

struct UtilConsts {
  static Identifier EmptyIdentifier;
};

struct Text {
  Text(const std::string& text = "", const Color& color = {0, 0, 0}, const Color& bgColor = {0, 0, 0})
      : m_text(text), m_color(color), m_bgColor(bgColor) {}
  std::string m_text;
  Color m_color;
  Color m_bgColor;
};

#endif  // HEADERS_H
