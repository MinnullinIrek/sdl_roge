#pragma once
#ifndef CONSOLE_3_H
#define CONSOLE_3_H
//
#include <string_view>
#include <unordered_map>
#include <vector>
#include <assert.h>

#include "CppConsoleGameLibrary/Base4ConsoleGames.hpp"
#include "headers.h"
#include "templateCash.hpp"
#include "coords.h"

class ConsoleGame : public Game
{
  TemplateCash<uint64_t, WORD> cash;
 public:
  ConsoleGame();
  template <typename Color>
  void fill(float x, float y, char ch, Color&& color, Color&& bgColor) {
    FillCell(
        static_cast<short>(x),
        static_cast<short>(y),
        ch,
        colorToAttr(std::forward<Color>(color), std::forward<Color>(bgColor)));
  }
  void DrawBuffer();
  void DrawBufferRegion(short x, short y, short columns, short rows);
  void FillBuffer(CHAR c, WORD attr);
  bool IsKeyDown(int key);
  bool IsKeyPressed(int key);
  template <typename Color>
  void DrawFrame(float x, float y, float w, float h, FrameType type, Color&& color, Color&& bgColor) {
    Game::DrawFrame(
        (int)x, (int)y, (int)w, (int)h, type, 
        colorToAttr(std::forward<Color>(color), std::forward<Color>(bgColor)));
  }
  template <typename Color>
  void DrawWords(float x, float y, const std::string& text, Color&& color, Color&& bgColor) {
    Game::DrawWords((int)x, (int)y, text.c_str(), text.size(), colorToAttr(std::forward<Color>(color), std::forward<Color>(bgColor)));
  }

  template <typename Color>
  void DrawText(const RectangleI& r, const std::string& text, Color&& color, Color&& bgColor) {
    assert(r.height() >= 0);
    auto t = text.substr(0, r.width());
    for (int y = r.lu.y; y <= r.rd.y && !t.empty(); ++y) {
    Game::DrawWords(
        r.lu.x,
        r.lu.y,
        t.c_str(),
        r.width(),
        colorToAttr(std::forward<Color>(color), std::forward<Color>(bgColor)));
    }
  }

  void SetTitle(const char* title);
  void SetWindowSize(SHORT width, SHORT height, bool adjustBuffer);

 private:
  template <typename Color>
  WORD colorToAttr(Color&& color) {
    if (cash.exists(RGBToHex(color))) {
      return cash.get(RGBToHex(color));
    } 
    
    WORD col = F_BLACK;
    if (color.r >= 75 && color.g >= 75 && color.b >= 75) {
        col = F_GREY;
    }
    if (color.r > 150 && color.g > 150 && color.b >= 150) {
        col = F_WHITE;
    }
    if (color.r > 200 && color.g > 200 && color.b >= 200) {
        col = F_BRIGTHWHITE;
    }

    if (color.b - color.r > 50 && color.b - color.g > 50) {
        if (color.b > 125) {
        col = F_LIGHTBLUE;
        } else {
        col = F_BLUE;
        }
    }

    if (color.b - color.r > 50 && color.b - color.g > 50) {
        if (color.b > 125) {
        col = F_LIGHTBLUE;
        } else {
        col = F_BLUE;
        }
    }

    if (color.g - color.b > 50 && color.g - color.r > 50) {
        if (color.g > 125) {
        col = F_LIGHTGREEN;
        } else {
        col = F_GREEN;
        }
    }

    if (color.g - color.b < 0 && color.g - color.r < 0) {
        if (color.r > 125) {
        col = F_LIGHTPURPLE;
        } else {
        col = F_PURPLE;
        }
    }

    if (color.r - color.b < 0 && color.r - color.g < 0) {
        if (color.g > 125) {
        col = F_LIGHTAQUA;
        } else {
        col = F_AQUA;
        }
    }

    if (color.b - color.r < 0 && color.b - color.g < 0) {
        if (color.g > 125) {
        col = F_LIGHTYELLOW;
        } else {
        col = F_YELLOW;
        }
    }
    cash.put(RGBToHex(color), col);
    return col;
  }

  template <typename Color>
  WORD colorToAttr(Color&& color, Color&& bgColor) {
    return colorToAttr(std::forward<Color>(color)) | (colorToAttr(std::forward<Color>(bgColor)) >> 4);
  }

  uint64_t RGBToHex(const Color& color) {    
      return (((uint64_t)color.r & 0xff) << 16) + (((uint64_t)color.g & 0xff) << 8) + ((uint64_t)color.b & 0xff); 
  }
};

#endif  // !CONSOLE_H
