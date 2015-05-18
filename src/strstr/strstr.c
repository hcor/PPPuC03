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

	void call_strstr() { result = strstr(a, b); }            // i know this is wired ... and that use of EOF may be wrong ...
	scanf("%s%s", a, b) == EOF ? exit(1) : call_strstr();    // i just want to shut that annoying warn_unused_result warning ...
	                                                         // i know i'm stupid ... :)
	if (result) printf("%ld\n", result-a+1);
	else printf("NOT FOUND!\n");
	return 0;
}

