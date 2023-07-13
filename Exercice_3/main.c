#include "../main.h"

/**
 * is_factor - a funtion that search a substring
 * @factor: The substring
 * @src: The original string
 *
 * Description: That is a function that search a substring
 * in another string. 
 * Return: 1 if found and 0 otherwise!
 */



int is_factor(char *factor, char *src)
{
	int i = 0, j = 0, k = 0, checker = 0;

	while (src[i])
	{
		if (src[i] == factor[0])
		{
			k = i;

			while (factor[j] && (factor[j] == src[k]))
			{
				checker++;
				j++;
				k++;
			}
		
			if (((checker - 1) == (j - 1)) && !factor[j])
			{
				return (1);
			}
			else
			{
				checker = 0;
			}

		}

		i++;
	}
	


	return (0);
}
