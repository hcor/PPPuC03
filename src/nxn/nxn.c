#include <stdio.h>

int main()
{
	int n, i, j;

	if (scanf("%d", &n) == 1) {
		for (i = 0; i < n; i++) printf(" _"); printf("\n");    /* topmost edge */
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) printf("|_");
			printf("|\n");    /* rightmost edge */
		}
	}

	return 0;
}

