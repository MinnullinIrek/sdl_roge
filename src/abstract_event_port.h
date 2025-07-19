#pragma once

using EventType = int;

class IEventPort {
 public:
  virtual [[nodiscard]] EventType checkEvent() = 0;
};
