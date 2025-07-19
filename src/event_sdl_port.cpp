#include "event_sdl_port.h"

EventSdlPort::EventSdlPort() : event{} {}
EventSdlPort::~EventSdlPort() {}
EventType EventSdlPort::checkEvent() {
  // Обработка событий
  if (SDL_PollEvent(&event)) {
    if (event.type == SDL_EVENT_QUIT) {
      return -1;
    }
  }

  return 0;
}
