#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "struct.h"


/*FUNCTIONS TO MANIPULATE A file DATA STRUCTURE*/

Element *allocate_memory(void);
void enfile(Element*, File_*);
int defile(File_*);
void show_file(File_*);


#endif
