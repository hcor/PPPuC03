#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX    1024

int palindrome(const char* s, int begin, int end)
{
	if ((end-1) <= begin) return 1;
	if (s[begin] != s[end-1]) return 0;
	return palindrome(s, begin+1, end-1);
}

int main()
{
	char s[MAX];
	int len;

	// guys, remember to clean your memory before use.
	memset(s, 0, sizeof(s));

	printf("Enter your string (less than %d charactors): ", MAX);
	//if (scanf("%s", s) != EOF) {
	if (scanf("%s", s) != EOF) {    // better check conversions than EOF.
		len = strlen(s);
		printf("%s!\n", palindrome(s, 0, len) ? "Y" : "N");
	}

	return 0;
}

