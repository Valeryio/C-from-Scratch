#include "../main.h"
#include "struct.h"

/**
 * create_list - a funtion that create a list
 *
 * Description: That is a function that create a list and
 * give a pointer on that list.
 * Return: @list, a pointer on the top of the list.
 */

List *create_list(void)
{
	
	List *list_x = malloc(sizeof(List));

	if (!list_x)
	{
		printf("\nError, cannot allocate the memory!\n");
		exit(EXIT_FAILURE);
	}


	list_x->first = NULL;

	return (list_x);
}



/**
 * list_add_element - add an element to the list
 * @value: The int value in the next element of the list
 * @list_x: The list I have to use
 *
 * Description: This function takes a list and add a value to 
 * this list.
 * Return: @list, a pointer on the top of the list.
 */

List *list_add_element(int value, List *list_x)
{

	Element *new = malloc(sizeof(Element));

	if (!new)
	{
		printf("\nError, cannot allocate the memory!\n");
		exit(EXIT_FAILURE);
	}

	new->value = value;

	if (!list_x->first)
	{
		printf("\nThis is an empty list!\n");
		
		new->next = NULL;
		list_x->first = new;
	}
	else
	{
		new->next = list_x->first;
		list_x->first = new;
	}


	return (list_x);
}



/**
 * show_list - a function that shows a linked list
 * @list_x: the list
 *
 * Description: That is a function that shows a list.
 * Return: Nothing!
 */

int show_list(List *list_x)
{
	Element *j = NULL;
	j = list_x->first;

	if (!list_x->first)
	{
		printf("\nThe list is empty!\n");
		return (0);
	}

	while (j)
	{
		printf("%d", j->value);
		
		if (j->next)
		{
			printf(" -> ");
		}

		j = j->next;
	}

	return (0);
}

/**
 * remove_from_list - remove an element from the list
 * @value: The value of the element which will be removed
 *
 * Description: This function takes an element and remove it 
 * from the list.
 * Return: 0 if everything is good
 */

int remove_from_list(int value, List *list_x)
{
	Element *j = list_x->first, *tmp = NULL;

/*Case in which the ceils that we are looking for in at the beginning of the linked list*/

	if (list_x->first->value == value)
	{
		tmp = list_x->first->next;
		
		free(list_x->first);

		list_x->first = tmp;

		return (0);
	}


/*Case in which the ceil we are looking for is not at the beginning of the linked list*/
	while (j)
	{
		if (j->next->value == value)
		{
			tmp = j->next->next;

			free(j->next);

			j->next = tmp;	

			return (0);
		}
		
		j = j->next;
	}
	
	return (1);
}


/*delete_list - a function that delete a list
 * @liste: the list that we want to delete
 *
 * Description: That function takes a list and delete all
 * the elements of this one.
 * Return: 0 when the function ends
 */

int delete_list(List *list_x)
{
	Element* tmp;

	while (list_x->first)
	{
		tmp = list_x->first;
		list_x->first = list_x->first->next;
		free(tmp);
	}

	return (0);
}

/*
 * search_value - search a cell that contain a value
 * @value : The value we want to find
 * @list_x : The list in wich the ceil containing the value is
 *
 * Description: This function takes a value and a function, and
 * find the value in the List.
 * Return: 0 if the value is found, 1 otherwise!
 */

int search_value(int value, List* list_x)
{
	Element *tmp = list_x->first;

	while (tmp)
	{
		if (tmp->value == value)
		{
			printf("\nThe value has been found!\n");
			return (0);
		}
		
		tmp = tmp->next;
	}

	printf("\nThe value has not been found!\n");

	return (1);
}


/*
 * list_length - give the length of the list
 * @list_x: The list of which we want to find the length
 *
 * Description: That function takes a list and find his
 * length.
 * Return: @length, the length of the list
 */

int list_length(List *list_x)
{
	Element *tmp = list_x->first;
	int length = 0;

	while (tmp)
	{
		length++;
		tmp = tmp->next;
	}
	
	return (length);
}


/*
 * insert_element - a function that insert an element
 * @index: The index of the element to insert
 * @new_element : The new_element we want to insert
 * @list_x : The list in which we want to insert
 *
 * Description: This function takes an index, a list and a new
 * element. It insert the new element at the index, in the list.
 * Return: 0 if everything is okay, and 1 otherwise.
 */

int insert_element(int index, Element *new_element, List *list_x)
{
	int i = 0;
	Element *tmp = list_x->first, *tmp_transfert = NULL;

	while ((i+1) != index)
	{
		tmp = tmp->next;
		i++;
	}

	tmp_transfert = tmp->next;
	tmp->next = new_element;
	new_element->next = tmp_transfert;

	return (0);
};
