#include "level.h"
#include "sokoban.h"


int check_collision(level* state, int y, int x) {
  if (state->board[x][y] == '#'){
    return 0;
  }
  else { return 1; }
}

void move_player(level* state, int y, int x) {
  if (check_collision(state,y,x)) {
    state->board[state->player[1]]
      [state->player[0]] = '.';
    state->player[0] = y;
    state->player[1] = x;
    (state->board[x])[y] = '@';
  }
}

int move_player_rel(level* state, int dir) {
  /* supports numpad arrow keys and hjkl
   * bindings */
  int y,x;
  /* 0 is y; 1 is x */
  y = state->player[0];
  x = state->player[1];
  switch(dir) {
  case '8':
  case 'k':
  case KEY_UP:
    move_player(state,y,x-1);
    return 0;
    break;
  case '2':
  case 'j':
  case KEY_DOWN:
    move_player(state,y,x+1);
    return 0;
    break;
  case '6':
  case 'l':
  case KEY_RIGHT:
    move_player(state,y+1,x);
    return 0;
    break;
  case '4':
  case 'h':
  case KEY_LEFT:
    move_player(state,y-1,x);
    return 0;
    break;
  default:
    return 1;
    break;
  }
}

