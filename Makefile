CC=cc
CFLAGS=-I.
DEPS = screen.h game.h
OBJ = main.o screen.o game.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

battleship: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)