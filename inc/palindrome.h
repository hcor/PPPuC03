#ifndef _PALINDROME_H_
#define _PALINDROME_H_ 1

#include <stdio.h>

int palindrome(const char* s, int begin, int end)
{
	if ( (end-1) <= begin ) return 1;
	if ( s[begin] != s[end-1] ) return 0;
	return palindrome(s, begin+1, end-1);
}

#endif /* _PALINDROME_H_ */

