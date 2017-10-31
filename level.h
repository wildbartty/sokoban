#ifndef SOKOBAN_LEVEL
#define SOKOBAN_LEVEL
#include "player.h"
#include "sokoban.h"


int setup_level(level*);
int kill_level(level*);
void print_level(level*);
int move_player_rel(level*,int);
int load_level_string(char*,level*);

#endif
