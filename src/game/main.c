#include "./includes.h"
#include "./game.h"

typedef struct map_node* map_node;
typedef struct player*	 player;

map_node newNode ( const char description[50], const char name[50]) {
	map_node p = malloc(sizeof(struct map_node));
	strcpy( p->description, description);
	strcpy( p->name, name);
	return p;
}

player newPlayer (map_node initial_pos) {
	player p = malloc(sizeof(struct player));
	p->position = initial_pos;
	return p;
}

// map node API
char* Describe(map_node n){
	char* s = malloc(100);
	sprintf(s, "you are at %s, %s", n->name, n->description);
	return s;
}

// player API
void MovePlayer (player p, int direction){
	map_node pos = p->position;
	p->position = pos->ajacent_nodes[direction];
}

char* DescribePlayerPos (struct player p){
	return Describe ( p.position );
}

/*
instead of hardcoding the initialization
that will be spagetti to type I should implement 
a staticly typing system like json or toml SO
we would need to interact with a json (or other 
data storing file format) parsing library :P
 */
player InitGame(){
	puts("initializing rooms...");
	map_node map = newNode("this room is big and empty", "room one");
	map->ajacent_nodes[NORTH] = newNode("this room is not really big", "room two");

	puts("initializing player...");
	player player = newPlayer(map);

	puts("done");
	return player;
}

void crawlAndDestroy(map_node m);

void DestroyGame(player* p){
	map_node map = (*p)->position;
	crawlAndDestroy(map);
	free(*p);
}

void crawlAndDestroy(map_node m){
	if(!m || m->v_free) return;
	m->v_free = true;
	for(int i = 0; i<4; i++){
		crawlAndDestroy(m->ajacent_nodes[i]);
	}
	free(m);
}
