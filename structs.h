#ifndef SOKOBAN_STRUCTS
#define SOKOBAN_STRUCTS

struct player{
  int x;
  int y;
  char poses[9];
  /* The value of the squares that the player can `see' */
};

#define PLAYER_HERE        0
#define PLAYER_UP          1
#define PLAYER_UP_UP       2
#define PLAYER_RIGHT       3
#define PLAYER_RIGHT_RIGHT 4
#define PLAYER_DOWN        5
#define PLAYER_DOWN_DOWN   6
#define PLAYER_LEFT        7
#define PLAYER_LEFT_LEFT   8

typedef struct player player;

struct level {
  char* board_string; /* the raw 1d string that the level is */

  /* the next 2 variables are for bounds checking */
  int longest_line;   /* the longest line in the level file */
  int no_lines;       /* the number of lines in the level file */
  int line_lengths;
  int dimension;      /* the length of board_string to allow for newlines
			 equal to longest_line*no_lines+no_lines */
  player* player;      /* the state of the player in the level */
  char** board;       /* the state of the level
			 and array that is longest_line* no lines big */
};

typedef struct level level;

#endif
