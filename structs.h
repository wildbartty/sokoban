 #ifndef SOKOBAN_STRUCTS
#define SOKOBAN_STRUCTS
struct player{
    int x;
    int y;
};
typedef struct player player;

struct level {
    char* board_string; /* the raw 1d string that the level is */

    /* the next 2 variables are for bounds checking */
    int longest_line;   /* the longest line in the level file */
    int no_lines;       /* the number of lines in the level file */

    int* player;      /* the state of the player in the level */
    char** board;       /* the state of the level
                            and array that is longest_line* no lines big */
};

typedef struct level level;

#endif
