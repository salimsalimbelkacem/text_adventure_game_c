#include <stdio.h>
#include <stdlib.h>

enum { NORTH = 0, EAST, SOUTH, WEST };

typedef struct map_node {
	char description[50];
	char name[50];
	struct map_node* ajacent_nodes[4];
}* map_node;

typedef struct player{
	map_node position;
}* player;

// map node API
map_node NewNode (map_node parent, int direction, const char descrition[50], const char name[50]) {
	map_node p = malloc(sizeof(struct map_node));
	if(parent != NULL){
		parent->ajacent_nodes[direction] = p;
	}

	return p;
}

char* Describe(map_node n){
	char s[100];

	sprintf(s, "you are at %s, %s", n->name, n->description);

	return s;
}

// player API
player NewPlayer (map_node initial_pos) {
	player p = malloc(sizeof(struct player));
	
	return p;
}

void MovePlayer(player p, int direction){
	map_node pos = p->position;
	p->position = pos->ajacent_nodes[direction];
}

/*
instead of hardcoding the initialization
that does the same thing over and over
everytime we execute the game I should implement 
a staticly typing system like json or toml SO
we would need to interact with a json parsing api :P
 */
void InitGame(){
}
