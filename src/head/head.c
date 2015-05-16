/*
 * based on ZHU Tianyao's code.
 * */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX    1024

int main(int argc, char **argv)
{
	int i = 0, n = -1;
	char c[MAX];
	char* ep;
	char* prog = argv[0];

	// check the argument count.
	if (argc != 3) {
		fprintf(stderr, "Usage: %s [-n lines | -c bytes]\n", prog);
		exit(1);
	}

	// did you enter a proper count?
	n = strtol(argv[2], &ep, 10);
	if (*ep || n <= 0) {
		//fprintf(stderr, "%s: illegal number %s!\n", argv[0], argv[2]);
		fprintf(stderr, "Usage: %s [-n lines | -c bytes]\n", prog);
		exit(2);
	}

	// print lines or charactors.
	if (argv[1][0] == '-') {
		switch (argv[1][1]) {
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
			//fprintf(stderr, "%s: illegal option %c!\n", argv[0], argv[1][1]);
			fprintf(stderr, "Usage: %s [-n lines | -c bytes]\n", prog);
			exit(4);
		}
	} else {
		//fprintf(stderr, "%s: illegal option %s!\n", argv[0], argv[1]);
		fprintf(stderr, "Usage: %s [-n lines | -c bytes]\n", prog);
		exit(5);
	}

	return 0;
}

