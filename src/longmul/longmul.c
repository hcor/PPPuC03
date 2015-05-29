/*
 * An integer in C is typically 32 bits, of which 31 can be used for positive 
 * integer arithmetic. This is good for representing numbers up to about 2 
 * billion (2147483648). A "long long" type gives 64 bits capable of 
 * representing about 9 quintillion (9.223372037×10^18).
 *
 * Some applications may require many more digits than this. For example, 
 * public-key encryption with the RSA algorithm typically requires 300 digit 
 * numbers.
 *
 * For such problems, we must move to a different representation of integers. 
 * We can represent a number as a sequence of digits stored in an array of 
 * integers, or we can simply use char arrays. We can write functions to add, 
 * multiply, etc. on those arrays, and then make them as large as we want.
 *
 * To do the calculation, we may have the following options:
 *
 * - Just stay simple and stupid, and do it the same way you would do it with 
 *   a paper and pencil; this is a naive algorithm (O(n^2)).
 *
 * - Use Karatsuba multiplication algorithm, it's a Divide-and-Conquer 
 *   strategy (O(n^1.59)).
 *
 * - Use Fast Fourier Transform (FFT multiplication), and the multiplication 
 *   of large numbers of n digits can be done in time O(nlog(n)).
 *
 * - Or just use boost multiprecision or the GNU MP Bignum Library, and never 
 *   ever give it a damn :)
 *
 * References
 *
 * [1]: http://faculty.cse.tamu.edu/djimenez/ut/utsa/cs3343/lecture20.html
 * [2]: http://www.quora.com/How-do-I-multiply-two-large-numbers-stored-as-strings-in-the-C-C++-language
 * [3]: http://www.geeksforgeeks.org/divide-and-conquer-set-2-karatsuba-algorithm-for-fast-multiplication
 * [4]: http://courses.csail.mit.edu/6.006/spring11/exams/notes3-karatsuba
 * [5]: http://www.thinbasic.com/community/showthread.php?11206-C-multiplying-big-integers
 * [6]: http://numbers.computation.free.fr/Constants/Algorithms/fft.html
 * [7]: http://www.codeproject.com/Articles/106932/Addition-Multiplication-of-Very-Long-Integers
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
/* c = a * b. */ 
void longmul(const char *a, const char *b, char *c)
{
	int i = 0, j = 0, k = 0; 
	int n, carry;
	int la, lb;
 
	/* zero will be zero. */
	if (!strcmp(a,  "0") || !strcmp(b,  "0") || 
	    !strcmp(a, "-0") || !strcmp(b, "-0")) {
		c[0] = '0', c[1] = '\0';
		return;
	}
 
	/* see if either a or b is negative */
	if (a[0] == '-') { i = 1; k = !k; }
	if (b[0] == '-') { j = 1; k = !k; }
	if (i || j) {
		if (k) c[0] = '-';
		a += i; b += j; c += k;
	}

	/* prepare the "c" char array. */	
	la = strlen(a);
	lb = strlen(b);
	memset(c, '0', la + lb);
	c[la + lb] = '\0';

	/* do the multiplication as if by hand. */	
#	define I(a) (a - '0')
	for (i = la - 1; i >= 0; i--) {
		for (j = lb - 1, k = i + j + 1, carry = 0; j >= 0; j--, k--) {
			n = I(a[i]) * I(b[j]) + I(c[k]) + carry;
			carry = n / 10;
			c[k] = (n % 10) + '0';
		}
		c[k] += carry;
	}
#	undef I
	if (c[0] == '0') memmove(c, c + 1, la + lb);
 
	return;
}
 
int main(int argc, char *argv[])
{
	char c[1024];

	if (argc != 3)  {
		fprintf(stderr, "Usage: %s [NUM-A] [NUM-B]\n", argv[0]);
		exit(1);
	}

	// longmul("-18446744073709551616", "18446744073709551616", c);
	longmul(argv[1], argv[2], c);
	printf("%s\n", c);

	return 0;
}

