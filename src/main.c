#include <stdio.h>
#include <stdlib.h>
#include "game/game.h"

int main(int argc, char *argv[]) {
	struct player* player = InitGame();

	puts(DescribePlayerPos(*player));
	MovePlayer(player, NORTH);
	puts(DescribePlayerPos(*player));

	DestroyGame(&player);
	return EXIT_SUCCESS;
}
