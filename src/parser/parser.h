#ifndef __PARSER__
#define __PARSER__

typedef struct grammar
{
	char* verbs[10];
	char* objects[10];
	char* (*Handle)(int);
} grammar;

#define GRAMMAR_SIZE 3
enum{EXIT=0, GO, SEE,};
char* Parse(char* raw);

#endif
