// let's just do
// verb + object 
// for now
#include "./includes.h"
#include "./handlers.h"

extern struct player* Player;

typedef struct grammar
{
	char* verbs[10];
	char* objects[10];
	char* (*Handle)(char*, char*);
} grammar;
#define GRAMMAR_SIZE 3
enum{EXIT=0, GO, SEE,};

grammar Grammar[] = {
	{
		.verbs={"exit"},
		.objects=NULL
	},
	{
		.verbs={"go", "walk", "move", "head"},
		.objects={"north", "east", "south", "west"}
	},
	{ 
		.verbs={"look", "see", "describe"},
		.objects=NULL
	}
};

char** tokenize(char* raw)
{

	char raw_copy[50];
	static char* tokens[2]; int i = 0;

	strcpy(raw_copy, raw);
	DPRINT("\t1st token extraction...");
	tokens[0] = strtok(raw_copy," \n");

	DPRINT("\tthe rest...");
	while(tokens[i] && i<2) {
		DPRINT(tokens[i]);
		tokens[++i] = strtok(NULL," \n");
	}

	DPRINT("\tdone tokenizing");
	return (char**)tokens;
}
bool lookForStr(char* str, char** arr)
{
	for(int i = 0; arr[i]!=NULL; i++)
{
		DPRINT(arr[i]);
		if(!strcmp(str, arr[i])) return true;
	}
	return false;
}

int lookForVerb(char* verb_tok)
{
	for(int i = 0; i<GRAMMAR_SIZE; i++)
{
		if(lookForStr(verb_tok, Grammar[i].verbs)) return i;
	}
	return -1;
}

int lookForobject(char* verb_tok, int index)
{
	for(int i = 0; Grammar[index].objects[i]!=NULL; i++) {
		DPRINT(Grammar[index].objects[i]);
		if(verb_tok!=NULL && !strcmp(verb_tok, Grammar[index].objects[i])) return i;
		DPRINT("nsm");
	}
	return -1;
}

char* Parse(char* raw)
{
	DPRINT("tokenizing the raw input...");
	char** tokens = tokenize(raw);

	DPRINT("searching for the verb...");
	int verb = lookForVerb(tokens[0]);

	if(verb<0) {
		return "i don't get what you're talking about";
	}

	int g_object;
	switch (verb) {
		case EXIT:
			return NULL;
			break;
		case GO:
			DPRINT("searching for the direction...");
			DPRINT(tokens[1]);
			g_object = lookForobject(tokens[1], GO);
			return Handle_go(g_object);
			break;
		case SEE:
			return Handle_see(0);
			break;
		default:
			return "i don't know how you got here";
			break;
	}

	return NULL;
}

