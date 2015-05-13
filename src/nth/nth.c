#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addsuffix.h"    // ../../inc/addsuffix.h

#define MAX    1024

int main(void)
{
	int x;
	char s[MAX];

	memset(s, 0, MAX*sizeof(char));

	printf("Enter your number: ");
	while (scanf("%d", &x) != EOF)
	{
		addSuffix(x, s, MAX);
		printf("%s\n", s);
		printf("Enter your number: ");
	}
	printf("\n");

	return 0;
}

