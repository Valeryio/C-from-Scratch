#include "../main.h"

/** show_language - a print function
 * @language: The language we want to print
 *
 * Description: That is a function that could print 
 * a language.
 * Return: Nothing
 */

void show_language(char *language[])
{

	int i = 0;

	while (language[i] != NULL)
	{
		printf("[ %s ]", language[i]);

		printf("%s", (language[i + 1] != NULL) ? "-" : "" );

		i++;
	}
}



/**
 * same_string - verify if two words are the same
 * @w1: a first word
 * @w2: a second word
 *
 * Description: That is a function that verify if two words are
 * the same.
 * Return: 1 if the word are the same and 0 otherwise!
 */

int same_string(char *w_1, char *w_2)
{
	int i = 0, checker = 0;

	while (w_1[i] && w_2[i] && (w_1[i] == w_2[i]))
	{
		checker++;
		i++;
	}


	if (!w_1[i] && !w_2[i])
	{
		return (1);
	}

	return (0);
}



/**
 * element_of - a search function
 * word: The word the want to search
 * @language: The language in which we want to make the research
 *
 * Description: That is a function that could verify if a word is
 * in a language or not.
 * Return: 0 is the word is not present, and !0 otherwise
 */

int element_of(char *word, char* language[])
{


//	show_language(language);

	int i = 0;

	while (language[i] != NULL)
	{
		if (same_string(word, language[i]))
		{
			return (1 + i);
		}
		
		i++;
	}

	return (0);
}



/**
 * is_disjoint - disjoints languages verification
 * @l_1: a pointer for the first language
 * @l_2: a pointer for the second language
 *
 * Description: That's a function that verify if two languages
 * are disjoint or not. 
 * Return: 1 if they are, and 0 if not!
 */

int is_disjoint(char *l_1[], char *l_2[])
{
	int i = 0, j = 0;

	while (l_1[i] && l_2[i])
	{
		i++;
	}

	if (!l_1[i] && !l_2[i])
	{
		printf("\nThe two langugages had the same number of word. We can compare them !\n");
	}
	else
	{
		printf("\nThe two languages hadn't the same number of word. We cannot compare them!\n");
		
		return (0);
	}


	while (l_1[j])
	{
		if (element_of(l_1[j], l_2))
		{
			j++;
		}
		else
		{
			return (1);
		}
	}


	return (0);
}




/**
 * add_word - adding word to a language
 * @word: a string (the word to add)
 * @language: the language we use
 *
 * Description: That's a function that we can use to add a word
 * to a language and return its index.
 * Return: i, the index of the added word.
 */

int add_word(char *word, char *language[])
{
	int i = 0;

	if (word == NULL)
	{
		printf("\nWe cannot add an empty or NULL word.\n");
		return (-1);
	}



	printf("\nThat is the language you gave : \n");

	show_language(language);




	while (language[i])
	{
		i++;
	}

	language[i] = word;

	language[i + 1] = NULL;




	printf("\nNow we have the new language !\n");

	show_language(language);

	return (i);
}



/**
 * gather_lang - add some word from a language to another
 * @l_1: the first language
 * @l_2: the second language
 *
 * Description: This function allow us to add the word of the first language
 * that are not in the second language to it. 
 * Return: Nothing at all!
 */

void gather_lang(char *l_1[], char *l_2[])
{
	int i = 0;


	printf("\n\nBeginning of the function. Showing languages : \n");
	show_language(l_1);
	printf("\n");
	show_language(l_2);

	while (l_1[i])
	{
		if (!element_of(l_1[i], l_2))
		{
			add_word(l_1[i], l_2);
		}

		i++;
	}


	printf("\n\nEnd of the function. Showing languages : \n");
	show_language(l_1);
	printf("\n");
	show_language(l_2);

}



/**
 * remove_word - remove a word
 * @word: the word you want to remove
 * @language: the language you want to use
 *
 * Descripition: That's a function that remove a word if this one
 * is found in a language.
 * Return: Nothing at all!
 */

void remove_word(char *word, char *language[])
{
	int i = 0;

	while (!same_string(word, language[i]))
	{
		i++;
	}
	
	if (language[i] == word)
	{
		while (language[i + 1] != NULL)
		{
			language[i] = language[i + 1];
		
			i++;
		}
	}
	
	language[i] = NULL;

}

