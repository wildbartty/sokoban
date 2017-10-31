#include "sokoban.h"
#include "structs.h"

int get_longest_line(FILE *file,level *level)
{
  char temp;
  int length = 0;
  const int start = ftell(file);
  printf("%d\n",start);
  rewind(file);
  {
    int length_temp=0;
    int nth = 0;
  lpstart:
    temp = fgetc(file);
    switch(temp) {
    case EOF:
      goto end;
    case '\n':
      length = length>length_temp ? length : length_temp;
      level->line_lengths = length_temp;
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

  level->no_lines=get_no_lines(file);

  level->longest_line = get_longest_line(file,level);
  
  level->dimension=(level->longest_line*level->no_lines+1);/* +level->no_lines; */

  level->board_string=malloc(sizeof(char)*level->dimension);

  rewind(file);
  {
    char pre = fgetc(file);
    char temp = fgetc(file);
    for(int i=0; i < level->dimension; i++) {
      int temp_int = 0;
      if (temp == '\n')
	{
	  pre = pre + 128;
	  /* mark the newlines */
	  level->board_string[i]=pre;
	  pre = fgetc(file);
	  temp = fgetc(file);
	  continue;
	}
      if (temp == EOF)
	{
	  continue;
	}
      level->board_string[i]=pre;
      pre = temp;
      temp = fgetc(file);
    }
    level->board_string[level->dimension] = '\0';
    fclose(file);
  }
  return 0;
}

char level_at(level* state, int x, int y){
  return 0;
}

char ilegal_characterp(char thing)
{
  char res = 0;
  res = res |(thing == '#');/* a wall */
  res = res |(thing == '.');/* a empty floor tile */
  res = res |(thing == '@');/* the player */
  res = res |(thing == '%');/* a block */
  res = res |(thing == 'G');/* a block on a goal floor */
  res = res |(thing == '=');/* a goal floor */
  res = res |(thing == '\0');/* to let a level print */
  return !res;
}

void print_level(level* level)
{
  for(int i=0; i < level->dimension; i++) {
    int temp = level->board_string[i];
    char test = 0;
    if (ilegal_characterp(temp))
      {
	temp = temp - 128;
	/* mark the newlines */
	test = 1;
      }
    printf("%c",temp);
    if (test == 1) {
	test = 0;
	printf("\n");
      }
  }
}

int kill_level(level* level)
{
  free(level->board_string);
  return 0;
}

