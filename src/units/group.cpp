#include "group.h"

std::unordered_map<int, std::unordered_map<ERelationType, std::unordered_set<int>>> Group::commands = {
    {0, {{ERelationType::ally, {0}}}}};

std::map<CoordPair<int>, std::function<void(std::shared_ptr<CellHolder> att, std::shared_ptr<CellHolder> def)>>
    Group::relations = {
        {{
             Group::EGroupId::hero,
             Group::EGroupId::whall,
         },
         [](std::shared_ptr<CellHolder> att, std::shared_ptr<CellHolder> def) {}},
};

ERelationType Group::getRelationship(int command) {
  for (const auto& relPair : commands.at(m_currentCommand)) {
    if (relPair.second.contains(command)) {
      return relPair.first;
    }
  }
}

void Group::doAction(std::shared_ptr<CellHolder> att, std::shared_ptr<CellHolder> def) {
  auto attCom = att->owner->GetComponent<Group>()->m_currentCommand;
  auto defCom = def->owner->GetComponent<Group>()->m_currentCommand;
  auto func = relations.at({attCom, defCom});
  func(att, def); 
}

Group::Group(int group) : m_currentCommand(group) {

  }
