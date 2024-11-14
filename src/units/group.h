#pragma once
#include <functional>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "cell_holder.h"
#include "component.h"
#include "coords.h"
#include "headers.h"

class Group : public Component {
 public:
  Group(int group);
  ERelationType getRelationship(int command);
  void doAction(std::shared_ptr<CellHolder> att, std::shared_ptr<CellHolder> def);
  int m_currentCommand = 0;
  static std::unordered_map<int, std::unordered_map<ERelationType, std::unordered_set<int>>> commands;
  static std::map<CoordPair<int>, std::function<void(std::shared_ptr<CellHolder>, std::shared_ptr<CellHolder>)>>
      relations;

  enum EGroupId {
      hero,
      whall,
    
  };
};
