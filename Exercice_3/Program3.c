#include "../main.h"

#define length 200


int main(void)
{

	int result = 0;

	char source[length] = "polycopie", sub[length] = "polycopie";


	printf("\nWe'll verify is the substring is a part of the original string\n");


	result = is_factor(sub, source);


	if(result)
	{
		printf("\nThe substring is a part of the original string\n");
	}
	else
	{
		printf("\nThe substring is not a part of the original string\n");
	}



	return (0);
}
