#ifndef ACTOR_STRATEGY_H
#define ACTOR_STRATEGY_H

#include <optional>
#include <memory>

#include "../headers.h"

class Command;

class ActorStrategy {
 public:
  bool executeKey(EAction action);
  virtual ~ActorStrategy() = default;

 protected:
  virtual std::optional<std::shared_ptr<Command>> doKey(EAction action) = 0;
};

#endif  // ACTOR_STRATEGY_H
