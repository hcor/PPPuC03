/*
 * this is stupid and ugly.
 *
 * burn the CPU, play no trick.
 * */

#include <stdio.h>

#define ORDER  4
#define N      16    // (ORDER*ORDER)

int main()
{
	int s[N], count = 0;
	int msum = (1 + N) * N / 2 / ORDER;
	unsigned char i, n[N] = { 0 };

	//#pragma omp parallel for firstprivate(s, n) reduction(+:count)
	for (s[0] = 1; s[0] <= N; s[0]++)
	if (!n[s[0]-1]) {
	n[s[0]-1] = 1;

	for (s[1] = 1; s[1] <= N; s[1]++)
	if (!n[s[1]-1]) {
	n[s[1]-1] = 1;

	for (s[2] = 1; s[2] <= N; s[2]++)
	if (!n[s[2]-1]) {
	n[s[2]-1] = 1;

	for (s[3] = 1; s[3] <= N; s[3]++)
	if (!n[s[3]-1]) {
	n[s[3]-1] = 1;

	if (s[0]+s[1]+s[2]+s[3] == msum)

		for (s[4] = 1; s[4] <= N; s[4]++)
		if (!n[s[4]-1]) {
		n[s[4]-1] = 1;

		for (s[5] = 1; s[5] <= N; s[5]++)
		if (!n[s[5]-1]) {
		n[s[5]-1] = 1;

		for (s[6] = 1; s[6] <= N; s[6]++)
		if (!n[s[6]-1]) {
		n[s[6]-1] = 1;

		for (s[7] = 1; s[7] <= N; s[7]++)
		if (!n[s[7]-1]) {
		n[s[7]-1] = 1;

		if (s[4]+s[5]+s[6]+s[7] == msum)

			for (s[8] = 1; s[8] <= N; s[8]++)
			if (!n[s[8]-1]) {
			n[s[8]-1] = 1;
	
			for (s[9] = 1; s[9] <= N; s[9]++)
			if (!n[s[9]-1]) {
			n[s[9]-1] = 1;
	
			for (s[10] = 1; s[10] <= N; s[10]++)
			if (!n[s[10]-1]) {
			n[s[10]-1] = 1;
	
			for (s[11] = 1; s[11] <= N; s[11]++)
			if (!n[s[11]-1]) {
			n[s[11]-1] = 1;

			if (s[8]+s[9]+s[10]+s[11] == msum)

				for (s[12] = 1; s[12] <= N; s[12]++)
				if (!n[s[12]-1]) {
				n[s[12]-1] = 1;
				if (s[0]+s[4]+s[8]+s[12] == msum && s[3]+s[6]+s[9]+s[12] == msum)

				for (s[13] = 1; s[13] <= N; s[13]++)
				if (!n[s[13]-1]) {
				n[s[13]-1] = 1;
				if (s[1]+s[5]+s[9]+s[13] == msum)

				for (s[14] = 1; s[14] <= N; s[14]++)
				if (!n[s[14]-1]) {
				n[s[14]-1] = 1;
				if (s[2]+s[6]+s[10]+s[14] == msum)

				for (s[15] = 1; s[15] <= N; s[15]++)
				if (!n[s[15]-1]) {
				n[s[15]-1] = 1;
				if (s[3]+s[7]+s[11]+s[15] == msum && s[0]+s[5]+s[10]+s[15] == msum)

					if (s[12]+s[13]+s[14]+s[15] == msum) {
						for (i = 0; i < N; i++) {
							if (i%4 == 0) printf("\n");
							printf("%2d  ", s[i]);
						}
						printf("\n");
						count++;
					}
				
				n[s[15]-1] = 0;
				}

				n[s[14]-1] = 0;
				}

				n[s[13]-1] = 0;
				}

				n[s[12]-1] = 0;
				}

			n[s[11]-1] = 0;
			}

			n[s[10]-1] = 0;
			}

			n[s[9]-1] = 0;
			}

			n[s[8]-1] = 0;
			}

		n[s[7]-1] = 0;
		}

		n[s[6]-1] = 0;
		}

		n[s[5]-1] = 0;
		}

		n[s[4]-1] = 0;
		}

	n[s[3]-1] = 0;
	}

	n[s[2]-1] = 0;
	}

	n[s[1]-1] = 0;
	}
	
	n[s[0]-1] = 0;
	}

	printf("\nFOUND: %d\n", count);

	return 0;
}

