#include "../main.h"
#include "struct.h"


/**
 * init_alphabet - initialise the alphabet for a structure of letter
 * @alphabet: take the alphatbet (data structure)
 * @mode: who takes the mode to initialise the structure
 *
 * Description: That is a function that takes an array of structure 
 * named alphabet, composed of letters, that it should initialise with
 * all the letters of the english alphabet.
 * Return: 0 if everything is alright
 */

int init_alphabet(letter *alphabet, char mode)
{
	char i;
	short j = 0, middle = 0;

	switch (mode)
	{
		case 'a':
			for (i = 'a'; i <= 'z'; i++)
			{
				alphabet[j].character = i;
				j++;
			}
		break;


		case 'A':
			for (i = 'A'; i <= 'Z'; i++)
			{
				alphabet[j].character = i;
				j++;
			}
		break;


		case 'x':
			for (i = 'a'; i <= 'z'; i++)
			{
				alphabet[j].character = i;
				j++;
			}

			for (i = 'A'; i <= 'Z'; i++)
			{
				alphabet[j].character = i;
				j++;
			}
		break;


		default:
			printf("\nError, cannot initialise the alphabet!\n");
	}

	return (0);
}
