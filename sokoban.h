#include "structs.h"
#include "level.h"
#include "player.h"
#include <lua.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>
#include <lualib.h>
#include <lauxlib.h>

int file_to_string(lua_State*,char**,const char*);
