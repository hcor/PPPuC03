#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palindrome.h"

#define MAX    1024

int main(void)
{
	char s[MAX];
	int len;

	// guys, remember to clean your memory before use.
	memset(s, 0, MAX*sizeof(char));

	printf("Enter your string (less than %d charactors): ", MAX);
	if (scanf("%s", s) != EOF) {
		len = strlen(s);
		printf("%s!\n", palindrome(s, 0, len) ? "Y" : "N");
	}

	return 0;
}

