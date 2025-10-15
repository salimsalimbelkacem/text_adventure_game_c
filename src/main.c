#include <stdio.h>
#include <stdlib.h>
#include "game/game.h"
#include "parser/parser.h"

extern struct player* Player;

int main(int argc, char *argv[]) {
	Player = InitGame();
	char* message;

	DestroyGame(&Player);
	return EXIT_SUCCESS;
}
