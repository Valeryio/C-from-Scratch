#include "../main.h"

/**
 * main - manipulation of strings
 * 
 * Description: That's a function that manipulate an array
 * of strings. It takes dynamically input from the keyboard
 * and sort an array of strings in which the new string is 
 * saved.
 * Return: 0
 */


int main(void)
{
	int i = 0, j = 0, k = 0;

	char end_str[20], *str_tab[6] = {NULL}, tmp_str[20];


	while (i < 5)
	{
		printf("\nGive a value : ");
		
		/*I get the string from the STDIN with the fgets function*/
		fgets(end_str, sizeof(end_str), stdin);

		/*I use the function str_replace to replace the NL character \n by \0*/
		str_replace(end_str, '\n', '\0');


		to_lower(end_str);
		
		if (!(strcmp(end_str, "fin") == 0))
		{
			str_tab[i] = malloc(20 * sizeof(char));
			strcpy(str_tab[i], end_str);
		}
		else
		{
			printf("NO");
		}


		show_language(str_tab);

		while (str_tab[k] != NULL)
		{
			j = 0;
			
			while (str_tab[j] != NULL && str_tab[j+1] != NULL)
			{
			
				if (str_weigth(str_tab[j]) > str_weigth(str_tab[j + 1]))
				{
					strcpy(tmp_str, str_tab[j]);
					strcpy(str_tab[j], str_tab[j+1]);
					strcpy(str_tab[j+1], tmp_str);
				}

				j++;
			}

			k++;
		}

		k = 0;

		printf("\nSecond Operation : \n ");
		show_language(str_tab);

		i++;

	}



	return (0);
}
