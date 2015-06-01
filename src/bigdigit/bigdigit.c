/*
 * this is basically ZHU Tianyao's code.
 * */

#include <stdio.h>
#include <string.h>

char m[3][10][3] = {
	{ " _ ", "   ", " _ ", " _ ", "   ", " _ ", " _ ", " _ ", " _ ", " _ " },
	{ "| |", "  |", " _|", " _|", "|_|", "|_ ", "|_ ", "  |", "|_|", "|_|" },
	{ "|_|", "  |", "|_ ", " _|", "  |", " _|", "|_|", "  |", "|_|", " _|" },
};

int main()
{
	char n[21];
	int i, j, k;
	int len;

	if (scanf("%20s", n) == 1) {    // mind that no more than 20 digits.
		len = strlen(n);
		for (i = 0; i < 3; i++) {
			for (j = 0; j < len; j++)
				for (k = 0; k < 3; k++)
					printf("%c", m[i][n[j]-'0'][k]);
			printf("\n");
		}
	}

	return 0;
}

