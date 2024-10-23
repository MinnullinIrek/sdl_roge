#pragma once
#ifndef HEADERS_H
#define HEADERS_S

#include <cstdint>
#include <string>

using TranslatableText = std::string;
using Description = std::string;
using Resurce = std::string;
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
  Resurce adress;
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

#endif // HEADERS_H
