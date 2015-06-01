/*
 * this is simple and naive ... and maybe buggy :)
 * */

#include <stdlib.h>
#include <stdio.h>

#define MAX 1024
#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

char *strstr(const char *haystack, const char *needle)
{
	const char *hstk;
	const char *ndl;

	if (!*needle) return (char *) haystack;

	while (*haystack) {
		if (*haystack == *needle) {
			hstk = haystack + 1;
			ndl  = needle   + 1;
			while (*hstk && *ndl)
				if (*hstk == *ndl) hstk++, ndl++;
				else break;
			if (!*ndl) return (char *) haystack;
			if (!*hstk) return NULL;
		}
		haystack++;
	}

	return NULL;
}

int main()
{
	char a[MAX+1], b[MAX+1];
	char* result;

	//void call_strstr() { result = strstr(a, b); }
	//scanf("%s%s", a, b) == EOF ? exit(1) : call_strstr();

	if (scanf("%" STRINGIFY(MAX) "s%" STRINGIFY(MAX) "s", a, b) == 2) {
		result = strstr(a, b);
		if (result) printf("%ld\n", result-a+1);
		else printf("NOT FOUND!\n");
	}

	return 0;
}

