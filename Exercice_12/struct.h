#ifndef _STRUCT_H_
#define _STRUCT_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct Element Element;
struct Element 
{
	int value;
	struct Element *next;
};

typedef struct File_ File_;

struct File_
{
	Element *first;
};

#endif
