#include <bits/stdc++.h>
using namespace std;

typedef struct reg {
	struct reg *esq;
	struct reg *dir;
	char val;
} noh;

typedef noh *arvore;

arvore cria_arv (char val)
{
	arvore arv = (arvore) malloc (sizeof (noh));
	arv->esq = arv->dir = NULL;
	arv->val = val;
}



int main ()
{

	return 0;
}
