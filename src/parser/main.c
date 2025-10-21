// let's just do
// verb + object 
// for now
#include "./includes.h"
#include "./handlers.h"

extern struct player* Player;


grammar Grammar[] = {
	{
		.verbs={"exit"},
		.objects={NULL},
		.Handle=NULL
	},
	{
		.verbs={"go", "walk", "move", "head"},
		.objects={"north", "east", "south", "west"},
		.Handle=Handle_go
	},
	{ 
		.verbs={"look", "see", "describe"},
		.objects={NULL},
		.Handle=Handle_see
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
	char* message = NULL;

	DPRINT("searching for the verb...");
	int verb = lookForVerb(tokens[0]);

	if(verb<0) {
		message = malloc(50);
		strcpy(message, "i don't know what you're talking about");
		return message;
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
			return Grammar[GO].Handle(g_object);
		case SEE:
			return Grammar[SEE].Handle(0);
		default:

			message = malloc(50);
			strcpy(message, "i don't know how you got here");
			return message;
	}

	return NULL;
}

