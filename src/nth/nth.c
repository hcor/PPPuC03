#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX    1024

void addSuffix(int num, char* buf, size_t len)
{
	char *suffixes[4] = { "th", "st", "nd", "rd" };
	int i;

	switch (num % 10)
	{
		case 1 : i = (num % 100 == 11) ? 0 : 1;
		         break;
		case 2 : i = (num % 100 == 12) ? 0 : 2;
		         break;
		case 3 : i = (num % 100 == 13) ? 0 : 3;
		         break;
		default: i = 0;
	};

	snprintf(buf, len, "%d%s", num, suffixes[i]);
}

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

