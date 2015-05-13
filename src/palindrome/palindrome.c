#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

#define MAX    1024

int main()
{
	char s[MAX];
	int len;

	memset(s, 0, MAX*sizeof(char));

	printf("Enter your string (less than %d charactors): ", MAX);
	while (scanf("%s", s) != EOF)
	{
		len = strlen(s);
		printf("%s!\n", palindrome(s, 0, len) ? "Y" : "N");
		printf("Enter your string (less than %d charactors): ", MAX);
	}
	printf("\n");

	return 0;
}

