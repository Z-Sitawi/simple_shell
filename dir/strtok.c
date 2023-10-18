#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char str[] = "  ds  i'll split this string";
	char* piece = strtok(str, " ");

	while(piece != NULL)
	{
		printf("%s\n", piece);
		piece = strtok(NULL, " ");
	}
	return (0);
}
