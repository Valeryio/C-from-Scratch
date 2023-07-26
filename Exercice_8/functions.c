#include "../main.h"

#define ENC_checker Cesar_text_ciphering_checker
#define DEC_checker Cesar_text_deciphering_checker

#if _WIN32
#define file_length file_length_WINDOWS_OS
#else
#define file_length file_length_LINUX_OS
#endif


/**
 * cipher_file - cipher a file
 *
 * Description: This main is special. It takes a file
 * cipher it, and save it into another file with no error.
 * Return: 0 in all case!
 */

int cipher_file(char *text_file,char *new_file, int step)
{

	FILE *file_1 = NULL, *file_2 = NULL;
	char *text = NULL, *cipher = NULL;
	int length = 0;

/*Opening the file in which the text I want to cipher and save in another file is!*/
	file_1 = fopen(text_file, "r");

	if (!file_1)
	{
		perror("\nError, cannot open the file!\n");
		exit(EXIT_FAILURE);
	}


/*Getting the number of characters in the file to allocate the right memory size*/
	length = file_length(file_1);
	printf("\nLength of the string : %d\n", length);

	text = malloc((length + 1) * sizeof(char));

	if (!text)
	{
		printf("Error, cannot allocate the memory");
		exit(EXIT_FAILURE);
	}

/*Conversion of the file into a string I choosed (a variable)!*/

	file_to_string(file_1, text);
	printf("\nClear text of the file you gave : \n");
	printf("#####################################################\n%s\n", text);
	printf("#####################################################\n\n", text);

/*Ciphering the text, I ask for a step to use C�sar's Algorithm*/
	cipher = malloc((length + 1) * sizeof(char));
	
	if (!cipher)
	{

		printf("Error, cannot allocate the memory");
		exit(EXIT_FAILURE);
	}


	Cesar_ciphering(text, step, cipher);

	printf("\nCIPHER : \n");
	printf("#####################################################\n%s\n", cipher);
	printf("#####################################################\n\n", cipher);


/*Verify if the cipher is right and without error, before saving in the new file I choosed!*/
	if (ENC_checker(text, step, cipher))
	{
		printf("\nThe file is ciphered with no errors!\n");
	}
	else
	{
		printf("\nError in the ciphered text!\n");
	}

/*Writing the cipher in the new file!*/
	file_2 = fopen(new_file, "w+");
	if (!file_2)
	{
		perror("\nError, cannot open the file!\n");
		exit(EXIT_FAILURE);
	}

	fputs(cipher, file_2);

	printf("\nThe name of the generated file is : %s\n", new_file);


/*Closing the files and free the memory!*/
	fclose(file_1);
	fclose(file_2);
	free(text);
	free(cipher);

	return (0);
}





/**
 * decipher_file - dcipher a file
 *
 * Description: That function is the reverse of cipher a text.
 * It takes a file cipher it, and save it into another 
 * file with no error.
 * Return: 0 in all case!
 */


int decipher_file(char *text_file,char *new_file, int step)
{

	FILE *file_1 = NULL, *file_2 = NULL;
	char *text = NULL, *decipher = NULL;
	int length = 0;


/*Opening the file in which the text I want to cipher and save in another file is!*/
	file_1 = fopen(text_file, "r");

	if (!file_1)
	{
		perror("\nError, cannot open the file!\n");
		exit(EXIT_FAILURE);
	}


/*Getting the number of characters in the file to allocate the right memory size*/
	length = file_length(file_1);

	printf("\nLength of the string : %d\n", length);

	text = malloc((length + 1) * sizeof(char));
	
	if (!text)
	{
		printf("\nError, cannot allocate memory!\n");
		exit(EXIT_FAILURE);
	}


/*Conversion of the file into a string I choosed (a variable)!*/
	file_to_string(file_1, text);
	printf("\nClear text of the file you gave : \n");
	printf("#####################################################\n%s\n", text);
	printf("#####################################################\n\n", text);


/*Deciphering the text, I ask for a step to use C�sar's Algorhm*/
	decipher = malloc((length + 1) * sizeof(char));

	if (!decipher)
	{
		printf("Failed to allocate the memory");
		exit(EXIT_FAILURE);
	}


	Cesar_deciphering(text, step, decipher);

	printf("\nDECIPHER : \n");
	printf("#####################################################\n%s\n", decipher);
	printf("#####################################################\n\n", decipher);



/*Verify if the decipher is right and without error, before saving in the new file I choosed!*/
	if (DEC_checker(text, step, decipher))
	{
		printf("\nThe file is deciphered with no errors!\n");


/*Writing the decipher in the new file!*/
		file_2 = fopen(new_file, "w+");
		if (!file_2)
		{
			perror("Error, cannot open the file!\n");
			exit(EXIT_FAILURE);
		}
		fprintf(file_2, "%s", decipher);
		printf("\nThe name of the generated file is : %s\n", new_file);
	}
	else
	{
		printf("Error in the deciphered text!\n");
	}


/*Closing the files and free the memory!*/
	fclose(file_1);
	fclose(file_2);
	free(text);
	free(decipher);

	return (0);
}
