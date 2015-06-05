#include <stdio.h>

int main()
{
	short n[3], nn[4];
	short i, j, flag;

	nn[0] = 123;
LOOP:
	if ((nn[1]=nn[0]++) > 329) goto EXIT;
	nn[2] = 2 * nn[1]; nn[3] = 3 * nn[1];
	flag = 1;

	for (i = 1; i < 4; i++) {
		for (j = 0; j < 3; j++) {
			n[j] = nn[i] % 10;
			if (!(flag&(1<<n[j]))) flag |= (1<<n[j]);
			else goto LOOP;
			nn[i] /= 10;
		}
	}

	printf("%d %d %d\n", nn[0]-1, 2*(nn[0]-1), 3*(nn[0]-1));
	goto LOOP;

EXIT:
	return 0;
}

