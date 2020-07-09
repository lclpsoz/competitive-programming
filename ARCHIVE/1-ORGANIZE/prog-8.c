//Alocacao dinamica de structs em array (um a um), utilizando o mesmo array para salvar e recuperar em modo binario
//Solucao usando apenas 1 array!!
//Linux: Funciona perfeitamente
//Windows: Programa trava
#include <stdio.h>
#include <stdlib.h>

//Faça um programa principal em C para criar um vetor de ponteiros para uma  struct chamada brasileirão, que deve conter os campos nome da equipe (vetor de char), posição no campeonato (char), estado brasileiro (vetor de char) e número de pontos ganhos (inteiro). Aloque dinamicamente cada estrutura, e leia os valores de nome da equipe, posição, estado e pontos de cada equipe. Salve os dados do vetor de struct em um arquivo chamado de serieA. Finalmente, recupere os dados a partir do arquivo salvo.
//OBS: O vetor de ponteiros deverá conter 5 posições para conter todas as equipes que estão no G5 do Brasileirão série A 2017

typedef struct brasileirao{

	char equipe[100];
	char posi;
	char estado[100];
	int pontos;

} Brasileirao;

int main (void){

	int i;
	FILE *fp;
	Brasileirao *arr[5];

	for (i = 0; i < 5; i++)
		arr[i] = (Brasileirao*) malloc(sizeof(Brasileirao));

	for (i = 0; i < 5; i++){

		scanf(" %[^\n]\n", arr[i]->equipe);
		scanf("%c", &arr[i]->posi);
		scanf(" %[^\n]\n", arr[i]->estado);
		scanf("%d", &arr[i]->pontos);

	}
	printf("1\n");

	fp = fopen("serieA", "wb");
	fwrite(arr, sizeof(Brasileirao), 5, fp);
	fclose(fp);
	printf("2\n");

	fp = fopen("serieA", "rb");
	fread(arr, sizeof(Brasileirao), 5, fp);
	fclose(fp);
	printf("3\n");

	for (i = 0; i < 5; i++){

		printf("%s\n", arr[i]->equipe);
		printf("%c\n", arr[i]->posi);
		printf("%s\n", arr[i]->estado);
		printf("%d\n", arr[i]->pontos);

	}

	for (i = 0; i < 5; i++)
		free(arr[i]);

	return 0;
}
