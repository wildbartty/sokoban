#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "sokoban.h"
#include "level.h"
#include "printstack.h"

int main(int argc, char** argv)
{
  level foo;
  load_level_string("first.level",&foo);
  printf("%s",foo.board_string);
  kill_level(&foo);
  return 0;
}
