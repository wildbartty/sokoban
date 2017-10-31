#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "sokoban.h"
#include "level.h"

int main(int argc, char** argv)
{
  level foo;
  load_level_string("first.level",&foo);
  print_level(&foo);
  kill_level(&foo);
  return 0;
}
