/*
 * to implement trigonometric functions:
 *
 * - reduce arguments down to a standard interval, since trig functions are 
 *   periodic.
 *
 * - most chips use a CORDIC algorithm to compute the sines and cosines. CORDIC
 *   algorithms are much better suited to efficient hardware implementation 
 *   than Taylor series.
 *
 *   note that the table of values used by CORDIC must be pre-calculated, so, 
 *   Taylor might still be used at "compile time".
 *
 * in GNU libm, the implementation is system-dependent. therefore you can find
 * the implementation, for each platform, somewhere in the appropriate sub-
 * directory of sysdeps, e.g.,
 *
 * [1]: https://sourceware.org/git/?p=glibc.git;a=blob_plain;f=sysdeps/ieee754/dbl-64/s_sin.c;hb=HEAD
 *
 * following is basically KONG Jing's code.
 * */

/*#include <stdio.h>

#define PI 3.141592653589793238462643383279502384197169399375105820974944592

long double powerfact1(long double x, long n)
{
	if (n > 0) return (powerfact1(x, n-1) * x) / n;
	else if (n == 0) return 1;
	else exit(1);
}

long double powerfact2(long double x, long n)
{
	long double pwrft;
	if (n > 0) pwrft = powerfact2(x, n-1) * x;
	else if (n == 0) return 1;
	else exit(1);
	return pwrft / n;
}

long double sine(long double x, long n)
{
	long i, j;
	long double sum = 0;
	for (i = 1; i <= n; i++) {
		if (i % 2 == 0) j = -1;
		else j = 1;
		sum += powerfact1(x, 2*i-1) * j;
	}
	return sum;
}

long double cosine(long double x, long n)
{
	long i, j;
	long double sum = 0;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) j = 1;
		else j = -1;
		sum += powerfact1(x, 2*i) * j;
	}
	return sum;
}

long double exps(long double x, long n)
{
	long i;
	long double sum = 0;
	for (i = 0; i < n; i++)
		sum += powerfact1(x, i);
	return sum;
}

long double logs(long double x, long n)
{
	long i, j;
	long double sum = 0;
	for (i = 1; i < n; i++) {
		if (i % 2 == 0) j = -1;
		else j = 1;
		sum += powerfact2(x, i) * j;
	}
	return sum;
}*/

int main()
{
	/*long double x;
	if (scanf("%LF", &x) == 1) {
		printf("exp = %.6LF\n", exps(x, 4096));
		if (0 < x && x <= 2) printf("log = %.6LF\n", logs(x-1, 4096));
		while (x >= 2 * PI) x -= 2 * PI;
		while (x < 0)       x += 2 * PI;
		printf("sin = %.6LF\n", sine  (x, 2048));
		printf("cos = %.6LF\n", cosine(x, 2048));
	}*/
	return 0;
}

