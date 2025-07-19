#pragma once

#include <iostream>

#include "SDL.h"
#include "abstract_event_port.h"

class EventSdlPort final : public IEventPort {
 public:
  EventSdlPort();
  ~EventSdlPort();
  EventType checkEvent() override;

 private:
  SDL_Event event;
};
