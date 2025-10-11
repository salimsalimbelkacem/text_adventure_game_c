CC = gcc
IN = src/main.c
OUT = bin/out
LIBS = -lncurses

$(OUT): $(IN)
	$(CC) -o $(OUT) $(LIBS) $(IN)
