#include "../main.h"

#if _WIN32
#define file_length file_length_WINDOWS_OS
#else
#define file_length file_length_LINUX_OS
#endif

/**
 * file_length - get the length of the file
 * @file: A pointer on a file
 *
 * Description: That function get a pointer on a file, 
 * and return the number of character in the file. With
 * this number we can know how byte we should allocate in
 * the memory to save all the letters of the file.
 * Return: @length!
 */

int file_length_LINUX_OS(FILE *file)
{
	int length = 0;

	fseek(file, 0, SEEK_END);

	length = ftell(file);

	rewind(file);

	return (length);
}


int file_length_WINDOWS_OS(FILE *file)
{
	int number = 0;

//	rewind(file);
	while (!feof(file))
	{
/*fgetc is used to move the cursor in the file*/

		fgetc(file);
		number++;
	}

	rewind(file);
/*number - 1 cause there is the first iteration of feof that is right, but not a character, just the beginning*/
	return (number - 1);
}

/**
 * file_to_string - copy the content of a file in a string
 * @file: A pointer on the file
 * @str: The pointer on the string in which you want to make the copy
 *
 * Description: That function take a file and copy all his content
 * in a string (array of char), to use this content more easily
 * in a program.
 * Return: @Number of written characters.
 */

int file_to_string(FILE *file, char *str)
{
	int length = file_length(file);

	fread(str, sizeof(char), length, file);

	/*Add the EOL '\0' character to make a complete string*/
	str[length] = '\0';

	return (length);
}



/**
 * Cesar_ciphering - a ciphering function
 * @str: The string we want to cipher
 * @step: An int that is the step
 * @ciphered_text: A pointer to the ciphered text
 *
 * Description: Based on the algorithm of Jule C�sar, the algorithm
 * use a number as a step to change letters by another, making a 
 * non-sense text for the ones that ignore the step (number).
 * 
 * ---------------------------------------------------------
 * DON'T FORGET TO FREE THE MEMORY AFTER USING THIS FUNCTION
 * ---------------------------------------------------------
 *
 * Return: @ciphered_text, a pointer to the ciphered text!
 */

char* Cesar_ciphering(char *str, int step, char *ciphered_text)
{
	int i = 0;

	while (str[i])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			ciphered_text[i] = 'A' + ((str[i] - 'A' + step + 26) % 26);
		}
		else if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			ciphered_text[i] = 'a' + ((str[i] - 'a' + step + 26) % 26);
		}
		else
		{
			ciphered_text[i] = str[i];
		}

		i++;
	}
	
	ciphered_text[i] = '\0';


	return (ciphered_text);
}



/**
 * Cesar_deciphering - decipher the C�sar Algorithm
 * @cipher: A string that represent the ciphered text
 * @step: The step used to cipher the original text
 * @deciphered_text: A pointer to the deciphered text
 *
 * Description: That algorithm decipher a text ciphered
 * with the algorithm of C�sar!
 *
 * ---------------------------------------------------------
 * DON'T FORGET TO FREE THE MEMORY AFTER USING THIS FUNCTION
 * ---------------------------------------------------------
 *
 * Return: @deciphered_text, a pointer to the deciphered text.
 */

char* Cesar_deciphering(char *str, int step, char *deciphered_text)
{
	int i = 0;


	while (str[i])
	{
		if ((str[i] >= 'A') && (str[i] <= 'Z'))
		{
			deciphered_text[i] = 'A' + ((str[i] - 'A' - step + 26) % 26);

		}
		else if ((str[i] >= 'a') && (str[i] <= 'z'))
		{
			deciphered_text[i] = 'a' + ((str[i] - 'a' - step + 26) % 26);
		}
		else
		{
			deciphered_text[i] = str[i];
		}

		i++;
	}

	deciphered_text[i] = '\0';


	return (deciphered_text);
}



/**
 * Cesar_text_ciphering_checker - check if the encryption is right
 * @plain_text: The plain text that we want to cipher
 * @cipher: The ciphering file we have done
 * @step: The step we want to use to decipher the text ciphered
 *
 * Description: That algorithm take a string and a string. The string contain
 * the cipher of the text in the file. Then we verify if the encryption is right
 * or Not.
 * Return: 1 if the enciphering is right, and 0 otherwise!
 */

int Cesar_text_ciphering_checker(char *plain_text, int step, char *cipher)
{
	char *decipher;
	int length = strlen(plain_text);

	decipher = malloc((length + 1) * sizeof(char));

	if (!decipher)
	{
		printf("\nError, cannot allocate the memory!\n");
		exit(EXIT_FAILURE);
	}

	Cesar_deciphering(cipher, step, decipher);
	
	if (same_string(plain_text, decipher))
	{
		return (1);
	}
	
	free(decipher);

	return (0);
}



/**
 * Cesar_text_deciphering_checker - check if the deciphering is right.
 * @original_cipher: the original text ciphered
 * @step: The step used for deciphering
 * @decipher: The decipher result obtained
 *
 * Description: That algorithm takes the cipher and the last deciphered result, 
 * and make itself the deciphering of the cipher. Then it compares it results to 
 * the one it takes in argument.
 * Return: 1 if the deciphering is right, and 0 otherwise!
 */

int Cesar_text_deciphering_checker(char *original_cipher, int step, char *decipher)
{
	int length = 0;
	char *cipher = NULL;

	length = strlen(original_cipher);

	cipher = malloc((length + 1) * sizeof(char));

	if (!cipher)
	{
		printf("\nError, cannot allocate the memory!\n");
		exit(EXIT_FAILURE);
	}

	Cesar_ciphering(decipher, step, cipher);

	if (same_string(cipher, original_cipher))
	{
		return (1);
	}

	free(cipher);

	return (0);

}
