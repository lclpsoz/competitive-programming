#include <stdio.h>
#include <stdlib.h>

typedef struct _celula{

	int valor;
	struct _celula *prox;

} Celula;

//Insere elemento de valor inteiro valor
//ao final de lista encadeada onde seu inicio
//eh indicado pelo ponteiro le, lista encadeada
//headless. Retorna a indiceicao da primeira celula
//da lista encadeada.
Celula* inserir (Celula *le, int valor){

	Celula *nova;
	nova = (Celula*) malloc (sizeof(Celula));

	if (le == NULL){

		le = nova;
		le->valor = valor;
		le->prox = NULL;

	}
	else{

		Celula *aux = le;
		while (aux->prox != NULL)
			aux = aux->prox;

		aux->prox = nova;
		aux = aux->prox;

		aux->valor = valor;
		aux->prox = NULL;

	}

	return le;

}

//Recece le como ponteiro pra primeira Celula da
//lista encadeada e indice (como inteiro indice)
//de qual elemento deve ser removido da lista.
//Retorna a primeira celula da lista encadeada apos
//a remocao
Celula* remover_indice (Celula *le, int indice){

	if (indice == 0)
		return le->prox;
	else{

		int i = 1;
		Celula *atual, *anterior;
		anterior = le;
		atual = le->prox;

		while (atual != NULL && i < indice){

			anterior = atual;
			atual = anterior->prox;
			i++;

		}

		if (i == indice){

			anterior->prox = atual->prox;

		}

	}
}

//Recebe le como ponteiro pra primeira Celula e
//o indice (0..n-1) do elemento da lista encadeada
//referindicea que o valor deve ser retornado,
//como o inteiro indice
int consultar_valor (Celula *le, int indice){

	int i;
	Celula *aux;
	aux = le;
	for (i = 0; i < indice; i++)
		aux = aux->prox;

	return aux->valor;

}

//Recebe le como ponteiro pra primeira
//Celula da lista indexada e o valor
//da celula que o indice (0..n-1)
//deve ser retornada. Caso o valor
//nao seja encontrado, retorna -1.
int consultar_indice (Celula *le, int valor){

	int i = 0;
	if (le->valor == valor)
		return i;
	else{

		while (le->prox != NULL && le->valor != valor){

			le = le->prox;
			i++;

		}

		if (le->valor == valor)
			return i;
		else
			return -1;

	}
}

int main (){

	int i;
	int n, valor;
	Celula *le = NULL;

	printf("Insira a quantindade elementos para a lista encadeada:\n");
	scanf("%d", &n);

	printf("Insira os valores das celulas:\n");
	for (i = 0; i < n; i++){

		scanf("%d", &valor);
		le = inserir (le, valor);

	}

	printf("\nOs elementos da lista são:\n");
	for (i = 0; i < n; i++){

		printf("%d\n", consultar_valor (le, i));

	}

	int x, indice;
	printf("\nDigite o valor que deseja saber a posicao:\n");
	scanf("%d", &x);
	indice = consultar_indice (le, x);
	if (indice == -1)
		printf("Este valor nao esta presente nesta lista encadeada\n");
	else
		printf("O valor %d esta na %dº posicao\n", x, indice+1);


	return 0;
}
