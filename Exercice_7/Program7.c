#include "../main.h"


int main(void)
{
	FILE *str_1 = NULL, *str_2 = NULL, *str_3 = NULL;
	char str_tmp[100];


	str_1 = fopen("spiderman_1.txt", "r");
	if (!str_1)
	{
		perror("\nError, cannot open the file!\n");
		exit(EXIT_FAILURE);
	}


	str_2 = fopen("spiderman_2.txt", "r");
	if (!str_2)
	{
		perror("\nError, cannot open the file!\n");
		exit(EXIT_FAILURE);
	}


	printf("\nWhat is the name of the new text file : ");
	scanf("%s", str_tmp);

	printf("\nName of the new file : %s.txt\n", str_tmp);
	strcat(str_tmp, ".txt");

	str_3 = fopen(str_tmp, "wt+");
	if (!str_3)
	{
		perror("\nError, cannot open the file\n");
		exit(EXIT_FAILURE);
	}

/*Concatenation of the two files*/
	file_concat(str_1, str_2, str_3);


	fclose(str_1);
	fclose(str_2);

	return (0);
}
