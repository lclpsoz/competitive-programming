#include <cstdio>
#include <cstdlib>

int i, j;
int n, x;
long long ans;

typedef struct reg cell;
struct reg {
	int val;
	cell*prox;
};

int main ()
{
	cell *le = (cell*) malloc (sizeof (cell)), *p;
	p = le;
	le->val = 1;
	for (i = 1; i <= 7; i++) {
		p->prox = (cell*) malloc (sizeof (cell));
		p = p->prox;
		p->val = 0;
	}
	p->prox = le;
	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		scanf ("%d", &x);
		x %= 8;
		for (j = 0; j < x; j++) {
			le = le->prox;
		}
		ans += le->val;
		le->val++;
	}
	printf ("%lld\n", ans);
}
