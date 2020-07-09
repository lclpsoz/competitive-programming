#include <bits/stdc++.h>
using namespace std;

typedef struct reg {
	struct reg *bef;
	char dir;
	struct reg *aft;

} cell;

void insert (char dir, cell *le) {
	cell *p = le;
	while (p->aft != le)
		p = p->aft;

	cell *new_cell;
	new_cell = (cell*) malloc(sizeof(cell));
	new_cell->dir = dir;
	new_cell->bef = p;
	new_cell->aft = p->aft;
	p->aft = new_cell;
	le->bef = new_cell;

}

int i;
int n;
char c;

int main ()
{
	cell *le, *p;
	le = (cell*) malloc (sizeof(cell));
	le->dir = 'N';
	le->aft = le;
	le->bef = le;
	insert ('L', le);
	insert ('S', le);
	insert ('O', le);

	while (scanf(" %d ", &n), n) {
		p = le;
		for (int i = 0; i < n; i++) {
			c = getchar();
			if (c == 'D')
				p = p->aft;
			else
				p = p->bef;
		}
		printf ("%c\n", p->dir);
	}

	return 0;
}
