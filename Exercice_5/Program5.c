#include "../main.h"

void main(int argc, char* argv[])
{
	if (argc < 3)
	{
		printf("%s : Usage %s <mot-1> <mot-2>\n", argv[0], argv[0]);
		return;
	}
	printf("\t%s\n\t%s\n", argv[2], argv[1]);
}
