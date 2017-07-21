#ifndef SOKOBAN_PLAYER
#define SOKOBAN_PLAYER
#include "level.h"
#include "sokoban.h"

typedef struct player player;
void move_player(level*,int,int);
void move_and_print_player(level*,int,int);
int move_and_print_player_rel(level*,int);
#endif
