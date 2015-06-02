/*
 * IEEE 754 standard specifies a binary32 as having:
 *
 * - sign bit: 1 bit,
 *
 * - exponent width: 8 bits,
 *
 * - significant precision: 24 bits (23 explicitly stored).
 *
 * the smallest number you can represent is `01000000000000000000000000000000`,
 * which is `1x2^-126 = 1.1754943508222875079687365372222E-38`.
 *
 * the largest value is `011111111111111111111111111111111`, which gives
 * `(1-1/65536)*2^128 = 3.4027717462407992863574607693544E+38`.
 * */

#include <stdio.h>
#include <ctype.h>

#define FLT_MAX         3.402823466e+38F
#define FLT_MAX_10_EXP  38
#define FLT_MAX_EXP     128
#define FLT_MIN         1.175494351e-38F
#define FLT_MIN_10_EXP  (-37)
#define FLT_MIN_EXP     (-125)

#define NEGATIVE  1
#define POSITIVE  0

#define MAX  127

#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

int isfloat(const char *str)
{
	const char *p;
	int sign, mlen, decpt, exp, fexp;
	double fraction, power10;

	/* skip leading spaces and sign. */
	p = str;
	while (isspace(*p)) p++;

	sign = POSITIVE;
	switch (*p) {
		case '-': sign = NEGATIVE;
		case '+': p++;
	}

	/* accumlate the fraction.
	 * count the digits in the mantissa, locate the decimal point and 
	 * prepare the exponent that derives from the fractional part. */
	fraction = 0.0; mlen = 0; decpt = -1;
	while (1) {
		if (isdigit(*p)) {
			if (mlen < 10)    /* if the mantissa has more than 10 digits, ignore the extras. */
				fraction = 10 * fraction + (*p - '0');
			mlen++;
		} else {
			if (*p != '.' || decpt >= 0) break;
			decpt = mlen;
		}
		p++;
	}
	if (mlen == 0) return 0;
	if (decpt < 0) decpt = mlen;
	if (mlen > 10) mlen = 10;
	fexp = decpt - mlen;
	
	/* correct the sign. */
	//if (sign == NEGATIVE) fraction = -fraction;

	/* figure out the exponent. */
	exp = 0; sign = POSITIVE;
	if (*p == 'E' || *p == 'e') {
		switch (*++p) {
			case '-': sign = NEGATIVE;
			case '+': p++;
		}

		while (*p) {
			if (!isdigit(*p)) return 0;
			exp = 10 * exp + (*p++ - '0');
		}
	} else if (*p != 0) {
		return 0;
	}

	if (sign == NEGATIVE) exp = fexp - exp;
	else exp = fexp + exp;

	if (exp < FLT_MIN_EXP || exp > FLT_MAX_EXP) return 0;

	/* scale the result. */
	if (exp < 0) { sign = NEGATIVE; exp = -exp; }
	else { sign = POSITIVE; }

	power10 = 10.;
	while (exp > 0) {
		if (exp & 1)
			if (sign == NEGATIVE) fraction /= power10;
			else fraction *= power10;
		exp >>= 1;
		power10 *= power10;
	}

	//printf("%.9e\n", fraction);
	if (fraction <= FLT_MIN && fraction >= FLT_MAX) return 0;
	
	return 1;
}

int main()
{
	char s[MAX+1];
	if (scanf("%" STRINGIFY(MAX) "s", s) == 1) printf("%d\n", isfloat(s));
	return 0;
}

