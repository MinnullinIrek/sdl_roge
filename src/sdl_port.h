#pragma once

#include <iostream>

#include "SDL.h"
#include "SDL_render.h"
#include "abstract_port.h"

class SdlPort final : public IPort {
 public:
  SdlPort();
  ~SdlPort();
  void update(const Time dt) override;
  void drawBorder(const RectangleI& borders, std::string_view headerText = "") override;
  void render() override;
  void init(const WindowSize w = 800, const WindowSize h = 800) override;
  WindowSize getWidth() override;
  WindowSize getHeight() override;
  void drawText(const WindowSize x, const WindowSize y) override;

 protected:
 private:
  WindowSize _width = 800;
  WindowSize _height = 600;

  SDL_Window* window = nullptr;
  SDL_Renderer* renderer = nullptr;
};
