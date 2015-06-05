/*
 * that `% 26 + 'a'` calculation is based on WANG Lei's codes (the one that
 * advisor HUO showed us), it makes the code look cleaner, although may cause
 * more computation. but never mind, just burn your CPU :)
 * */

#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
	char c, *pwd;
	int m, i;
	int delta[16] = { 0 }, *d;

	/* check the argument. */
	if (argc != 2) {
		fprintf(stderr, "usage: %s [your-password]\n", *argv);
		goto EXIT;
	}

	/* check the password. */
	pwd = *(argv+1);
	m = 0; while (isalpha(pwd[m++])); m--;
	if (pwd[m]) {
		fprintf(stderr, "illegal non-alpha password!\n");
		goto EXIT;
	}
	if (m < 2 || m > 16) {
		fprintf(stderr, "illegal password length!\n");
		goto EXIT;
	}

	/* prepare the encryption table. */
	d = delta;
	while (*pwd) *d++ = tolower(*pwd++) - 'a';

	/* encryt the alphabet read from the stdin. */
	for (i = 0; (c = getchar()) != EOF && i < 512; i++) {
		if (isalpha(c)) islower(c) ? putchar((c+delta[i%m]-'a') % 26 + 'a'):
		                             putchar((c+delta[i%m]-'A') % 26 + 'A');
		else putchar(c);
	}

	putchar('\n');

EXIT:
	return 0;
}

