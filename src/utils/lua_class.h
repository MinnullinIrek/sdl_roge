#pragma once
#include "lua.hpp"

#include <string_view>
#include <concepts>

template <typename T>
concept LUA_FUNC = requires(T lua_func) { 
 { lua_func(std::declval<lua_State*>()) } -> std::convertible_to<int>;
};

class LuaClass final{
 public:
  LuaClass();
  ~LuaClass();
  void init(std::string_view path);
  /*template <LUA_FUNC Func>
  void registerFunc(std::string_view name, Func &&f);*/

  template <LUA_FUNC Func>
  inline void registerFunc(std::string_view name, Func&& f) {
    lua_register(L, name.data(), std::forward<Func>(f));
  }

  void dostring(std::string_view code);

  lua_State* L;
};

