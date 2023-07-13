#include "../main.h"


/*
 * mirror - make a mirror of a string
 * @src: The source string
 * @dst: The destination string
 *
 * Description: This function takes the fist source and write it
 * by reverse in the string dest. Then, dst contain the mirror of
 * the string that is in the source string
 * Return: Nothing at all!
 */

void mirror(char *dst, char *src)
{
	int i = 0, length = 0;

	while (src[length] != '\0')
	{
		length++;
	}

	length--;

	while (length >= 0)
	{
		dst[i] = src[length];

		i++;
		length--;
	}
	
	dst[i] = '\0';
}
