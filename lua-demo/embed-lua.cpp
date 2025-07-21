// sudo apt-get install liblua5.4-dev
extern "C"
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

int main()
{
    lua_State *L = luaL_newstate(); // Create Lua state
    luaL_openlibs(L);               // Load Lua libraries

    luaL_dostring(L, "print('Hello from Lua!')");

    lua_close(L); // Close Lua state
    return 0;
}

// to build
// g++ main.cpp -o main -llua5.4