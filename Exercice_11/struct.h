#ifndef _STRUCT_H_
#define _STRUCT_H_

#include "../main.h"

typedef struct Element Element;

struct Element
{
	int value;
	Element *next;
};

typedef struct List
{
	Element *first;
} List;




#endif
