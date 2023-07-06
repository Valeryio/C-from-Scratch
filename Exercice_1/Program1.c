#include "../main.h"

#define length 4


int main(void)
{

	int j = 0, i = 0, tmp = 0;


	int array[length] = {9, 0, 3, 2};

	print_Int_Array(array, length);

	while (i < length)
	{

		for (j = i+1; j < length; j++)
		{
			if (array[j] < array[i])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}

		i++;

	}

	printf("\n");

	print_Int_Array(array, length);

	return(0);
}
