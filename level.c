#include "sokoban.h"
int setup_level(level* state) {
    /* allocates the variables in a level state */

    state->board_string=malloc(2);
    state->longest_line = 0;
    state->no_lines = 0;
    file_to_string(&state->board_string,"first.level");
    {
        char tmp_char = 'q';
        int cur_line_len = 0;
        for (int i = 0;; i++) {
            tmp_char = state->board_string[i];
            switch (tmp_char) {
                case '@':
                    /* printf("no_lines is: %d\n"*/
                            /*"cur_line_len is: %d\n",*/
                            /* state->no_lines,*/
                            /* cur_line_len);*/

                    state->player.x=state->no_lines;
                    state->player.y=cur_line_len;
                    /* keep with the curses way */
                    cur_line_len++;
                    break;
                case '\n':
                    state->longest_line = (state->longest_line > cur_line_len)?
                                            state->longest_line : cur_line_len;
                    state->no_lines+= 1;
                    /* printf("at line %d, cur_line_len is: %d\n"*/
                            /*,state->no_lines, cur_line_len);*/
                    cur_line_len = 0;
                    break;
                case '\0':
                    /* printf("longest_line is: %d\n",state->longest_line);*/
                    goto end;
                    /* goto gets out of 3 levels of stack frames */
                default:
                    cur_line_len++;
                    break;
            }
        }
end:
        ;
    }
    {
        state->board=malloc(sizeof(void*)*state->no_lines);
        /* setup the rows */
        for (int i = 0;i<state->no_lines;i++) {
            state->board[i] = malloc(sizeof(char*) * state->no_lines);
            /* the board is no an empty array */
        }
        int cur_line=0;
        int cur_pos=0;
        /* copy the board string into the board but in 2d */
        for (int i = 0; i < strlen(state->board_string); i++) {
            char tmp = state->board_string[i];
            if (tmp == '\n') {
                cur_line++;
                cur_pos=0;
            }
            else {
                state->board[cur_line][cur_pos] = tmp;
                cur_pos++;
            }
        }
        move(state->player.y,state->player.x);
    }
    return 1;
}

int kill_level(level* state) {
        for (int i = 0;i<state->no_lines;i++) {
            free(state->board[i]);
        }
    free(state->board);
    free(state->board_string);
    return 1;
}

void print_level(level* state) {
    int y;
    y = 20;
    int cur_pos = 0;
    move(20,20);
    for (int i = 0; i < state->no_lines; i++) {
        for (int j = 0; j < state->longest_line; j++) {
            addch(state->board[i][j]);

        }
        move(++y,20);
    }
}
