#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <unistd.h>

#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

int luaopen_mt(lua_State *L);

/*
 * the first is intervel,
 * the second number is  units default 1[s]
 * */

static int mt_sleep(lua_State *L) {
    lua_Number interval = luaL_checknumber(L, 1);
    lua_Number units    = luaL_optnumber(L, 2, 1);

    usleep(1000000 * interval / units);

    return 0;
}

static const luaL_reg mt_lib[] = {
    {"sleep", mt_sleep},
    {0, 0}
};

int luaopen_mt(lua_State *L) {
    luaL_register(L, "mt", mt_lib);
    return 1;
}
