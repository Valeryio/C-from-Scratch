#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
/*
 * #include "Exercice_9/struct.h"
#include "Exercice_11/struct.h"*/

#include "Exercice_12/struct.h"


/*FUNCTIONS ON ARRAY OF STRING*/

/*What we call a language here is a set of strings
in the same array. These data structure is created
using an array of pointers. Then you can perform all
this kind of operations allowd by the functions I wrote here !

Enjoy !
*/
void print_Int_Array(int *Array, int);

void mirror(char*, char*);

int is_factor(char*, char*);

void show_language(char *language[]);

int element_of(char *word, char *language[]);

int is_disjoint(char *l_1[], char *l_2[]);

int add_word(char*, char *language[]);

void gather_lang(char *l_1[], char *l_2[]);

void remove_word(char*, char *language[]);



/*FUNCTIONS TO MANIPULATE STRINGS*/

/*In the string.h library we have some essential
and indispensable function to manipulate strings.
Before using them all time, like I want without 
worrying to much to know if I'm capable of rewrite
these functions..

I decided to write some beautiful functions of string.h
here.
You can use all of them !

Enjoy !
*/

int same_string(char*, char*);

char* Cesar_ciphering(char*, int, char*);

char* Cesar_deciphering(char*, int, char*);

int Cesar_text_ciphering_checker(char*, int, char*);

int Cesar_text_deciphering_checker(char*, int, char*);

int is_letter(void *ptr);

char* enter_str(void);

int str_weigth(char*);

void to_lower(char*);

void str_replace(char*, char, char);




/*FUNCTIONS TO MANIPULATE FILES*/

/*Stdlib have some function to manipulate files
but in some case, I need to create my own to do
specific task and manipulate files.

Here you are these functions.

Enjoy !
*/
int file_concat(FILE*, FILE*, FILE*); /*Still not working with long strings!*/

int file_to_string(FILE*, char*);

int file_length_LINUX_OS(FILE*);

int file_length_WINDOWS_OS(FILE*);

int cipher_file(char*, char*, int);

int decipher_file(char*, char*, int);





/*FUNCTIONS TO MANIPULATE THE DATA STRUCTURE LETTER*/
/*
 letter is a data structure composed by a char and a letter
 that is the sum of the occurence of the char in a text
 */

int init_alphabet(letter*, char);


/*FUNCTION TO MANIPULATE A LIST*/

List *create_list(void);
List *list_add_element(int, List*);
int show_list(List*);
int remove_from_list(int, List*);
int delete_list(List*);
int search_value(int value, List *list_x);
int list_length(List*);
int insert_element(int, Element*, List*);



/*FUNCTIONS TO MANIPULATE A file DATA STRUCTURE*/
void enfile(Element*, File_*);
int defile(File_*);
void show_file(File_*);


#endif
