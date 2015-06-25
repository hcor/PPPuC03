#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024
#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

int palindrome(const char *s, int begin, int end)
{
	if ((end-1) <= begin) return 1;
	if (s[begin] != s[end-1]) return 0;
	return palindrome(s, begin+1, end-1);
}

int main()
{
	char s[MAX+1];
	int len;

	/* guys, remember to clean your memory before use. */
	memset(s, 0, sizeof(s));

	//if (scanf("%s", s) != EOF) {
	if (scanf("%" STRINGIFY(MAX) "s", s) == 1) {    /* better check conversions than EOF. */
		len = strlen(s);
		printf("%s!\n", palindrome(s, 0, len) ? "Y" : "N");
	}

	return 0;
}

