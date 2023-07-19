#include "../main.h"

/**
 * str_weigth - return the weigth of a string
 * @str: An string input
 *
 * Description: That function allow us to know the
 * weight of a string.
 * Return: An int
 */

int str_weigth(char *str)
{
	int i = 0, weigth = 0;

	while (str[i])
	{
		weigth += (int) str[i];
		i++;
	}

	return (weigth);
}



/**
 * to_lower - lowercase characters
 * @str: A string
 *
 * Description:
 * That's a function that take a pointer on a string
 * and put all the letters to lowercase.
 */

void to_lower(char *str)
{
	int i = 0;

	while (str[i])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			str[i] += 32;

		}

		i++;
	}

}


/**
 * str_replace - a function that replace characters
 * @str: the sentence in which you want to replace the character
 * @to_be_repl: the character we want to replace
 * @substitute: the char that will substitute the other
 * 
 * Description: That function takes a string, a character to replace,
 * and a character we want to replace by the other.
 */

void str_replace(char *str, char to_be_repl, char substitute)
{

	int i = 0;

	while (str[i])
	{
		if (str[i] == to_be_repl)
		{
			str[i] = substitute;
		}

		i++;
	}
}
