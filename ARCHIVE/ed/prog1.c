#include <stdio.h>
#include <stdlib.h>

typedef struct reg noh;
struct reg {
	int conteudo;
	noh *esq;
	noh *dir;
};

typedef noh *arvore;

arvore cria_arvore (int c)
{
	arvore nova = (arvore) malloc (sizeof (noh));
	nova->conteudo = c;
	nova->dir = NULL;
	nova->esq = NULL;
	return nova;
}

void erd (arvore r)
{
	printf ("%d\n", r->conteudo);
	if (r != NULL) {
		erd (r->esq);
		printf ("%d\n", r->conteudo);
		erd (r->dir);
	}
}

void inverte_arv (arvore r)
{
	arvore aux;
	aux = r->esq;
	r->esq = r->dir;
	r->dir = r->esq;
	if (r->esq != NULL)
		inverte_arv (r->esq);
	else
		inverte_arv (r->dir);
}

void preenche_erd (arvore r, int c, int pos)
{
	if (pos == 0)
		r->conteudo = c;
	else if (pos == 1) {
		r->esq = cria_arvore (c);
	}
	else if (pos == 2) {
		r->dir = cria_arvore (c);
	}
	else {
		pos-=2;
		pos&1 ? preenche_erd (r->esq, c, pos) : preenche_erd (r->dir, c, pos);
	}
}

int main (void)
{
	int n, x;
	arvore arv = cria_arvore (0);
	scanf ("%d", &n);

	preenche_erd (arv, 123, 0);
	printf ("%d\n", arv->conteudo);
	/*for (int i = 0; i < n; i++) {
		scanf ("%d", &x);
		preenche_erd (arv, x, i);
	}
	putchar ('\n');
	printf ("%d\n", arv->conteudo);
	erd (arv);
	//inverte_arv (arv);
	printf ("=====\n");
	erd (arv);*/
	return 0;
}
