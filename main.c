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

void print_lines(int y,int x,const char* string) {
  move(y,x);
  char val;
  int index = 0;
  val = string[index];

  while (val != '\0') {
    addch(val);
  skip:
    index++;
    val = string[index];
    if (val == '\n') {
      move(++y,x);
      goto skip;
    }
  }
}

int file_to_string(lua_State* L, char** dest, const char* file) {
 /*  FILE* fp = fopen(file, "r"); */
 /*  int file_size; */
 /*  char* buf; */
 /*  char* tmp; */
 /*  fseek(fp,0,SEEK_END); */
 /*  file_size = ftell(fp); */
 /*  rewind(fp); */
 /*  buf = malloc(sizeof(char) * file_size + 1); */
 /*  if (!dest) {goto freebuf;} */
 /*  fread(buf,sizeof(char),file_size+1,fp); */
 /*  fclose(fp); */
 /*  *dest = (char*) realloc(*dest,sizeof(char) * file_size + 1); */
 /*  strcpy(*dest,buf); */
 /*  free(buf); */
 /*  return 0; */
 /* freebuf: */
 /*  free(buf); */
 /*  return 1; */
  lua_getglobal(L,"load_level"); /* stack: .. file func */
  /* print_stack(L); */
  lua_pushstring(L,file); /* stack: .. file */
  /* print_stack(L); */
  lua_pcall(L,1,1,0); /* stack: .. level */
  /* print_stack(L); */
  const char* val = lua_tostring(L,-1);
  strcpy(dest,val);
  lua_pop(L,-1);
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
  lua_State *L= luaL_newstate();
  luaL_openlibs(L);
  luaL_dofile(L,"file.lua");
  /* initscr(); */
  /* clear(); */
  /* noecho(); */
  /* cbreak(); */
  /* keypad(stdscr,TRUE); */
  /* level bob; */
  /* setup_level(&bob,L); */
  /* control_loop(&bob); */
  /* endwin(); */
  /* kill_level(&bob); */
  char* test_string;
  test_string = malloc(sizeof(char)*400);
  file_to_string(L,test_string,"first.level");
  fprintf(stdout,"%s",test_string);
  free(test_string);
  lua_close(L);
  return 0;
}
