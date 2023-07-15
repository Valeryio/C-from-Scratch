#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdio.h>
#include <stdlib.h>

void print_Int_Array(int *Array, int);

void mirror(char*, char*);

int is_factor(char*, char*);

void show_language(char *language[]);

int element_of(char *word, char *language[]);

int same_word(char*, char *w_2);

int is_disjoint(char *l_1[], char *l_2[]);

int add_word(char*, char *language[]);

void gather_lang(char *l_1[], char *l_2[]);

void remove_word(char*, char *language[]);

int is_letter(void *ptr);

#endif
