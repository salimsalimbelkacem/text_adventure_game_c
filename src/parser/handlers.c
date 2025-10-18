#include "./includes.h"
#include "../game/game.h"
#include <stdlib.h>
#include <string.h>

extern struct player* Player;

char* Handle_go(int destination)
{
	DPRINT("registering old position...");
	struct map_node* old_pos = Player->position;

	DPRINT("moving player...");
	MovePlayer(Player, destination);
	DPRINT("old and new position is:");
	DPRINT((old_pos == Player->position)?"\tthe same":"\tnot the same");

	if (old_pos == Player->position){
		char* response = calloc(MAX_MALLOC,1);
		strcpy(response, "can't go there");
		return response;
	}
	
	DPRINT("preparing response...");
	char* response = calloc(MAX_MALLOC,1);
	char* directions[4] = {"north", "east", "south", "west"};

	DPRINT(directions[0]);
	DPRINT(directions[1]);
	DPRINT(directions[2]);
	DPRINT(directions[3]);

	snprintf(response, MAX_MALLOC, "you go %s", directions[destination]);

	return response;
}

char* Handle_see(int object)
{
	char* response = calloc(MAX_LONG_MALLOC, 1);

	response = strncpy(response, DescribePlayerPos(*Player), 200);
	return response;
}
