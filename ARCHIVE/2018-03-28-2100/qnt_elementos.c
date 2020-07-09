#include <stdio.h>
#include <stdlib.h>

typedef struct reg{

	int conteudo;
	struct reg *prox;

} celula;

//Funcao recebe como parametro uma lista encadeada
//de inteiros le e valor, um inteiro, aloca
//dinamicamente uma nova celula que sera inserida
//logo apos a celula le e retorna ponteiro celula
//da celula alterada
celula *inserir (celula *le, int valor){

	celula *nova;
	nova = (celula*) malloc (1 * sizeof(celula));

	nova->conteudo = valor;
	nova->prox = le->prox;
	le->prox = nova;
	return le;

}

//Funcao recebe como parametro uma lista encadeada
//de inteiros le e imprime, de forma iterativa, o
//conteudo de todos os seus elementos
void imprime (celula *le){

	celula *p;
	for (p = le->prox; p != NULL; p = p->prox)
		printf("%d ", p->conteudo);
	printf("\n");

}

//Funcao recebe como parametro uma lista encadeada
//de inteiros le, calcula de forma iterativa a
//quantidade de elementos presentes na lista
//encadeada com cabecalho iniciada por le e
//retorna esse valor como inteiro
int quantidade_elementos_iterativa (celula *le) {

	int quantidade = 0;
	celula *p;
	for (p = le->prox; p != NULL; p = p->prox)
		quantidade++;

	return quantidade;

}

//Funcao recebe como parametro le, um struct
//celula, calcula de forma recursiva a
//quantidade de elementos presentes na lista
//encadeada com cabecalho iniciada por le e
//retorna esse valor como inteiro
int quantidade_elementos_recursiva (celula *le) {

	if (le->prox == NULL)
		return 0;
	else
		return 1 + quantidade_elementos_recursiva (le->prox);

}

int main (void) {

	int i;
	int qnt_elementos, valor;
	celula *le;
	le = (celula*) malloc(1 * sizeof(celula));
	le->prox = NULL;

	printf("Entre com a quantidade de elementos de sua lista encadeada: ");
	scanf("%d", &qnt_elementos);

	printf("Entre com os %d elementos da lista encadeada:\n", qnt_elementos);
	for (i = 0; i < qnt_elementos; i++){

		scanf("%d", &valor);
		inserir (le, valor);

	}

	printf("Sua lista encadeada eh:\n");
	imprime (le);

	printf("Calculando de forma iterativa, sua lista encadeada tem %d elementos.\n", quantidade_elementos_iterativa(le));
	printf("Calculando de forma recursiva, sua lista encadeada tem %d elementos.\n", quantidade_elementos_recursiva(le));

	return 0;
}
