#include <stdio.h>
#include <ctype.h>

struct charinfo {
	char c;
	int count;
};

int main()
{
	int n;
	struct charinfo alpha[26] = {0};

	for (n = 0; n < 26; n++) alpha[n].c = 'a' + n;

	while ((n = getchar()) != EOF)
		if (isalpha(n)) alpha[tolower(n)-'a'].count++;

	for (n = 0; n < 26; n++) printf("%c  %d\n", alpha[n].c, alpha[n].count);

	return 0;
}

