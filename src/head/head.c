/*
 * based on ZHU Tianyao's code.
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX    1024

int main(int argc, char *argv[])
{
	int i = 0, n = -1;
	char c[MAX];
	char *ep;
	char *prog = *argv;

	if (argc != 3) {    // check the argument count.
		fprintf(stderr, "Usage: %s [-n lines | -c bytes]\n", prog);
		exit(1);
	}

	n = strtol(argv[2], &ep, 10);    // did you enter a proper number?
	if (*ep || n <= 0) {
		fprintf(stderr, "Illegal count!\n");
		exit(2);
	}

	if (*argv[1] == '-') {    // print by lines or charactors.
		switch (*(argv[1]+1)) {
		case 'c':
			while (!feof(stdin) && i < n) {
				c[0] = fgetc(stdin);
				c[0] == EOF ? exit(3) : printf("%c", c[0]);
				i++;
			}
			break;
		case 'n':
			while (!feof(stdin) && i < n) {
				memset(c, '\n', sizeof(c));
				fgets(c, sizeof(c), stdin) == NULL ? exit(3) : printf("%s", c);
				i++;
			}
			break;
		default:
			fprintf(stderr, "Unknown options!\n");
			exit(4);
		}
	} else {
		fprintf(stderr, "Illegal options!\n");
		exit(5);
	}

	return 0;
}

