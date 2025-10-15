#include "./includes.h"
#include "../game/game.h"

extern struct player* Player;

char* Handle_go(int destination)
{
	DPRINT("registering old position...");
	struct map_node* old_pos = Player->position;

	DPRINT("moving player...");
	MovePlayer(Player, destination);
	DPRINT("old and new position is:");
	DPRINT((old_pos == Player->position)?"\tthe same":"\tnot the same");

	if (old_pos == Player->position) return "can't go there";
	
	DPRINT("preparing response...");
	char* response = calloc(12,1);
	char* directions[4] = {"north", "east", "south", "west"};

	DPRINT(directions[0]);
	DPRINT(directions[1]);
	DPRINT(directions[2]);
	DPRINT(directions[3]);

	sprintf(response, "you go %s", directions[destination]);

	return response;
}

char* Handle_see(int object)
{
	return Describe(Player->position);
}
