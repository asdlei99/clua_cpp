#include <iostream>
#include <lua.hpp>
#include <Windows.h>
extern "C" {
#include <lua.h>  
#include <lualib.h>  
#include <lauxlib.h>  
}
static int MyLuaDLL_HelloWorld(lua_State* L)
{
	MessageBox(NULL, "Hello", "World", MB_OK);
	return 0;
}
static int MyLuaDLL_average(lua_State *L)
{
	int n = lua_gettop(L);
	double sum = 0;
	int i;
	for (i = 1; i <= n; i++)
	{
		sum += lua_tonumber(L, i);
	}
	lua_pushnumber(L, sum / n);
	lua_pushnumber(L, sum);
	return 2;
}
static const luaL_reg MyLuaDLLFunctions[] =
{
	{ "HelloWorld",MyLuaDLL_HelloWorld },
	{ "average",MyLuaDLL_average },
	{ NULL, NULL }
};
extern "C"  __declspec(dllexport) int luaopen_MyLuaDLL(lua_State* L)
{
	luaL_register(L, "MyLuaDLL", MyLuaDLLFunctions);
	return 1;
}