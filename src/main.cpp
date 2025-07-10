#include <filesystem>
#include <iostream>

#include "SDL.h"

int main(int argc, char** argv) {
  // Инициализация SDL

  return 0;
}

void sdl_drw_line() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cerr << "Ошибка инициализации SDL: " << SDL_GetError() << std::endl;
    return;
  }

  // Создание окна
  SDL_Window* window = SDL_CreateWindow(
      "SDL3 Рисование Линии",  // Заголовок окна
      800,  // Ширина окна
      600,  // Высота окна
      SDL_WINDOW_RESIZABLE  // Флаги окна
  );

  if (!window) {
    std::cerr << "Ошибка создания окна: " << SDL_GetError() << std::endl;
    SDL_Quit();
    return;
  }

  // Создание рендерера
  SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
  if (!renderer) {
    std::cerr << "Ошибка создания рендерера: " << SDL_GetError() << std::endl;
    SDL_DestroyWindow(window);
    SDL_Quit();
    return;
  }

  // Цикл обработки событий
  bool running = true;
  SDL_Event event;

  while (running) {
    // Обработка событий
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        running = false;
      }
    }

    // Очистка экрана (заливка чёрным цветом)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Установка цвета для рисования линии (белый цвет)
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Рисование линии (от точки (100, 100) до точки (700, 500))
    SDL_RenderLine(renderer, 100, 100, 700, 500);

    // Отображение содержимого рендерера на экран
    SDL_RenderPresent(renderer);
  }

  // Освобождение ресурсов
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}
