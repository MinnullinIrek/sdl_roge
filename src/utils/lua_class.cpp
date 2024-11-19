#include "lua_class.h"
#include "log.h"
#include <unordered_map>


class TestLuaClass {
 public:
  int t = 0;
  void testFunc(int i, std::string str)
  { 
	  t++;
  }
};


static const char* tname = "TestLuaClass";

static void push_Object(lua_State* L, TestLuaClass* object);
static TestLuaClass* check_Object(lua_State* L, int i);

static int l_gc(lua_State* L) {
  TestLuaClass** ud = (TestLuaClass**)luaL_checkudata(L, 1, tname);

  if (*ud) {
    // { delete *ud }
    *ud = NULL;
  }
  return 0;
}

static int l_tostring(lua_State* L) {
  TestLuaClass** ud = (TestLuaClass**)luaL_checkudata(L, 1, tname);

  lua_pushfstring(L, "%s: %p", tname, *ud);
  return 1;
}

static int l_new(lua_State* L) {
  TestLuaClass* object = new TestLuaClass;

  push_Object(L, object);
  return 1;
}

static int l_testFunc(lua_State* L) {
  TestLuaClass* object = check_Object(L, 1);
  lua_Integer int_arg = luaL_checkinteger(L, 2);
  const char* str_arg = luaL_checklstring(L, 3, NULL);
  object->testFunc(int_arg, str_arg);
  // { object->method(int_arg, str_arg) }

  return 0;
}

static const luaL_Reg lib[] = {
    // functions
    {"new", l_new},  // () -> object

    // methods
    {"method", l_testFunc},  // (object, int, string) -> none

    {NULL, NULL},
};
static lua_CFunction first_m = l_testFunc;

static void push_mt(lua_State* L) {
  if (luaL_newmetatable(L, tname)) {
    size_t m = 0;
    while (first_m != lib[m].func) 
        m++;
    lua_createtable(L, 0, 0);
    //luaL_register(L, NULL, &lib[m]);
    luaL_setfuncs(L, &lib[m], 0);
    lua_setfield(L, -2, "__index");

    lua_pushcfunction(L, l_tostring);
    lua_setfield(L, -2, "__tostring");

    lua_pushcfunction(L, l_gc);
    lua_setfield(L, -2, "__gc");

    lua_pushstring(L, tname);
    lua_setfield(L, -2, "__metatable");

    // mt.objects = setmetatable({ }, { __mode = "v" })
    lua_createtable(L, 0, 0);
    lua_createtable(L, 0, 1);
    lua_pushstring(L, "v");
    lua_setfield(L, -2, "__mode");
    lua_setmetatable(L, -2);
    lua_setfield(L, -2, "objects");
  }
}




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
