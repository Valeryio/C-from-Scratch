#include "../main.h"

/**
 * print_Int_Array - a function that print an array
 * @array: a pointer on the array
 * length: The length of the array
 *
 * Description: That's a function that just print an array
 * on the standard output.
 * Return: Nothing
 */



void print_Int_Array(int *array, int length)
{

	int i = 0;

	for (i = 0; i < length; i++)
	{
		printf("[ %d ]", array[i]);
	}

	printf("\n");

}
