#include <stdio.h>

int main()
{
	double salary, tax;
	if (scanf("%lf", &salary) == 1) {
		if (0 < salary && salary <= 750)
			tax = salary * 0.02;
		else if (750 < salary && salary <= 2250)
			tax = 15  + (salary- 750)*0.05;
		else if (2250 < salary && salary <= 3750)
			tax = 90  + (salary-2250)*0.08;
		else if (3750 < salary && salary <= 5250)
			tax = 210 + (salary-3750)*0.10;
		else if (5250 < salary && salary <= 7000)
			tax = 360 + (salary-5250)*0.20;
		else if (salary > 7000)
			tax = 710 + (salary-7000)*0.30;
		printf("%.2lf\n", tax);
	}
	return 0;
}

