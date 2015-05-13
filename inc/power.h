/*
 * Remeber to take the benefit of recursion to reduce the number of 
 * multiplication operations required, e.g., if n=8, then is much more 
 * efficient to compute x*x as val1, then val1*val1 as val2, and the final 
 * answer is val2*val2 as val3, rather than to compute x*x*x*x*x*x*x*x 
 * (7 multiplications).
 * */

#ifndef _POWER_H_
#define _POWER_H_ 1

int power(const int base, const int exp)
{
	int pwr;

	if (exp == 0) return 1;

	if (exp % 2 == 0)
	{
		pwr = power(base, exp/2);
		return pwr * pwr;
	}
	else
	{
		return base * power(base, exp-1);
	}
}

#endif /* _POWER_H_ */

