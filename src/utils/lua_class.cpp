#include "lua_class.h"
#include "log.h"
#include <unordered_map>

static int lua_log(lua_State* L) { 
  auto logString = lua_tostring(L, -1); 
  //LOG(logString);  
  //LOG("ddsdsd");

  return 0; /* One return value */
}


LuaClass::LuaClass() : L(luaL_newstate()) {
  
}

LuaClass::~LuaClass() { lua_close(L); }

void LuaClass::init(std::string_view path) {
  //lua_register(L, "log", lua_log);
  //lua_register(L, "log", [](lua_State* L) { return 0;});
 

  //static const lua_reg Map[] = {{"dothis", myCfunc}, {NULL, NULL}};
  //luaL_register(L, "cstuff", Map);

  //luaL_dostring(L, "log(\"qwertyui\")");
  luaL_dofile(L, (std::string(path) + "/lua_scripts/init.lua").c_str());
}


void LuaClass::dostring(std::string_view code) { 
	luaL_dostring(L, code.data()); 
}

//template <LUA_FUNC Func>
//inline void LuaClass::registerFunc(std::string_view name, Func&& f) {
//	lua_register(L, name.data(), std::forward<Func>(f));
//}
