#ifndef COMPAT_H
#define COMPAT_H

#if !defined(LUA_VERSION_NUM) || LUA_VERSION_NUM==501

#ifndef _WIN32
#pragma GCC visibility push(hidden)
#endif

void luasocket_setfuncs (lua_State *L, const luaL_Reg *l, int nup);
void *luasocket_testudata ( lua_State *L, int arg, const char *tname);

#ifndef _WIN32
#pragma GCC visibility pop
#endif

#define luaL_setfuncs luasocket_setfuncs
#define luaL_testudata luasocket_testudata

#endif

/* Luau does not have continuation-based pcall; map to plain pcall */
#ifndef LUA_VERSION_NUM
typedef int lua_KContext;
#define lua_pcallk(L, na, nr, err, ctx, cont) lua_pcall(L, na, nr, err)
#endif

#endif
