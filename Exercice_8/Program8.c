#include "../main.h"

#define checker Cesar_text_ciphering_checker

/**
 * main - cipher a file
 *
 * Description: This main is special. It takes a file
 * cipher it, and save it into another file with no error.
 * Return: 0 in all case!
 */

int main(void)
{

	char text_file[100], new_file[100];
	int step = 0;

/*Trying the ciphering_file funtion*/

	printf("\n#####################################################\n");
	printf("####            ENCIPHERING PART                 ####\n");
	printf("#####################################################\n");

	printf("\nWhat is the name of the file you want to cipher : ");
	scanf("%s", text_file);
	strcat(text_file, ".txt");
	printf("\nThat is the name of the text you want to decipher : %s\n", text_file);
		
	printf("\nWhat is the name of the file that will get the ciphered text : ");
	scanf("%s", new_file);
	strcat(new_file, ".txt");

	printf("\nWhat is the step you want to use : ");
	scanf("%d", &step);

	cipher_file(text_file, new_file, step);


/*Trying the deciphering_file function*/

printf("\n#####################################################\n");
printf("####            DECIPHERING PART                 ####\n");
printf("#####################################################\n");

printf("\nWhat is the name of the file you want to decipher : ");
	scanf("%s", text_file);
	strcat(text_file, ".txt");

	printf("\nThat is the name of the text you want to decipher : %s\n", text_file);

	printf("\nWhat is the name of the file that will get the deciphered text : ");
	scanf("%s", new_file);
	strcat(new_file, ".txt");

	printf("\nWhat is the step you want to use : ");
	scanf("%d", &step);

	decipher_file(text_file, new_file, step);


	return (0);
}
