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
			while ((c[0] = fgetc(stdin)) != EOF && i < n) {
				printf("%c", c[0]);
				i++;
			}
			break;
		case 'n':
			memset(c, '\n', sizeof(c));    // `fgets` will not stop when it encouters a `NULL`.
			                               // and this kludge is stupid and ugly :)
			while (fgets(c, sizeof(c), stdin) != NULL && i < n) {
				printf("%s", c);
				memset(c, '\n', sizeof(c));
				i++;
			}
			break;
		default:
			fprintf(stderr, "Unknown options!\n");
			exit(3);
		}
	} else {
		fprintf(stderr, "Illegal options!\n");
		exit(4);
	}

	return 0;
}

