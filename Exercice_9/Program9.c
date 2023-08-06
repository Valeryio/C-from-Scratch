#include "../main.h"
#include "struct.h"

#if _WIN32
#define file_length file_length_WINDOWS_OS
#else
#define file_length file_length_LINUS_OS
#endif



int main(void)
{

	short length = 0, i = 0, j = 0;

	char *text;

	letter alphabet[52];

	letter tmp = {'\0', 0};

	FILE *file = NULL;
	printf("\nSIZE OF THE ALPHABET : %zu\n", sizeof(alphabet));

/*Initialisation of the data structure*/

	for (i = 0; i < 52; i++)
	{
		alphabet[i].character = '\0';
		alphabet[i].number = 0;
	}


/*Openning the file and copy its content into a string var*/
	file = fopen("text.txt", "rt");

	if (!file)
	{
		perror("Error, cannot open the file!");
		exit(EXIT_FAILURE);
	}

	length = file_length(file);
	printf("\nThat is the length of the file : %d\n", length);


	text = malloc ((length + 1) * sizeof(char));
	if (!text)
	{
		printf("Error, cannot allocate the memory!");
	}


	file_to_string(file, text);
	printf("\nContent of the file : \n\n%s\n", text);


/*Initialisation of the alphabet*/
	init_alphabet(alphabet, 'x');
	for (i = 0; i < 52; i++)
	{
		printf("%c - ", alphabet[i].character);
	}


/*Counting the frequence of each character*/

	for (i = 0; i < 52; i++)
	{
		while (text[j])
		{
			if (alphabet[i].character == text[j])
			{
				alphabet[i].number++;
			}
			j++;
		}

		j = 0;
	}


/*Sorting the result by ascending frequence*/
	for (i = 0; i < 52; i++)
	{
		for (j = 0; j < 52; j++)
		{

			if (alphabet[j].number > alphabet[j+1].number)
			{
	
				tmp.character = alphabet[j].character;
				tmp.number = alphabet[j].number;

				alphabet[j].character = alphabet[j + 1].character;
				alphabet[j].number = alphabet[j + 1].number;

				alphabet[j + 1].character = tmp.character;
				alphabet[j + 1].number = tmp.number;
			}
		}
	}


	printf("After sorting : ");

	for (i = 0; i < 52; i++)
	{
		printf("COUNTING  %c : %d \n", alphabet[i].character, alphabet[i].number);
	}


	free(text);
	fclose(file);

	return (0);
}
