CC = gcc
IN = src/main.c src/game/*.c
OUT = bin/out
# LIBS = -lncurses
CFLAGS = -Wall

$(OUT): $(IN)
	$(CC) -o $(OUT) $(LIBS) $(IN) $(CFLAGS)
