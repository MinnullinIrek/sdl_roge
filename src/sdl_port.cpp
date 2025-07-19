#include "sdl_port.h"

#include "SDL_render.h"
// #include "SDL_ttf.h"

static SDL_FRect makeRect(const RectangleI& rect) {
  return SDL_FRect{
      static_cast<float>(rect.lu.x),
      static_cast<float>(rect.lu.y),
      static_cast<float>(rect.rd.x - rect.lu.x),
      static_cast<float>(rect.rd.y - rect.lu.y)};
}

SdlPort::SdlPort() {}
SdlPort ::~SdlPort() {
  // Освобождение ресурсов
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void SdlPort::init(const WindowSize w, const WindowSize h) {
  _width = w;
  _height = h;
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "SDL initialization error: " << SDL_GetError() << std::endl;
    return;
  }

  // Инициализация SDL_ttf
  // if (TTF_Init() == -1) {
  //  SDL_Log("Не удалось инициализировать SDL_ttf: %s", TTF_GetError());
  //  SDL_Quit();
  //  return;
  //}

  // Создание окна
  window = SDL_CreateWindow(
      "SDL3 draw line",  // Заголовок окна
      _width,  // Ширина окна
      _height,  // Высота окна
      SDL_WINDOW_RESIZABLE  // Флаги окна
  );

  if (!window) {
    std::cerr << "window creation error: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return;
  }

  // Создание рендерера
  renderer = SDL_CreateRenderer(window, nullptr);
  if (!renderer) {
    std::cerr << "Render creation error: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return;
  }
}

void SdlPort::update(const Time dt) {
  // Очистка экрана (заливка чёрным цветом)
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // Установка цвета для рисования линии (белый цвет)
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // Рисование линии (от точки (100, 100) до точки (700, 500))
  // SDL_RenderLine(renderer, 100, 100, 700, 500);

  // Отображение содержимого рендерера на экран
}

void SdlPort::drawBorder(const RectangleI& borders, std::string_view headerText) {
  // Установка цвета для рисования линии (белый цвет)
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // Рисование линии (от точки (100, 100) до точки (700, 500))
  // SDL_RenderLine(renderer, 100, 100, 700, 500);
  auto rect = makeRect(borders);
  SDL_RenderRect(renderer, &rect);
}

void SdlPort::render() { SDL_RenderPresent(renderer); }

WindowSize SdlPort::getWidth() { return _width; }
WindowSize SdlPort::getHeight() { return _height; }

void SdlPort::drawText(const WindowSize x, const WindowSize y) {
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  // Sdl_RenderString
}
