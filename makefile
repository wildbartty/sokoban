CC = gcc
SRC= main.c player.c level.c
FILES = player.o level.o
MAIN = main.o
LIBS = `pkg-config --libs --cflags ncurses lua`

%.o: %.c $(SRC)
	$(CC) -pg -Wall -c -o  $@ $< $(LIBS)

make: $(MAIN) $(FILES)
	$(CC) -o sokoban $(FILES) $(MAIN) $(LIBS)

clean:
	rm *.o sokoban
