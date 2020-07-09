#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e6+10, MAXN = 2e6+100;

int i, j;
char str[MAXS];
int aux[MAXS], arr[MAXN], posi[MAXS], size, qnt;
bool test;

//aux: Armazena a sequencia atual em forma de 0 e 1
//arr: Armazena todas as sequencias separadas por 2
//posi: Armazena a posicao inicial de cada sequencia
//size: Tamanho da sequencia atual, inclui o 2
//qnt: Quantidade de sequencias diferentes

int main(){


	size = 0;//Posicao do ultimo 2, que finaliza uma sequencia
	while (scanf("%s", str) != EOF){

		for (i = 0; str[i] != '\0'; i++){

			if (str[i] == '(')
				aux[i] = 0;
			else if(str[i] == ')')
				aux[i] = 1;

		}
		aux[i] = 2;
		for (i = 0; i < 3; i++)
			printf("%d ", aux[i]);
		printf("\n");
		size = i+1;

		//Verify if it's a new sequence or not
		for (i = 0; i < qnt; i++){

			j = posi[i]-1;
			test = false;
			do{

				if (arr[++j] != aux[i])
					test = true;

			}while (arr[j] != 2);

		}
		if (test) printf("true\n");
		else printf("false\n");
		printf("posi: ");
		for (i = 0; i < qnt; i++)
			printf("%d ", posi[i]);
		printf("\n");
		//Save a new sequente to arr
		if (!qnt || test){

			qnt++;
			posi[qnt+1] = posi[qnt] + size;
			printf("size: %d\n", size);
			for (i = posi[qnt]; i < posi[qnt]+size; i++)
				arr[i] = aux[j++];

		}
	}

	for (i = 0; i < posi[qnt]; i++)
		printf("%d ", arr[i]);

	printf("\n");

	printf("%d\n", qnt);

	return 0;
}
