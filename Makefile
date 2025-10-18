CC = gcc
IN = src/main.c src/game/*.c src/parser/*.c
HEADERS=src/*.h src/game/*.h src/parser/*.h
OUT = bin/out
# LIBS = -lncurses
CFLAGS := -Wall
MACROS =

$(OUT): $(IN) $(HEADERS)
	@$(CC) -o $(OUT) $(LIBS) $(IN) $(CFLAGS) $(MACROS)
