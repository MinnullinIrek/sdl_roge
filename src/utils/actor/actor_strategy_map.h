#ifndef ACTOR_STRATEGY_Map_H
#define ACTOR_STRATEGY_Map_H

#include <functional>
#include "../coords.h"
#include "actor_strategy.h"

class ActorStrategyMap : public ActorStrategy {
 public:
  virtual std::optional<std::shared_ptr<Command>> doKey(EAction action) override;
  void init(const std::function<void(const Coord& cd)>& action, const std::function<void(const Coord& cd)>& m_redo);
 private:
  std::function<void(const Coord& cd)> m_action;
  std::function<void(const Coord& cd)> m_redo;
};

#endif  // _Map
