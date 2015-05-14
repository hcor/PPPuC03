#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "addsuffix.h"    // ../../inc/addsuffix.h

#define MAX    1024

int main(void)
{
	int x;
	char s[MAX];

	// guys, remember to clean your memory before use.
	memset(s, 0, MAX*sizeof(char));

	printf("Enter your number: ");
	if (scanf("%d", &x) != EOF) {
		addSuffix(x, s, MAX);
		printf("%s\n", s);
	}

	return 0;
}

