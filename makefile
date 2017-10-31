CC = gcc
SRC= main.c player.c level.c 
FILES = player.o level.o 
MAIN = main.o
ARCH='-march=native'
LIBS = `pkg-config --libs --cflags ncurses lua`

%.o: %.c $(SRC)
	$(CC) -Os -Wall -c -o  $@ $< $(LIBS)

make: generic arch

generic: $(MAIN) $(FILES)
	$(CC) -o sokoban $(FILES) $(MAIN) $(LIBS)

arch: $(MAIN) $(FILES)
	$(CC) $(ARCH) -Os -o sokoban.arch $(SRC) $(LIBS)

clean:
	rm *.o sokoban

main.o: main.c
player.o: player.c
level.o: level.c
