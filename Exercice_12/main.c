#include "main.h"
#include "struct.h"


/*
 * allocate_memory - is  a function that allocate memory
 *
 * Description: That is a function that allocate the memory
 * for a pointer of Element.
 * Return: @allocated_mem, a pointer on the allocate memory
 */

Element *allocate_memory(void)
{
	Element *allocated_mem = NULL;

	allocated_mem = malloc(sizeof(Element));

	if (!allocated_mem)
	{
		printf("annot allocate the memory");
		exit(EXIT_FAILURE);
	}

	allocated_mem->next = NULL;

	return (allocated_mem);
}

/*
 * enfile - a function that enfile
 * @new_element: A pointer to the new element we want to add to the file
 * @file_x: A pointer to the file we want to use
 *
 * Return: nothing at all!
 */

void enfile(Element *new_element, File_ *file_x)
{
	Element *tmp = NULL;

	if (file_x->first == NULL)
	{
		printf("\nThis is an empty list!\n");
		file_x->first = new_element;
		return;
	}

	tmp = file_x->first;

	while (tmp->next)
	{
		printf("\nThis is not an empty list!\n");
		tmp = tmp->next;
	}

	new_element->next = NULL;
	tmp->next = new_element;

	return;
}



/*
 * defile - a function that defile
 * @file_x: The file on which we want to defile
 * 
 * Description: That is a function that defile one element
 * of the file.
 * Return: @value, the value in the ceil that we defile from 
 * the file data structure.
 */



int defile(File_ *file_x)
{
	Element *tmp = NULL;

	int value = 0;

	tmp = file_x->first->next;
	value = file_x->first->value;

	free(file_x->first);
	file_x->first = tmp;

	return (value);
}


void show_file(File_ *file_x)
{

	Element *tmp = file_x->first;

	while (tmp)
	{
		printf(" %d ", tmp->value);

		if (tmp->next != NULL)
		{
			printf(" -> ");
		}

		tmp = tmp->next;
	}
}
