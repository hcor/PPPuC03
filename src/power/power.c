#include <stdio.h>
#include <stdlib.h>

int power(int base, int exp)
{
	int pwr;

	if (exp == 0) return 1;

	pwr = power(base, exp/2);    /* FU Xin asked for this change. */
	if (exp % 2 == 0) {
		//pwr = power(base, exp/2);
		return pwr * pwr;
	} else {
		//return base * power(base, exp-1);
		return base * pwr * pwr;
	}
}

int main(int argc, char *argv[])
{
	if (argc != 3) {
		fprintf(stderr, "Usage: %s [BASE] [EXP]\n", argv[0]);
		exit(1);
	}

	/* i'm lazy so i just use `strtol()` :-) */
	printf("%d\n", power(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10)));

	return 0;
}

