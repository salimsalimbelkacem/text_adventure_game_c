#include <stdlib.h>
#include <stdio.h>
#include "game/game.h"
#include "parser/parser.h"

extern struct player* Player;

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
		fgets(input, 50, stdin);

		message = Parse(input);
		if(message == NULL) break;

		puts(message);
	}
	puts("goodbye");
}
