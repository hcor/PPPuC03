/*
 * Based on CHEN Yubi's code.
 * */

#include <stdio.h>

#define MAX  1024

/* to use the name `strlen`, compile with the option of `-fno-builtin`. */
int strlen(const char s[])
{
	int len = 0;
	while (s[len] != 0)
		len++;
	return len;
}

void squeeze(const char s[], char sqz[])
{
	int i = 0, j = 0;
	while (s[i] != 0) {
		if ( (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') ) {
			sqz[j] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 32 : s[i];
			j++;
		}
		i++;
	}
	sqz[j] = '\0';
}

int huiwen(const char s[])
{
	int i, j;
	for (i = 0, j = (strlen(s)-1); i <= j; i++, j--)
		if (s[i] != s[j])
			return 1;
	return 0;
}

void reverse(const char s[], char r[])
{
	int i, j;
	for (i = (strlen(s)-1), j = 0; i >= 0; i--, j++)
		r[j] = s[i];
	r[j] = '\0';
}

int main()
{
	char s[MAX], sqz[MAX], r[MAX];
	int i = 0;

	while ((s[i] = getchar()) != '\n' && i < MAX)
		i++;
	s[i] = '\0';
	printf("String: %s, length: %d.\n", s, strlen(s));

	squeeze(s, sqz);
	printf("Squeezed: %s, length: %d.\n", sqz, strlen(sqz));

	if (huiwen(sqz)) {
		printf("No!\n");
		reverse(s, r);
		printf("Reversed: %s, length: %d.\n", r, strlen(r));
	} else {
		printf("Yes!\n");
	}

	return 0;
}

