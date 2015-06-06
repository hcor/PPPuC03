#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct charinfo {
	char c;
	int count;
	struct charinfo *next;
};

int main()
{
	int n;
	struct charinfo *head = NULL, *current, *prev;

LOOP:
	if ((n = getchar()) == EOF) goto BREAK;

	if (isalpha(n)) {
		n = tolower(n);

		if (head == NULL) {
			head = malloc(sizeof(struct charinfo));
			current = head; prev = current;
			current->c = n;
			current->count = 1;
			current->next = NULL;
			goto LOOP;
		}

		if (n < head->c) {
			current = malloc(sizeof(struct charinfo));
			current->c = n;
			current->count = 1;
			current->next = head;
			head = current; prev = current;
			goto LOOP;
		}

		if (n < current->c) {
			current = head; prev = current;
		}
		while (1) {
			if (n > current->c && current->next != NULL) {
				prev = current;
				current = current->next;
			} else if (n == current->c) {
				current->count++;
				break;
			} else if (n < current->c) {
				prev->next = malloc(sizeof(struct charinfo));
				prev->next->next = current; current = prev->next;
				current->c = n;
				current->count = 1;
				break;
			} else if (current->next == NULL) {
				current->next = malloc(sizeof(struct charinfo));
				prev = current; current = current->next;
				current->c = n;
				current->count = 1;
				current->next = NULL;
				break;
			}
		}
	}

	goto LOOP;

BREAK:
	/* reverse the list. */
	current = head; prev = current;
	head = head->next; current->next = NULL;
	while (head != NULL) {
		prev = head; head = head->next;
		prev->next = current;
		current = prev;
	}
	head = current;

	current = head; /*prev = current;*/
	while (current != NULL) {
		printf("%c  %d\n", current->c, current->count);
		prev = current; current = current->next;
		//printf("%c freed!\n", prev->c);
		free(prev);
	}

	return 0;
}

