#include "main.h"
//#include "struct.h"

int main(void)
{
	File_ *my_file = NULL;

	Element *new_0 =  NULL, *new_1 = NULL, *new_2 = NULL, *new_3 = NULL;

/*
	new_0 = malloc(sizeof(Element));
	new_0->value = 4;
	new_0->next = NULL;


	new_1 = malloc(sizeof(Element));
	new_1->value = 5; 
	new_1->next = NULL;
*/
	new_0 = allocate_memory();
	new_0->value = 0;
//	new_0->next = NULL;

	new_1 = allocate_memory();
	new_1->value = 1;
//	new_1->next = NULL;*/
//
	new_2 = allocate_memory();
	new_2->value = 2;

	new_3 = allocate_memory();
	new_3->value = 3;

	my_file = malloc(sizeof(File_));

	if (!my_file)
	{
		printf("\nError, cannot allocate the memory!\n");
		exit(EXIT_FAILURE);
	}


	my_file->first = NULL;

	printf("\nI'm going to create a new file and add some elements\n");

	enfile(new_0, my_file);
	enfile(new_1, my_file);
	enfile(new_2, my_file);
	enfile(new_3, my_file);

	show_file(my_file);


	printf("\nThat is the new value that I defiled : %d \n", defile(my_file));
	printf("\nThat is the new value that I defiled : %d \n", defile(my_file));
	printf("\nThat is the new value that I defiled : %d \n", defile(my_file));
	printf("\nThat is the new value that I defiled : %d \n", defile(my_file));


	free(new_0);
	free(new_1);
	free(new_2);
	free(new_3);

	return (0);
}
