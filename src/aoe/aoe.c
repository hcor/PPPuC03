/*
 * based on ZHU Tianyao's code.
 *
 * the trick is: 'a'-'a'=0, 'e'-'a'=4, 'i'-'a'=8, 'o'-'a'=14, and 'u'-'a'=20.
 *
 * so bitwise SHIFT RIGHT 1065233(0001 0000 0100 0001 0001 0001) by 0, 4, 8,
 * 14, or 20 will give you some xxxxxx1, and then bitwise AND with 1 tells you
 * 1(YES) or 0(NO).
 * */

#include <stdio.h>

#define OFFSET(x) (('A' <= (x) && (x) <= 'Z') ? ((x) - 'A') : ((x) - 'a'))    /* be careful with such things. */

int main()
{
	int c, count = 0;
	//while ((c = getchar()) != '\n')
	while ((c = getchar()) != EOF)
		if (1065233 >> OFFSET(c) & 1)
			count++;
	printf("%d\n", count);
	return 0;
}

