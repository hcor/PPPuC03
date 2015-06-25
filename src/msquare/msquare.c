/*
 * this is stupid and ugly.
 *
 * i'm not clever and have no idea about how to play the order-4 magic square 
 * game, so i just brute-force-attack the problem, and am too lazy to check 
 * the "replicated" ones: burn the CPU, and play no trick.
 *
 * to use OpenMP to take advantage of all your cores, compile with `-fopenmp`.
 *
 * in my codes, i didn't check the number of threads (to make those compilers
 * without omp support work), so since N equals to 16, 16 threads most will be
 * enough.
 * */

#include <stdio.h>
#include <stdlib.h>

#define ORDER  4
#define N      16    /* (ORDER*ORDER) */

#ifdef __GNUC__
	typedef unsigned byte16 __attribute__ ((mode (TI)));
	typedef unsigned char int8;
#endif  /* __GNUC__ */

#ifdef _MSC_VER
	typedef unsigned /*__int128*/ byte16;    /* this is wrong; M$ cl doesn't have `__int128`. */
	typedef char int8;
#endif  /* _MSC_VER */

int main()
{
	int msum = (1 + N) * N / 2 / ORDER - ORDER, count = 0, i;
	byte16 s16;          /* 16 bytes: each for one number/cell. */
	int8 *s, s0;
	unsigned short n;    /* 16 bits: each indicates a number.   */

	#pragma omp parallel firstprivate(msum) private(s16, s, n)
	{
	s = (int8 *) &s16; n = 0;
	#ifdef _MSC_VER    /* is there a 16-byte data type in M$ VS??? */
	s = (int8 *) malloc(N * sizeof(int8));
	#endif

	#pragma omp for reduction(+:count)
	for (s0 = 0; s0 < N; s0++) {    /* s0: just to make omp compile ... */
	//for (*s = 0; *s < N; (*s)++) {
	s[0] = s0;
	if (!(n&(1<<s[0]))) {
	n |= (1<<s[0]);

	for (s[1] = 0; s[1] < N; s[1]++)
	if (!(n&(1<<s[1]))) {
	n |= (1<<s[1]);

	for (s[2] = 0; s[2] < N; s[2]++)
	if (!(n&(1<<s[2]))) {
	n |= (1<<s[2]);

	for (s[3] = 0; s[3] < N; s[3]++)
	if (!(n&(1<<s[3]))) {
	n |= (1<<s[3]);

	if (s[0]+s[1]+s[2]+s[3] == msum)

		for (s[4] = 0; s[4] < N; s[4]++)
		if (!(n&(1<<s[4]))) {
		n |= (1<<s[4]);

		for (s[5] = 0; s[5] < N; s[5]++)
		if (!(n&(1<<s[5]))) {
		n |= (1<<s[5]);

		for (s[6] = 0; s[6] < N; s[6]++)
		if (!(n&(1<<s[6]))) {
		n |= (1<<s[6]);

		for (s[7] = 0; s[7] < N; s[7]++)
		if (!(n&(1<<s[7]))) {
		n |= (1<<s[7]);

		if (s[4]+s[5]+s[6]+s[7] == msum)

			for (s[8] = 0; s[8] < N; s[8]++)
			if (!(n&(1<<s[8]))) {
			n |= (1<<s[8]);

			for (s[9] = 0; s[9] < N; s[9]++)
			if (!(n&(1<<s[9]))) {
			n |= (1<<s[9]);

			for (s[10] = 0; s[10] < N; s[10]++)
			if (!(n&(1<<s[10]))) {
			n |= (1<<s[10]);

			for (s[11] = 0; s[11] < N; s[11]++)
			if (!(n&(1<<s[11]))) {
			n |= (1<<s[11]);

			if (s[8]+s[9]+s[10]+s[11] == msum)

				for (s[12] = 0; s[12] < N; s[12]++)
				if (!(n&(1<<s[12]))) {
				n |= (1<<s[12]);

				if (s[0]+s[4]+s[8]+s[12] == msum && s[3]+s[6]+s[9]+s[12] == msum)

				for (s[13] = 0; s[13] < N; s[13]++)
				if (!(n&(1<<s[13]))) {
				n |= (1<<s[13]);

				if (s[1]+s[5]+s[9]+s[13] == msum)

				for (s[14] = 0; s[14] < N; s[14]++)
				if (!(n&(1<<s[14]))) {
				n |= (1<<s[14]);

				if (s[2]+s[6]+s[10]+s[14] == msum)

				for (s[15] = 0; s[15] < N; s[15]++)
				if (!(n&(1<<s[15]))) {
				n |= (1<<s[15]);

				if (s[3]+s[7]+s[11]+s[15] == msum && s[0]+s[5]+s[10]+s[15] == msum)

					if (s[12]+s[13]+s[14]+s[15] == msum) {
						for (i = 0; i < N; i++) {
							if (i%4 == 0) printf("\n");
							printf("%2d  ", s[i]+1);
						}
						printf("\n");
						count++;
					}

				n ^= (1<<s[15]);
				}

				n ^= (1<<s[14]);
				}

				n ^= (1<<s[13]);
				}

				n ^= (1<<s[12]);
				}

			n ^= (1<<s[11]);
			}

			n ^= (1<<s[10]);
			}

			n ^= (1<<s[9]);
			}

			n ^= (1<<s[8]);
			}

		n ^= (1<<s[7]);
		}

		n ^= (1<<s[6]);
		}

		n ^= (1<<s[5]);
		}

		n ^= (1<<s[4]);
		}

	n ^= (1<<s[3]);
	}

	n ^= (1<<s[2]);
	}

	n ^= (1<<s[1]);
	}

	n ^= (1<<s[0]);
	}

	} /* omp for */

	#ifdef _MSC_VER
	free(s);
	#endif
	} /* omp parallel */

	printf("\nFOUND: %d\n", count);

	return 0;
}

