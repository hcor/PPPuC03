#include <stdio.h>
#include <ctype.h>

#define LEN  10

#define STRINGIFY(x) STRINGIFY2(x)
#define STRINGIFY2(x) #x

char *months[12] = {
	"January", "February", "March",     "April",   "May",      "June",
	"July",    "August",   "September", "October", "November", "December",
};
unsigned char mdays[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
	char s[LEN+1], *p;
	int year, month, day, i;

	if (scanf("%" STRINGIFY(LEN) "s", s) == 1) {
		p = s;

		year = 0;
		for (i = 0; i < 4; i++)
			if (isdigit(*p)) year = 10*year + (*p++ - '0');
			else goto NaD;
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) mdays[1] = 29;

		if (*p++ != '-') goto NaD;

		month = 0;
		for (i = 0; i < 2; i++)
			if (isdigit(*p)) month = 10*month + (*p++ - '0');
			else goto NaD;
		if (month < 1 || month > 12) goto NaD;

		if (*p++ != '-') goto NaD;

		day = 0;
		for (i = 0; i < 2; i++)
			if (isdigit(*p)) day = 10*day + (*p++ - '0');
			else goto NaD;
		if (day < 1 || day > mdays[month-1]) goto NaD;

		printf("%s %d, %d\n", months[month-1], day, year);
	}

	return 0;

NaD:
	printf("NaD\n"); return 0;
}

