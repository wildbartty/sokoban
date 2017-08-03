CC = gcc
SRC= main.c player.c level.c printstack.c
FILES = player.o level.o printstack.o
MAIN = main.o
LIBS = `pkg-config --libs --cflags ncurses lua`

%.o: %.c $(SRC)
	$(CC) -g -Wall -c -o  $@ $< $(LIBS)

make: $(MAIN) $(FILES)
	$(CC) -o sokoban $(FILES) $(MAIN) $(LIBS)

clean:
	rm *.o sokoban
