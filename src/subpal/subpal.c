/*
 * The longest palindromic substring or longest symmetric factor problem is the
 * problem of finding a maximum-length contiguous substring of a given string
 * that is also a palindrome. For example, the longest palindromic substring of
 * "bananas" is "anana".
 *
 * Manacher (1975) found a linear time algorithm for listing all the palin-
 * dromes that appear at the start of a given string. However, as observed 
 * e.g., by Apostolico, Breslauer & Galil (1995), the same algorithm can also 
 * be used to find all maximal palindromic substrings anywhere within the 
 * input string, again in linear time. Therefore, it provides a linear time 
 * solution to the longest palindromic substring problem. Alternative linear 
 * time solutions were provided by Jeuring (1994), and by Gusfield (1997), who 
 * described a solution based on suffix trees. Efficient parallel algorithms 
 * are also known for the problem.
 *
 * References:
 * [1]: http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-i.html
 * [2]: http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
 *
 * Following is a dynamic programming solution, and is based on ref[1].
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __GNUC__
	#include <stdbool.h>
#endif /* __GNUC__ */

#if _MSC_VER && !__INTEL_COMPILER && !__cplusplus
	#define bool int
	#define true  1
	#define false 0
#endif /* _MSC_VER && !__INTEL_COMPILER */

#define MAX 4096
#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

int main()
{
	int start, maxLen;
	int i, j, k, len;
	char str[MAX+1];
	bool **table;    // if substring [i...j] is a palindrome, table[i][j] will be true.
	//bool table[MAX][MAX];    // this is local, and for big MAX, it would overflow the stack at the runtime.
	//                         // making them static or global will avoid segfault.
	//                         // remember that space for local data on call stack is always a scare resource.
	//bool *table;    // just malloc(r*c*sizeof(type)), and table[i][j] should be table[i*c+j], or *(table+i*c+j).

	if (scanf("%" STRINGIFY(MAX) "s", str) == 1) len = strlen(str);    // less than 4096 bytes.
	else exit(1);

	for (i = 0; i < len; i++)    // turn all charactors into lowercase.
		str[i] = (('A'<=str[i]) && (str[i]<='Z')) ? 'a'+(str[i]-'A') : str[i];

	table = malloc(len*sizeof(bool *) + len*len*sizeof(bool));    // dynamically allocate the table array.
	*table = (bool *)(table + len);
	for (i = 1; i < len; i++)
		*(table+i) = *table + i*len;
	memset(*table, 0, len*len*sizeof(bool));

	maxLen = 1;
	for (i = 0; i < len; i++)
		table[i][i] = true;    // one single char is a palindrome.

	start = 0;
	for (i = 0; i < len-1; i++) {    // check all sub-strings of length 2.
		if (str[i] == str[i+1]) {
			table[i][i+1] = true;
			start = i;
			maxLen = 2;
		}
	}

	for (k = 3; k <= len; k++) {   // check sub-strings of length greater than 2 (k).
		for (i = 0; i < len-k+1; i++) {    // i is the starting index.
			j = i + k - 1;             // j is the ending index.
			if (table[i+1][j-1] && str[i] == str[j]) {    // if str[i+1...j-1] is a palindrome and str[i] equals to str[j],
				table[i][j] = true;                   // then str[i...j] is a palindrome.
				if (k > maxLen) {
					start = i;
					maxLen = k;
				}
			}
		}
	}

	for (i = start; i < start + maxLen; i++)    // print the longest palindrome sub-string.
		printf("%c", str[i]);
	printf("\n%d\n", maxLen);    // print the length of longest sub-palindrome.

	free(table);    // never forget to release your "malloc"ed memory.

	return 0;
}

