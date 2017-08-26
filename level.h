#ifndef SOKOBAN_LEVEL
#define SOKOBAN_LEVEL
#include "player.h"
#include "sokoban.h"


int setup_level(level*,lua_State*);
int kill_level(level*);
void print_level(level*);
int move_player_rel(level*,int);

#endif
