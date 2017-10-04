#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <lua.h>
#include <lauxlib.h>
#include <lualib.h>
#include "sokoban.h"
#include "level.h"
#include "printstack.h"

void print_lines(lua_State* L)
{
  int y = lua_tonumber(L,1);
  /* move(y,x); */
  /* char val; */
  /* int index = 0; */
  /* val = string[index]; */

  /* while (val != '\0') { */
  /*   addch(val); */
  /* skip: */
  /*   index++; */
  /*   val = string[index]; */
  /*   if (val == '\n') { */
  /*     move(++y,x); */
  /*     goto skip; */
  /*   } */
  /* } */
}

int file_to_string(char** dest, const char* file) {
  FILE* fp = fopen(file, "r");
  int file_size;
  char* buf;
  char* tmp;
  fseek(fp,0,SEEK_END);
  file_size = ftell(fp);
  rewind(fp);
  buf = malloc(sizeof(char) * file_size + 1);
  if (!dest) {goto end;}
  fread(buf,sizeof(char),file_size+1,fp);
  fclose(fp);
  *dest = (char*) realloc(*dest,sizeof(char) * file_size + 1);
  strcpy(*dest,buf);
 end:
  free(buf);
  return 0;
}

int control_loop(level* state) {
  print_level(state);
  refresh();
  int cur_ch = 0;
  while (1) {
    if (cur_ch == 'q') { goto end; }
    if (!move_player_rel(state, cur_ch)) {
      print_level(state);
      refresh();
    }
    cur_ch = getch();
  }

 end: return 0;
}


int main () {
  level bob;
  setup_level(&bob);
  print_level(&bob);
  kill_level(&bob);
  return 0;
}
