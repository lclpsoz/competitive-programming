#include <bits/stdc++.h>
using namespace std;


typedef struct reg {
	int x;
	struct reg *l;
	struct reg *r;
} noh;
typedef noh *arvore;

arvore cria (int x)
{
	arvore arv = (arvore) malloc (sizeof (noh));
	arv->l = NULL;
	arv->r = NULL;
	arv->x = x;

	return arv;
}

arvore insere (arvore arv, int x)
{
	if (arv == NULL)
		return cria (x);
	if (x < arv->x)
		arv->l = insere (arv->l, x);
	else
		arv->r = insere (arv->r, x);

	return arv;
}

queue<arvore> q;

int main ()
{
	int t, n, x;
	scanf ("%d", &t);
	int i = 1;
	while (i <= t) {
		arvore arv = NULL;
		scanf ("%d", &n);
		while (n--) {
			scanf ("%d", &x);
			arv = insere (arv, x);
		}

		printf ("Case %d:\n", i);
		q.push (arv);
		while (!q.empty ()) {
			arvore aux = q.front ();
			q.pop ();
			if (aux != arv)
				putchar (' ');
			printf ("%d", aux->x);
			if (aux->l != NULL)
				q.push(aux->l);
			if (aux->r != NULL)
				q.push(aux->r);
		}
		putchar ('\n');
		if (i <= t)
			putchar ('\n');
		i++;
	}

	return 0;
}
