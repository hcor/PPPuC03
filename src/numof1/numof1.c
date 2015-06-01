/*
 * this is KONG Jing's code.
 * */

#include <stdlib.h>
#include <stdio.h>

int one(unsigned int num)
{
	int i, sum = 0;
	for (i = 0; i < 32; i++) sum += num >> i & 1;
	return sum;
}

int main()
{
	unsigned int num;
	if (scanf("%u", &num) == 1) printf("%d\n", one(num));
	return 0;
}

