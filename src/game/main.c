#include "./includes.h"

typedef struct map_node* map_node;
typedef struct player*	 player;


map_node newNode ( const char* description, const char* name) {
	map_node p = malloc(sizeof(struct map_node));
	strcpy( p->description, description);
	strcpy( p->name, name);

	for (int i = 0; i < 4; i++)
		p->ajacent_nodes[i] = NULL;

	return p;
}

player newPlayer (map_node initial_pos) {
	player p = malloc(sizeof(struct player));
	p->position = initial_pos;
	return p;
}


void linkNodes (map_node node1, map_node node2, int direction)
{
	node1->ajacent_nodes[direction] = node2;
	node2->ajacent_nodes[(direction+2)%4] = node1;

}
// map node API
char* describe(map_node n)
{
	static char s[150];
	sprintf(s, "you are at %s, %s", n->name, n->description);
	return s;
}

// player API
void MovePlayer (player p, int direction)
{
	map_node pos = p->position, next_pos = pos->ajacent_nodes[direction];
	p->position = next_pos == NULL ? pos: next_pos;
}

char* DescribePlayerPos (struct player p)
{
	return describe ( p.position );
}

//game API
/*
instead of hardcoding the initialization
that will be spagetti to type I should implement 
a static format like json or toml SO
we would need to interact with a json (or other 
data storing file format) parsing library :P
 */

player InitGame()
{
	DPRINT("initializing game...");
	DPRINT("\tinitializing rooms...");
	map_node map = newNode("this room is big and empty", "room one");
	linkNodes(map, newNode("this room is not really big", "room two"), NORTH);
	linkNodes(map->ajacent_nodes[NORTH], newNode("another empty room og", "room three"), WEST);

	DPRINT("\tinitializing player...");
	player player = newPlayer(map);

	DPRINT("\tdone");
	return player;
}

void crawlAndDestroy(map_node m)
{
	if(!m || m->v_free) return;
	m->v_free = true;
	for(int i = 0; i<4; i++)
{
		crawlAndDestroy(m->ajacent_nodes[i]);
	}
	free(m);
}

void DestroyGame(player* p)
{
	DPRINT("freeing memmory...");
	map_node map = (*p)->position;
	DPRINT("\tfreeing map memmory...");
	crawlAndDestroy(map);
	DPRINT("\tfreeing player...");
	free(*p);
}
