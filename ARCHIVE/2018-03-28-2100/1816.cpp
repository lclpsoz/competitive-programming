#include <bits/stdc++.h>
using namespace std;

typedef struct reg {
	char letter;
	struct reg *next;
} cell;

int i, j;
int n, h, x;

void insert (char c, cell *le) {
	cell *new_cell = (cell*) malloc (sizeof (cell));;
	new_cell->letter = c;
	new_cell->next = le->next;
	le->next = new_cell;
}

int main ()
{
	cell *le = (cell*) malloc (sizeof (cell));
	cell *p, *q;
	le->letter = 'A';
	le->next = NULL;
	for (i = 'Z'; i >= 'B'; i--)
		insert (i, le);
	h = 1;

	while (scanf ("%d", &n), n) {
		printf("Instancia %d\n", h++);
		for (i = 0; i < n; i++) {
			scanf ("%d", &x);
			p = q = le;
			for (j = 1; j < x; j++) {
				if (j > 1)
					q = q->next;
				p = p->next;
			}
			printf ("%c", p->letter);
			if (x > 1) {
				q->next = p->next;
				p->next = le;
				le = p;
			}
		}
		printf ("\n\n");
		p = le;
		for (i = 'A'; i <= 'Z'; i++) {
			p->letter = i;
			p = p->next;
		}
	}
	return 0;
}
