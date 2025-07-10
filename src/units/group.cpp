#include "group.h"
#include <assert.h>

#include "../game_struct.h"
#include "log.h"
#include "lua_class.h"

std::unordered_map<int, std::unordered_map<ERelationType, std::unordered_set<int>>> Group::commands = {
    {0, {{ERelationType::ally, {0}}}}};

std::map<CoordPair<int>, std::function<void(std::shared_ptr<CellHolder> att, std::shared_ptr<CellHolder> def)>>
    Group::relations = {
        {

            {
                Group::EGroupId::hero, Group::EGroupId::whall,
            },
            [](std::shared_ptr<CellHolder> att, std::shared_ptr<CellHolder> def) {

              auto L = gameStruct.m_luaClass->L;
              lua_getglobal(L, "G");
              // lua_getglobal(L, "strikeWhall");
              

              auto typeLua = lua_typename(L, 0);
              assert(lua_istable(L, 0));

              lua_getfield(L, 0, "strikeWhall");
              
              typeLua = lua_typename(L, 0);
              assert(lua_isfunction(L, 0));



              lua_call(L, 0, 0);
            }

        },
};

ERelationType Group::getRelationship(int command) {
  for (const auto& relPair : commands.at(m_currentCommand)) {
    if (relPair.second.contains(command)) {
      return relPair.first;
    }
  }
  return ERelationType::none;
}

void Group::doAction(std::shared_ptr<CellHolder> att, std::shared_ptr<CellHolder> def) {
  auto attCom = att->owner->GetComponent<Group>()->m_currentCommand;
  auto defCom = def->owner->GetComponent<Group>()->m_currentCommand;
  auto func = relations.at({attCom, defCom});
  func(att, def);
}

Group::Group(int group) : m_currentCommand(group) {}
