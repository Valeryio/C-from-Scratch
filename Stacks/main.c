#include "main.h"

/**
 * main - test some stacks functions
 */

int main(int argc, char *argv[])
{

	int i = 0;
	stack_t *head = NULL;

	for(; i < 4; i++)
		push(&head, i);

	pall(&head);

	return (0);
}
