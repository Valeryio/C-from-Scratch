#include "../main.h"

#ifdef _WIN32
#define file_length file_length_WINDOWS_OS
#else
#define file_length file_length_LINUX_OS
#endif

/**
 * file_concat - concat two file
 * @str_1: a pointer opened on the first file
 * @str_2: a pointer opened on the second file
 * @str_3: a pointer opened on the third file
 *
 * Description: That is a function that takes three files. Two
 * of the first files containing a text, and the third is just
 * the one that will contain the concatenation of the two first files.
 * Return: 0 if that's done, and 1 (with an error message) if there is a
 * problem.
 */



int file_concat(FILE *str_1, FILE *str_2, FILE *str_3)
{
	int i = 0, total_length = 0, char_number_1 = 0, char_number_2 = 0;

	char *text_1 = NULL, *text_2 = NULL, *text_3 = NULL;

/*This function allow us to know the number of characters between the end and the beginning of the file*/
	char_number_1 = file_length(str_1);
	char_number_2 = file_length(str_2);

	printf("\nThat is the length of the text 1 : %d\n", char_number_1);
	printf("\nThat is the length of the text 2 : %d\n", char_number_2);


/*Allocation of the necessary memory to get the text*/
	text_1 = malloc((char_number_1 + 1) * sizeof(char));

	if (!text_1)
	{
		printf("\nError, cannot allocate the memory!\n");
		exit(EXIT_FAILURE);
	}


	text_2 = malloc((char_number_2 + 1) * sizeof(char));

	if (!text_2)
	{
		printf("\nError, cannot allocate the memory!\n");
		exit(EXIT_FAILURE);
	}


/*Copying the content of the file in the strings*/
	fread(text_1, sizeof(char), char_number_1, str_1);
	fread(text_2, sizeof(char), char_number_2, str_2);

	text_1[char_number_1] = '\0';
	text_2[char_number_2] = '\0';

	strcat(text_1, text_2);
	total_length = char_number_1 + char_number_2 + 1;

/*Allocating memory to get the text concatenation*/	
	text_3 = malloc((char_number_1 + char_number_2 + 1) * sizeof(char));
	
	if (!text_3)
	{
		printf("\nError, cannot allocate the memory!\n");
		exit(EXIT_FAILURE);
	}

/*Writing the text in the file*/
	strcpy(text_3, text_1);
	fwrite(text_3, sizeof(char), (char_number_1 + char_number_2), str_3);

	printf("\nThat is the content of text_3 : \n\n%s\n", text_3);

	fclose(str_3);
	free(text_1);
	free(text_2);

	return (0);
}
