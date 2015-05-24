/*
 * Based on LAN Qingfeng's codes.
 * */

#include <stdio.h>

#define MAX    10000

int main()
{
	int i, j, sum;
	for (i = 1; i <= MAX; i++) {
		sum = 0;
		for (j = 1; j < i; j++)
			if (i % j == 0) sum += j;
		if (sum == i) printf("%d\n", sum);
	}
	return 0;
}

