#include <filesystem>
#include <iostream>
#include <memory>

#include "event_sdl_port.h"
#include "log.h"
#include "log_window.h"
#include "main_window.h"
#include "sdl_port.h"

// #include "utils/game_drawer.h"
constexpr float logPercent = 0.9;

int main(int argc, char** argv) {
  std::unique_ptr<IPort> port = std::make_unique<SdlPort>();
  port->init(800, 800);
  std::unique_ptr<IEventPort> eventPort = std::make_unique<EventSdlPort>();

  const Coord portSize{port->getWidth(), port->getHeight()};
  RectangleI logR{Coord{0, static_cast<decltype(portSize.y)>(logPercent * portSize.y)}, Coord{portSize.x, portSize.y}};
  LogWindow::init(logR);
  std::shared_ptr<LogWindow> logWindow = LogWindow::instance();

  MainWindow mw(RectangleI{{10, 10}, {790, 790}});
  mw.addWindow(EMainWindows::elog, logWindow);

  logWindow->Log("some log");

  while (true) {
    // port->update(1.f);
    port->drawBorder(RectangleI{{100, 100}, {500, 500}}, "window");
    logWindow->show(
        [&](Text&& text, const Coord& cd) {

        },
        logR.lu);

    port->render();
    if (eventPort->checkEvent() == -1) {
      break;
    }
  }

  return 0;
}

// void sdl_drw_line() {
//   if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//     std::cerr << " SDL initialization error: " << SDL_GetError() << std::endl;
//     return;
//   }
//
//   // Создание окна
//   SDL_Window* window = SDL_CreateWindow(
//       "SDL3 draw line",  // Заголовок окна
//       800,  // Ширина окна
//       600,  // Высота окна
//       SDL_WINDOW_RESIZABLE  // Флаги окна
//   );
//
//   if (!window) {
//     std::cerr << "Window creation error: " << SDL_GetError() << std::endl;
//     SDL_Quit();
//     return;
//   }
//
//   // Создание рендерера
//   SDL_Renderer* renderer = SDL_CreateRenderer(window, nullptr);
//   if (!renderer) {
//     std::cerr << "Render creation error: " << SDL_GetError() << std::endl;
//     SDL_DestroyWindow(window);
//     SDL_Quit();
//     return;
//   }
//
//   // Цикл обработки событий
//   bool running = true;
//   SDL_Event event;
//
//   while (running) {
//     // Обработка событий
//     while (SDL_PollEvent(&event)) {
//       if (event.type == SDL_EVENT_QUIT) {
//         running = false;
//       }
//     }
//
//     // Очистка экрана (заливка чёрным цветом)
//     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//     SDL_RenderClear(renderer);
//
//     // Установка цвета для рисования линии (белый цвет)
//     SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//
//     // Рисование линии (от точки (100, 100) до точки (700, 500))
//     SDL_RenderLine(renderer, 100, 100, 700, 500);
//
//     // Отображение содержимого рендерера на экран
//     SDL_RenderPresent(renderer);
//   }
//
//   // Освобождение ресурсов
//   SDL_DestroyRenderer(renderer);
//   SDL_DestroyWindow(window);
//   SDL_Quit();
// }
