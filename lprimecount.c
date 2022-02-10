#include<string.h>

#include"lua.h"
#include"lauxlib.h"

#include"primecount.h"

#define MYNAME "primecount"
#define MYVERSION \
  MYNAME " library for " LUA_VERSION " / Feb 2022 / " \
  "using primecount " PRIMECOUNT_VERSION

static int F_pi(lua_State *L)
{
  lua_Integer n;
  n = luaL_checkinteger(L,1);
  lua_pushinteger(L,primecount_pi(n));
  return 1;
}

/*Is this right?*/

static int F_pi_str(lua_State *L)
{
  int n;
  size_t len;
  char *x;
  x = (char*)luaL_checkstring(L,1);
  len = strlen(x);
  char res[len];
  n = primecount_pi_str(x,res,len);
  lua_pushinteger(L,n);
  if (n+1)
    lua_pushstring(L,res);
  else
    lua_pushliteral(L,"");
  return 2;
}

static int F_nth_prime(lua_State *L)
{
  lua_Integer n;
  n = luaL_checkinteger(L,1);
  lua_pushinteger(L,primecount_nth_prime(n));
  return 1;
}

static int F_phi(lua_State *L)
{
  lua_Integer n, a;
  n = luaL_checkinteger(L,1);
  a = luaL_checkinteger(L,2);
  lua_pushinteger(L,primecount_phi(n,a));
  return 1;
}

static const struct luaL_Reg L_primecount [] = 
{
  {"pi", F_pi},
  {"pi_str", F_pi_str},
  {"nth_prime", F_nth_prime},
  {"phi", F_phi},   
  {NULL, NULL}
};

LUALIB_API int luaopen_primecount(lua_State *L)
{
  luaL_newlib(L,L_primecount);
  lua_pushliteral(L,"version");
  lua_pushliteral(L,MYVERSION);
  lua_settable(L,-3);
  return 1;
}