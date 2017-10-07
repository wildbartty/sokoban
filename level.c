#include "sokoban.h"
#include "structs.h"

int get_longest_line(FILE *file)
{
  rewind(file);

  char temp;
  int length = 0;
  {
    int length_temp=0;
  lpstart:
    temp = fgetc(file);
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

int get_no_lines(FILE* file)
{
  rewind(file);

  char temp;
  int length = 0;
  {
  lpstart:
    temp = fgetc(file);
    switch(temp) {
    case EOF:
      goto end;
    case '\n':
      length++;
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
  level->longest_line = get_longest_line(file);
  printf("longest line %d\n",level->longest_line);

  level->no_lines=get_no_lines(file);
  printf("nolines %d\n",level->no_lines);
  
  level->dimension=level->longest_line*level->no_lines+level->no_lines;

  level->board_string=malloc(sizeof(char)*level->dimension);

  rewind(file);

  for(int i=0; i < level->dimension; i++) {
    char temp = fgetc(file);
    if (temp != EOF) 
      level->board_string[i]=temp;
  }
  fclose(file);
  return 0;
}

int kill_level(level* level)
{
  free(level->board_string);
  return 0;
}

