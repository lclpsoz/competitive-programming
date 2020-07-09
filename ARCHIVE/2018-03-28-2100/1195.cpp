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

// red
void pre (arvore arv)
{
	if (arv != NULL) {
		cout << ' ' << arv->x;
		pre (arv->l);
		pre (arv->r);
	}
}

// erd
void in (arvore arv)
{
	if (arv != NULL) {
		in (arv->l);
		cout << ' ' << arv->x;
		in (arv->r);
	}
}

// edr
void pos (arvore arv)
{
	if (arv != NULL) {
		pos (arv->l);
		pos (arv->r);
		cout << ' ' << arv->x;
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, x;
	cin >> t;
	int i = 1;
	while (i <= t) {
		arvore arv = NULL;
		cin >> n;
		while (n--) {
			cin >> x;
			arv = insere (arv, x);
		}

		cout << "Case " << i << ":\n";
		cout << "Pre.:";
		pre (arv);
		cout << '\n';

		cout << "In..:";
		in (arv);
		cout << '\n';

		cout << "Post:";
		pos (arv);
		cout << '\n';

		cout << '\n';
		i++;
	}

	return 0;
}
