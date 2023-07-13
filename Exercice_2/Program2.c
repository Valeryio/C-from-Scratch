#include "../main.h"
#include "string.h"

#define length 200


int main(void)
{
	char source[length] = "The source !", destination[length];

	printf("That is the source : %s \n and the destination : %s\n\n", source, destination);

	mirror(destination, source);

	printf("That is the source : %s \n and the destination : %s", source, destination);

	return (0);
}
