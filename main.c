#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include "sokoban.h"
#include "level.h"
/*
 * functions return a truthy value if they succeed
 * and it eases cleaning up if things go wrong
 */

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

int file_to_string(char** dest, const char* file) {
    FILE* fp = fopen(file, "r");
    int file_size;
    char* buf;
    char* tmp;
    fseek(fp,0,SEEK_END);
    file_size = ftell(fp);
    rewind(fp);
    buf = malloc(sizeof(char) * file_size + 1);
    if (!dest) {goto freebuf;}
    fread(buf,sizeof(char),file_size+1,fp);
    fclose(fp);
    *dest = (char*) realloc(*dest,sizeof(char) * file_size + 1);
    strcpy(*dest,buf);
    free(buf);
    return 1;
freebuf:
    free(buf);
    return 0;
}

int control_loop(level* state) {
    int cur_ch;
    while (1) {
        cur_ch = getch();
        if (cur_ch == 'q') goto end;
        if (move_player_rel(state, cur_ch)) {
            fprintf(stderr, "%c \t %d %d\t \n", cur_ch, state->player.y, state->player.x);
            print_level(state);
            refresh();
        }
    }
end: return 1;
}


int main () {
    initscr();
    clear();
    noecho();
    cbreak();
    keypad(stdscr,TRUE);
    level bob;
    setup_level(&bob);
    control_loop(&bob);
    endwin();
    kill_level(&bob);
    return 0;
}
