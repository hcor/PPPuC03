#include <stdio.h>
#include <stdlib.h>

#include "power.h"    // ../../inc/power.h

int main(int argc, char *argv[])
{
	if (argc != 3) 
	{
		fprintf(stderr, "Usage: %s [BASE] [EXP]\n", argv[0]);
		exit(1);
	}

	// i'm lazy so i just use `strtol()` :-)
	printf("%d\n", power(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10)));

	return 0;
}

