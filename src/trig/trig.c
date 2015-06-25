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
 * another interesting link:
 *
 * [2]: http://lolengine.net/blog/2011/12/21/better-function-approximations
 *
 * following is based on KONG Jing's code.
 * */

#include <stdio.h>

#define PI    3.14159265358979323846
#define PI_2  1.57079632679489661923

double powerfact(double x, long n)
{
	if (n > 0) return (powerfact(x, n-1) * x) / n;
	else if (n == 0) return 1;
	else return 0;
}

double sine(double x/*, long n*/)
{
	//long i = 1, s = 1;
	int i = 1, s = 1;
	double pf, sum = 0;
	//for (i = 1; i <= n; i++) {
	//	if (i%2) s = 1; else s = -1;
	//	sum += powerfact(x, 2*i-1) * s;
	//}
	while (1) {
		pf = powerfact(x, 2*i-1);
		if (-1e-16 < pf && pf < 1e-16) break; else sum += pf * s;
		i++; s *= -1;
	}
	return sum;
}

double cosine(double x/*, long n*/)
{
	//long i = 0, s = 1;
	int i = 0, s = 1;
	double pf, sum = 0;
	//for (i = 0; i < n; i++) {
	//	if (i%2) s = -1; else s = 1;
	//	sum += powerfact(x, 2*i) * s;
	//}
	while (1) {
		pf = powerfact(x, 2*i);
		if (-1e-16 < pf && pf < 1e-16) break; else sum += pf * s;
		i++; s *= -1;
	}
	return sum;
}

int main()
{
	double x;
	double s, c;
	if (scanf("%lf", &x) == 1) {
		/* range reduction. */
		while (x >= 2*PI) x -= 2*PI;
		while (x < 0)     x += 2*PI;

		/* sin -> -PI/2~PI/2, cos -> 0~PI. */
		if (0 <= x && x < PI_2)             s = x,        c = x;
		else if (PI_2 <= x && x < PI)       s = PI - x,   c = x;
		else if (PI <= x && x < PI+PI_2 )   s = PI - x,   c = 2*PI - x;
		else if (PI <= PI+PI_2 && x < 2*PI) s = x - 2*PI, c = 2*PI - x;
		
		printf("sin = %.6lf\n", sine  (s/*, 2048*/));
		printf("cos = %.6lf\n", cosine(c/*, 2048*/));
	}
	return 0;
}

