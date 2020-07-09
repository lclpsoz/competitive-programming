#include <stdio.h>
#include <stdlib.h>
typedef struct reg {
   int         chave;
   int         conteudo;
   struct reg *esq, *dir;
} noh;

void imprime ( noh *r){
	if (r!= NULL) {
		imprime (r->esq);
		printf("%d\n", r->chave);
		imprime (r->dir);
	}
}

noh *insere (noh *r, noh *novo){
	if (r == NULL) return novo;
	if(r->chave > novo->chave)
		r->esq = insere(r->esq,novo);
	else
		r->dir = insere (r->dir, novo);

}
noh *cria_noh(int n){
	noh *novo = (noh*) malloc (sizeof(noh));
	novo->chave = n;
	novo->esq = novo->dir = NULL;
	return novo;
}

int main ()
{
	noh *raiz = (noh*) malloc (sizeof (noh));
	raiz->chave = 10;
	raiz->esq = raiz->esq = NULL;

	int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
	int i = 0;
	for (i = 0; i < 9; i++){
		noh*novo = cria_noh(a[i]);
		insere(raiz, novo);
	}
	imprime(raiz);
	return 0;
}
