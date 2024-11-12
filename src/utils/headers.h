#pragma once
#ifndef HEADERS_H
#define HEADERS_S

#include <cstdint>
#include <string>

using TranslatableText = std::string;
using Description = std::string;
using Resource = std::string;
using SymbIdentifier = char;

struct Name {
  Description name;
  Description description;
};

struct Color {
  Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) : r(r), g(g), b(b) {}
  uint8_t r, g, b;
};

struct Identifier {
  Resource adress;
  SymbIdentifier charId;
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
