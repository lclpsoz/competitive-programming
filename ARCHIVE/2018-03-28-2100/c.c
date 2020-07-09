#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
	int conteudo;
	struct reg *prox;
} celula;

// Recebe um número nbytes que representa
// a quantidade de bytes a ser alocado.
// Caso tenha espaço suficiente na memória
// retorna ponteiro para espaço alocado,
// do contrário imprime aviso e para o
// processo
void *mallocc (size_t nbytes)
{
	void *ptr;
	ptr = malloc (nbytes);
	if (ptr == NULL) {
		printf ("Malloc devolveu NULL!\n");
		exit (EXIT_FAILURE);
	}
	return ptr;
}

// Retorna um ponteiro celula que é
// a cabeça de uma lista encadeada.
celula *cria_le (void)
{
	celula *le;
	le = (celula*) mallocc (sizeof (celula));
	le->prox = NULL;
	return le;
}

// Recebe um número x e um ponteiro
// celula p. Insere na lista encadeada
// (com cabeça) conteudo de x logo após
// a celula p.
void insere (int x, celula *p)
{
	celula *nova;
	nova = (celula*) mallocc (sizeof (celula));
	nova->conteudo = x;
	nova->prox = p->prox;
	p->prox = nova;
}

// Recebe uma lista encadeada com cabeça
// e imprime todos os seus elementos na
// ordem que estiverem.
void imprime (celula *le)
{
	celula *p;
	for (p = le->prox; p != NULL; p = p->prox)
		printf ("%d ", p->conteudo);
	printf ("\n");
}

// Recebe duas listas encadeadas de números
// inteiros sem repetição com cabeça (p1 e p2) e
// o número 0 (opcao). Retorna 1 caso tenham
// mesmo conteúdo e 0 do contrário. Algoritmo
// recursivo.
int compara (celula *p1, celula *p2, int opcao)
{
	int sao_iguais = 1;
	if (opcao == 0) {
		sao_iguais = compara (p1, p2, 1);
		p1 = p1->prox;
		p2 = p2->prox;
		if (sao_iguais)
			sao_iguais = compara (p1, p2, 2);
		return sao_iguais;
	}
	else if (opcao == 1) {
		p1 = p1->prox;
		p2 = p2->prox;
		if (p1 == NULL && p2 == NULL)
			return 1;
		else if (p1 == NULL || p2 == NULL)
			return 0;
		else
			sao_iguais = compara (p1, p2, 1);
	}
	else if (opcao == 2) {
		if (p1 == NULL && p2 == NULL)
			return 1;
		else if (p2 == NULL) {
			return 0;
		}
		else {
			compara (
		}
	}
}

int main (void)
{
	int i, n, valor;
	celula *le1;
	celula *le2;
	le1 = cria_le ();
	le2 = cria_le ();

	printf ("Entre com a quantidade de elementos da primeira lista encadeada: ");
	scanf ("%d", &n);
	printf ("Entre com os elementos da primeira lista encadeada: ");
	for (i = 0; i < n; i++) {
		scanf ("%d", &valor);
		insere (valor, le1);
	}
	printf ("Sua primeira lista encadeada eh:\n");
	imprime (le1);
	printf ("\n");

	printf ("Entre com a quantidade de elementos da segunda lista encadeada: ");
	scanf ("%d", &n);
	printf ("Entre com os elementos da segunda lista encadeada: ");
	for (i = 0; i < n; i++) {
		scanf ("%d", &valor);
		insere (valor, le2);
	}
	printf ("Sua segunda lista encadeada eh:\n");
	imprime (le2);
	printf ("\n");



	return 0;
}
