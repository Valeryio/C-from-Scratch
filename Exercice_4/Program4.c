#include "../main.h"


int main(void)
{
	int index = 0, int_answer;

	char *endprt = NULL;

	char char_answer;

	char *language[100] = {"chat", "chien", "oiseau", "voiture", "maison", "arbre", "soleil", "mer", "montagne", "étoie"};


	char *language_1[100] = {"chat", "chien", "oiseau", "voiture", "maison", "arbre", "soleil", "mer", "montagne", "étoi"};


	char *language_2[100] = {"chat", "lion", "chien", "oiseau", "voiture", "maison", "arbre", "soleil", "mer", "étol"};
	


	printf("\n#######################################################################################################################################################");
	printf("\n######   |||   |||  |||||||  |||    ||  ||  ||||||||   ||   ||  ||       |||||||  ||||||||   ||   |||||||   |||    ||              00000     #######");
	printf("\n######   || | | ||  ||   ||  || |   ||  ||  ||    ||   ||   ||  ||       ||   ||     ||      ||   ||   ||   || |   ||     00000000 00        #######");
	printf("\n######   ||  |  ||  |||||||  ||  |  ||  ||  ||||||||   ||   ||  ||       |||||||     ||      ||   ||   ||   ||  |  ||     00    00 00000     #######");
	printf("\n######   ||     ||  ||   ||  ||   | ||  ||  ||         ||   ||  ||       ||   ||     ||      ||   ||   ||   ||   | ||     00    00 00        #######");
	printf("\n######   ||     ||  ||   ||  ||    |||  ||  ||         |||||||  |||||||  ||   ||     ||      ||   |||||||   ||    |||     00000000 00        #######");
	printf("\n######                                                                                                                             00        #######");
	printf("\n#######################################################################################################################################################");

	printf("\n#######################################################################################################################################################");
	printf("\n######   ||         |||||||  |||    ||  |||||||||    ||   ||    |||||||     ||||||||   |||||||||                                             #######");
	printf("\n######   ||         ||   ||  || |   ||  ||           ||   ||    ||   ||     ||         ||   ||||                                             #######");
	printf("\n######   ||         |||||||  ||  |  ||  ||  |||||    ||   ||    |||||||     ||  |||||  |||||||||                                             #######");
	printf("\n######   ||         ||   ||  ||   | ||  ||    |||    ||   ||    ||   ||     ||     ||  ||                                                    #######");
	printf("\n######   |||||||||  ||   ||  ||    |||  |||||||||    |||||||    ||   ||     |||||||||  |||||||||                                             #######");
	printf("\n######                                                                                                                                       #######");
	printf("\n#######################################################################################################################################################");



	printf("\n\nThat's a program of manipulation of a language(series of word in a big array).\n\n");

	printf("You can use all the functions that we wrote in the library. But if you want to test them before, here it's a little program to help you.\n");
	printf("There is a language generated here, on which you can perform some operations.\n");

	printf("\nLanguage 1 : "); show_language(language);
	printf("\nLanguage 2 : "); show_language(language_1);
	printf("\nLanguage 3 : "); show_language(language_2);
	

	printf("\n\nOptions : \n\n1- Show a language (print it)\n\n2- Verify if two language are distincts.( a - more explanations)\n\n3- Add a word to a language\n\n");
	printf("4- Gather two languages. (b- More explanations)\n\n5- Remove a word from a language.\n");
	printf("\nEnjoy ! ('v')\n\nAnswer : ");

	scanf("%s", &char_answer);
	

	switch (char_answer)
	{

		case '1' :

			printf("\nVerification if \"chien\" is in the language !\n");

			if (element_of("chien", language))
			{
				printf("\n Answer : YES \n");
			}
			else
			{
				printf("\n Answer : NO \n");
			}
		break;


		case '2' :
		
			printf("\nVerification if the two languages are disjoint.\n");

			if (is_disjoint(language, language_2))
			{
				printf("\n Answer : YES \n");
			}
			else
			{
				printf("\n Answer : NO \n");
			}
		break;


		case '3' :

			printf("\nVerification of the function that add a word.");

			index = add_word("eagle", language_1);
			index = add_word("best", language_1);

			printf("\nThe index of the word you want to use is : %d\n", index);
		break;

		case '4' :

			printf("Verification of the function that gather two language");

			gather_lang(language_1, language);
		break;

		case '5' :

			printf("\n\nVerification of the function that remove a word\n");

			remove_word("chien", language);

			show_language(language);

		break;

		case 'a' :

			printf("\nIf there is a single word that is in a language and not in the other then, the two languages are disjoints!\n");
		break;

		case 'b' :

			printf("\nThat's simple, gather two languages, is take the first one, and add all the word that are in the second, but not present in the first! That's all.\n");
		break;

		default:
		break;
	}

	printf("\n");

	return (0);
}
