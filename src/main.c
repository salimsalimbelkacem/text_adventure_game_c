#include <stdlib.h>
#include <stdio.h>
#include "game/game.h"
#include "./debug.h"
#include "parser/parser.h"

struct player* Player;

void gameLoop();

int main(int argc, char *argv[]) {
	Player = InitGame();

	gameLoop();

	DestroyGame(&Player);
	return EXIT_SUCCESS;
}

void gameLoop(){
	char  input[50];
	char* message = NULL;
	
	while(true){
		printf("\n> ");
		if(fgets(input, 50, stdin)==NULL) break;

		message = Parse(input);
		if(message == NULL) break;
		puts(message);

		DPRINT("freeing message buffer...");
		free(message); message = NULL;
		DPRINT(message);

	}
	puts("\ngoodbye");
}
