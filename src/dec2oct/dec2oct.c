#include <stdio.h>

#define LEN 5

int main()
{
	int num, i;
	char oct[LEN+1] = { 0 };    // if an array is partially initialized, elements that are not initialized 
	                            // receive the value 0 of the appropriate type.
	if (scanf("%d", &num) == 1)
		if (0 <= num && num <= 32767) {
			for (i = LEN; i > 0; i--) {
				oct[i-1] = num % 8 + '0';
				num /= 8;
			}
			printf("%s\n", oct);
		}
	return 0;
}

