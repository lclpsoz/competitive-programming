#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Recebe ponteiro para dois inteiros
//a e b, torna o valor de a = b e o
//valor b igual ao original de a
void trocar (int* a, int* b)
{

	int t = *a;
	*a = *b;
	*b = t;

}

//Recebe vetor(esq..dir), inteiro esq e
//inteiro dir, faz processo de separacao
//do quicksort, retornando a posicao do pivo
int separar (int* vetor, int esq, int dir)
{

	int x = vetor[esq];
	int i = esq-1;
	int j = dir+1;

	while (1) {

		do
			j--;
		while (vetor[j] > x);

		do
			i++;
		while (vetor[i] < x);

		if (i < j)
			trocar(&vetor[i], &vetor[j]);
		else
			return j;


	}

}

//Recebe vetor(esq..dir), inteiro esq e
//inteiro dir, e ordena o vetor no intervalo
//[esq, dir]
void quicksort (int* vetor, int esq, int dir)
{

	if (esq < dir) {

		int pivo = separar (vetor, esq, dir);

		quicksort (vetor, esq, pivo);
		quicksort (vetor, pivo+1, dir);

	}

}

int main (void){

	int i, size = 500;
	int vetor[size+1];

	//Generate an vetor of size 'size' of pseudo-unsecure random numbers from 0 to 1000
	srand(time(NULL));
	for (i = 0; i < size; i++)
		vetor[i] = rand() % 1000;

	//for (i = 0; i < size; i++)
	//	vetor[i] = size-i;

	for (i = 0; i < size; i++){

		if (i % 10 == 0)
			printf("\n");
		printf("%d\t", vetor[i]);

	}
	printf("\n\n");

	quicksort(vetor, 0, size - 1);

	for (i = 0; i < size; i++){

		if (i % 10 == 0)
			printf("\n");
		printf("%d\t", vetor[i]);

	}
	printf("\n");

	return 0;
}
