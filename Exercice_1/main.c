#include "../main.h"

void print_Int_Array(int *array, int length)
{

	int i = 0;

	for (i = 0; i < length; i++)
	{
		printf("[ %d ]", array[i]);
	}

	printf("\n");

}
