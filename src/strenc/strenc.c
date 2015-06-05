/*
 * that `% 26 + 'a'` calculation is based on WANG Lei's codes (the one that
 * advisor HUO showed us), it makes the code look cleaner, although may cause
 * more computation. but never mind, just burn your CPU :)
 * */

#include <stdio.h>
#include <ctype.h>

int main()
{
	char c;
	int i = 0, delta = 'F' - 'A';

	while ((c = getchar()) != EOF && i++ < 512) {
		if (isalpha(c)) islower(c) ? putchar((c+delta-'a') % 26 + 'a'):
		                             putchar((c+delta-'A') % 26 + 'A');
		else putchar(c);
	}
	putchar('\n');

	return 0;
}

