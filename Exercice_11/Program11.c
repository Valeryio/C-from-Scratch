#include "../main.h"
#include "struct.h"

int main(void)
{

	List *my_list;

	Element *new_element = NULL;

	new_element = malloc(sizeof(Element));

	if (!new_element)
	{
		printf("Error, cannot allocate memory!");
		exit(EXIT_FAILURE);
	}

	new_element->value = 2004;
	new_element->next = NULL;

	my_list = create_list();

	list_add_element(4, my_list);
	list_add_element(5, my_list);
	list_add_element(6, my_list);
	list_add_element(7, my_list);
	list_add_element(8, my_list);
	list_add_element(9, my_list);
	list_add_element(10, my_list);
	list_add_element(11, my_list);
	list_add_element(12, my_list);

	printf("\nNow I'll show my list : ");
	show_list(my_list);

	printf("\nLet me remove the element 6!\n");
	remove_from_list(6, my_list);

	printf("\nShowing the list once again : ");
	show_list(my_list);

	printf("\nLet me remove the element 4!\n");
	remove_from_list(4, my_list);
	
	printf("\nShowing the list once again : ");
	show_list(my_list);
	
	printf("\nLet me remove the element 12!\n");
	remove_from_list(12, my_list);
	
	printf("\nShowing the list once again : ");
	show_list(my_list);
/*
	printf("\nNow I'll delete all the list! \n");
	delete_list(my_list);

	printf("\nShowing the list once again!\n");
	show_list(my_list);
*/
	printf("\nNow, I'll search the value 5\n");
	search_value(5, my_list);

	printf("\nNOW I'll add 2004 at the index 4 \n !");


	insert_element(4, new_element, my_list);

	printf("\nShowing the list once again\n");
	show_list(my_list);


	printf("\nNow, I'll get the value my list : %d\n", list_length(my_list));

	return (0);
}
