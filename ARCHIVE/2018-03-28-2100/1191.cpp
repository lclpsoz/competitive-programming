#include <bits/stdc++.h>
using namespace std;


typedef struct reg {
	char x;
	int c;
	struct reg *l;
	struct reg *r;
} noh;
typedef noh *arvore;

arvore cria (int c, char x)
{
	arvore arv = (arvore) malloc (sizeof (noh));
	arv->l = NULL;
	arv->r = NULL;
	arv->x = x;
	arv->c = c;

	return arv;
}

arvore insere (arvore arv, int c, char x)
{
	if (arv == NULL)
		return cria (c, x);

	if (c < arv->c)
		arv->l = insere (arv->l, c, x);
	else
		arv->r = insere (arv->r, c, x);

	return arv;
}

// edr
void pos (arvore arv)
{
	if (arv != NULL) {
		pos (arv->l);
		pos (arv->r);
		cout << arv->x;
	}
}

int main ()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n, x;
	int big[30], small[30];
	char str1[100], str2[100];
	while (scanf ("%s %s", str1, str2) != EOF) {
		arvore arv = NULL;

		for (int j = 0; str2[j] != '\0'; j++) {
			if (str2[j] >= 'a' && str2[j] <= 'z')
				small[str2[j]-'a'] = j;
			else
				big[str2[j]-'A'] = j;
		}

		int j = 0;
		while (str1[j] != '\0') {
			if (str1[j] >= 'a' && str1[j] <= 'z')
				arv = insere (arv, small[str1[j]-'a'], str1[j]);
			else
				arv = insere (arv, big[str1[j]-'A'], str1[j]);
			j++;
		}

		pos (arv);
		cout << '\n';
	}

	return 0;
}
