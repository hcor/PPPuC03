/*
 * Based on KONG Jing's code.
 * */

#include <stdio.h>

int min(const int a, const int b)
{
	return (a < b ? a : b);
}

int max(const int a, const int b)
{
	return (a > b ? a : b);
}

int main()
{
	int a, b, c, d;

	printf("请输入四个整数，以逗号间隔；程序将输出最大值、最小值，各占一行。\n");
	if (scanf("%d,%d,%d,%d", &a, &b, &c, &d) != EOF) {
		printf("MAX: %d\n", max(max(a,b), max(c,d)));
		printf("MIN: %d\n", min(min(a,b), min(c,d)));
	}

	return 0;
}

