#include "sokoban.h"
#include "structs.h"

int get_longest_line(FILE *file, level* level)
{
  rewind(file);

  char temp;
  int length = 0;
  {
    int length_temp=0;
  lpstart:
    temp = fgetc(file);
    if (temp != EOF)
      printf("%c", temp);
    switch(temp) {
    case EOF:
      goto end;
    case '\n':
      length = length>length_temp ? temp : length_temp;
      length_temp=0;
      break;
    default:
      length_temp++;
      break;
    }
    goto lpstart;
  }
 end:
  return length;
}

int load_level_string(char* name, level* level)
{
  FILE *file;
  file = fopen(name,"r");
  int length = 0;
  if (length >=0)
  level->longest_line = get_longest_line(file, level);
  fclose(file);
  printf("%d",level->longest_line);
  return 0;
}

