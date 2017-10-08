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
      length = length>length_temp ? length : length_temp;
      printf("%d\n",length);
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

  level->no_lines=get_no_lines(file);
  
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

char legal_character_p(char thing)
{
  char res = thing == '#';
  res = res | thing == '.';
  res = res | thing == '@';
  res = res | thing == '%';
  return res;
}

void print_level(level* level)
{
  for(int i=0; i < level->dimension; i++) {
    int temp = level->board_string[i];
    char test = 0;
    if (temp > 128)
      {
	temp = temp - 128;
	/* mark the newlines */
	test = 1;
      }
    printf("%c",temp);
    printf("%d",(temp > 128));
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

