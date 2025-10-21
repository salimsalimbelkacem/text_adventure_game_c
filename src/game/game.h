#ifndef __GAME__
#define __GAME__
#include <stdbool.h>

enum { NORTH = 0, EAST, SOUTH, WEST };

struct map_node {
	char description[50];
	char name[50];
	struct map_node* ajacent_nodes[4];
	bool v_free;
};

struct player{
	struct map_node* position;
};

// map node API
char* DescribePlayerPos (struct player);
// player API
void MovePlayer (struct player*, int direction);
char* DescribePlayerPos (struct player);


struct player* InitGame();
void DestroyGame(struct player**);
#endif
