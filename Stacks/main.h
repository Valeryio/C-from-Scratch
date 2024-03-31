#ifndef _MONTY_CIRCUS_
#define _MONTY_CIRCUS_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

/**
 * struct stack - a stack data structure
 *
 * @n: the integer of a node in the stack
 * @prev: a pointer to the previous node
 * @next: a pointer to the next node
 *
 * Description: This structure is built to
 * be useful for the implementation of LIFO
 * and FIFO algorithms
 */

typedef struct stack 
{
	int n;
	struct stack *prev;
	struct stack *next;
} stack_t;

void pop(stack_t**);
int is_empty(stack_t**);
void push(stack_t**, int);


#endif
