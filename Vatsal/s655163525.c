#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VALUES_PER_UNIT	0xFF
#define VOID_VAL	(-1)


typedef struct unit {
	struct unit *before, *after;
	int values[VALUES_PER_UNIT];
} unit;

int main(void) {
	char s[20];
	int index = 0, i, j, n, val;
	unit *funit, *lunit, *u;
	funit = malloc(sizeof(unit));
	funit->before = funit->after = NULL;
	lunit = funit;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		//if (i % 10000 == 0 || i >= 2000000) fprintf(stderr, "%d\n", i);
		scanf("%s", s);
		if (strcmp(s, "insert") == 0) {
			scanf("%d", &val);
			lunit->values[index++] = val;
			if (index >= VALUES_PER_UNIT) {
				u = malloc(sizeof(unit));
				u->before = lunit;
				lunit = u;
				index = 0;
			}
		} else if (strcmp(s, "delete") == 0) {
			scanf("%d", &val);
			j = index;
			u = lunit;
			while (u != NULL) {
				while (--j >= 0) {
					if (u->values[j] == val) {
						u->values[j] = VOID_VAL;
						break;
					}
				}
				if (j >= 0) break;
				u = u->before;
				j = VALUES_PER_UNIT;
			}
		} else if(strcmp(s, "deleteFirst") == 0) {
			do {
				index--;
				if (index < 0) {
					if (lunit->before == NULL) break;
					u = lunit;
					lunit = lunit->before;
					free(u);
					index = VALUES_PER_UNIT - 1;
				}
			} while (lunit->values[index] == VOID_VAL);
		} else if(strcmp(s, "deleteLast") == 0) {
			u = funit;
			j = 0;
			while (u->values[j] == VOID_VAL) {
				if (++j >= VALUES_PER_UNIT) {
					if (u->after == NULL) break;
					u = u->after;
					j = 0;
				}
			}
			if (j < VALUES_PER_UNIT) {
				u->values[j] = VOID_VAL;
			}
		} else printf("invalid operation: %s\n", s);
	}
	i = 0;
	for (u = lunit; u != NULL; u = u->before) {
		while (--index >= 0) {
			if (!i) {
				printf(" ");
				i++;
			}
			if (u->values[index] != VOID_VAL) printf("%d", u->values[index]);
		}
		index = VALUES_PER_UNIT - 1;
	}
	printf("\n");
}