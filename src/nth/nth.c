#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX  1024

#ifdef WIN32
	#define snprintf _snprintf
#endif /* WIN32 */

void addSuffix(int num, char *buf, size_t len)
{
	char *suffixes[4] = { "th", "st", "nd", "rd" };
	int i;

	switch (num % 10) {
		case 1 : i = (num % 100 == 11) ? 0 : 1;
		         break;
		case 2 : i = (num % 100 == 12) ? 0 : 2;
		         break;
		case 3 : i = (num % 100 == 13) ? 0 : 3;
		         break;
		default: i = 0;
	}

	snprintf(buf, len, "%d%s", num, suffixes[i]);
}

int main()
{
	int num;
	char buf[MAX];

	// guys, remember to clean your memory before use.
	memset(buf, 0, sizeof(buf));

	//if (scanf("%d", &num) != EOF) {
	if (scanf("%d", &num) == 1) {    // better check number of conversions than EOF.
		addSuffix(num, buf, sizeof(buf));
		printf("%s\n", buf);
	}

	return 0;
}

