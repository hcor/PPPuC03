/*
 * this is simple and naive ... and maybe buggy :)
 * */

#include <stdlib.h>
#include <stdio.h>

#define MAX    1024

char* strstr(const char *haystack, const char *needle)
{
	const char* hstk;
	const char* ndl;

	if (*needle == 0) return (char*) haystack;

	while (*haystack) {
		if (*haystack == *needle) {
			hstk = haystack + 1;
			ndl  = needle   + 1;
			while (*hstk && *ndl)
				if (*hstk == *ndl) hstk++, ndl++;
				else break;
			if (*ndl == 0) return (char*) haystack;
			if (*hstk == 0) return NULL;
		}
		haystack++;
	}

	return NULL;
}

int main()
{
	char a[MAX], b[MAX];
	char* result;

	//void call_strstr() { result = strstr(a, b); }
	//scanf("%s%s", a, b) == EOF ? exit(1) : call_strstr();

	if (scanf("%s%s", a, b) == 2) {    // better check conversions than EOF.
		result = strstr(a, b);
		if (result) printf("%ld\n", result-a+1);
		else printf("NOT FOUND!\n");
	}

	return 0;
}

