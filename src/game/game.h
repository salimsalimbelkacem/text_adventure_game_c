#ifndef __GAME__
#define __GAME__
#include <stdbool.h>

#define ITEM_HMAP_SIZE 127

// load factor = number of items / size
// load factory must not be >= 0.7

enum { NORTH = 0, EAST, SOUTH, WEST };

struct map_node {
	char description[50];
	char name[50];
	struct map_node* ajacent_nodes[4];
	bool v_free;
	struct item_bucket* item_list[ITEM_HMAP_SIZE];
};

struct item {
	char* name;
	union{
		char* map_description,
			inventory_description;
	};
	int weight;
	union{ // will not be used right now but is nice
	       // to have as reference for the future
		struct weapon_info{
			int damages,
			    range,
			    ammo;
			bool equiped;
		};
		struct key_info{
			int door_id;
		};
		struct posion{
			int effect;
		};
		char* (*Action)(int);
		// and so on and so on you get it pfff
	} item_info;
};

struct item_bucket{
	char* key;
	struct item value;

	struct item_bucket* next;
	struct item_bucket* previous;
};

struct player{
	struct map_node* position;
	struct item_bucket* inventory[ITEM_HMAP_SIZE];
};

// map node API
char* DescribePlayerPos (struct player);

// player API
void MovePlayer (struct player*, int direction);
char* DescribePlayerPos (struct player);

struct player* InitGame();
void DestroyGame(struct player**);

// item API

void DestroyBucketListArr (struct item_bucket** bucket_arr);

void AddItem (struct item_bucket** bucket_arr,
		const char* item_key, struct item item_);

void DestroyBucketListArr (struct item_bucket** bucket_arr);

struct item_bucket*
LookupItem (struct item_bucket** bucket_arr, const char* key);

void
PopItem (struct item_bucket** bucket_arr, const char* key);
#endif
