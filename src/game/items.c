#include "./includes.h"
#include "./game.h"
#include <stdlib.h>
#include <string.h>

static unsigned long
sdbm (const char *str)
{
	unsigned long hash = 0;
	int c;

	while ((c = *str++))
		hash = c + (hash << 6) + (hash << 16) - hash;

	return hash;
}

void
AddItem (struct item_bucket** bucket_arr, const char* item_key,
		struct item item_)
{
	unsigned long index = sdbm(item_key)%ITEM_HMAP_SIZE;

	struct item_bucket* p;

	if ( (p = bucket_arr[index]) != NULL ){
		p = p->next;
		p->previous = bucket_arr[index];
	}

	p = malloc(sizeof(struct item_bucket));
	p->key = malloc(50);
	strncpy(p->key, item_key, 50);

	p->value = item_;
	p->next = NULL;
	return;
}

static void
destroyBucketList (struct item_bucket* bucket_list)
{
	if(bucket_list == NULL) return;
	destroyBucketList(bucket_list->next);
	free(bucket_list);
}

void
DestroyBucketListArr (struct item_bucket** bucket_arr)
{
	for(int i = 0; i<ITEM_HMAP_SIZE; i++){
		destroyBucketList(bucket_arr[i]);
	}
}

static struct item_bucket*
LookupItemList (struct item_bucket* bucket, const char* key)
{
	if(bucket == NULL || !strcmp(key, bucket->key))
		return bucket;
	
	return LookupItemList(bucket->next, key);
}

static struct item_bucket**
lookupItemIndex (struct item_bucket** bucket_arr, const char* key)
{
	return bucket_arr + (sdbm(key)%ITEM_HMAP_SIZE);
}

struct item_bucket*
LookupItem (struct item_bucket** bucket_arr, const char* key)
{
	struct item_bucket* bucket = *lookupItemIndex(bucket_arr, key);
	return LookupItemList(bucket, key);
}


void
PopItem (struct item_bucket** bucket_arr, const char* key)
{
	struct item_bucket* item = LookupItem(bucket_arr, key);
	if(!item) return;

	struct item_bucket* p = item->next;
	struct item_bucket** head_pp = lookupItemIndex(bucket_arr, key);

	if(!item->previous)
		*head_pp = p;
	
	else
		item->previous->next = p;
	
	if(p) p->previous = item->previous;

	free(item);
}
