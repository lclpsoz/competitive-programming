//Programa para salvar em arquivo binario (e recuperar) array de structs alocados dinamicamente
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXS 101

typedef struct dados {

	int valor;
	char carac;
	char str[MAXS];

} Dados;

int main (void){

	int i;
	FILE *fp;		//Ponteiro onde arquivo sera utilizado
	Dados *arr[3];	//Array de ponteiros do struct dados (principal)
	Dados *sec[3];	//Array de ponteiros do struct dados (secundario)
	Dados aux[3];	//Array estatico auxiliar

	for (i = 0; i < 3; i++)
		arr[i] = (Dados*) malloc(sizeof(Dados));

	//Criar arquivo binario
	fp = fopen("bin", "wb");
	if (fp == NULL){

		printf("ERRO AO CRIAR O ARQUIVO!\n");
		return 1;

	}

	//Entrada de dados no array de struct principal
	for (i = 0; i < 3; i++){

		scanf("%d", &arr[i]->valor);
		scanf(" %c", &arr[i]->carac);
		scanf("%s", arr[i]->str);

	}

	printf("Dados originais:\n");
	for (i = 0; i < 3; i++){

		printf("%d\n", arr[i]->valor);
		printf("%c\n", arr[i]->carac);
		printf("%s\n", arr[i]->str);

	}
	printf("\n");

	/*Passando dados para array de structs auxiliar
	for (i = 0; i < 3; i++){

		aux[i].valor = arr[i]->valor;
		aux[i].carac = arr[i]->carac;
		strcpy(aux[i].str, arr[i]->str);

	}*/

	//Salvando array auxiliar em arquivo binario
	fwrite(arr, sizeof(Dados), 3, fp);

	//Liberando memoria do array principal
	//for (i = 0; i < 3; i++)
	//	free(arr[i]);

	//Fechando arquivo binario
	fclose(fp);

	/*Zerando struct auxiliar
	for (i = 0; i < 3; i++){

		aux[i].valor = 0;
		aux[i].carac = '\0';
		aux[i].str[0] = '\0';

	}*/

	//Alocando dinamicamente array de strucs secundaria
	for (i = 0; i < 3; i++)
		sec[i] = (Dados*) malloc(sizeof(Dados));

	//Abrindo arquivo em modo de leitura binaria
	fopen("bin", "rb");

	//Recuperando informações do arquivo binario para array sec
	fread(sec, sizeof(Dados), 3, fp);

	//Recuperando informações do arquivo binario para array aux
	//fread(aux, sizeof(Dados), 3, fp);

	//Fechando arquivo
	fclose(fp);

	//Passando dados para array de structs sec
	/*for (i = 0; i < 3; i++){

		sec[i]->valor = aux[i].valor;
		sec[i]->carac = aux[i].carac;
		strcpy(sec[i]->str, aux[i].str);

	}*/

	printf("Dados recuperados:\n");
	for (i = 0; i < 3; i++){

		printf("%d\n", sec[i]->valor);
		printf("%c\n", sec[i]->carac);
		printf("%s\n", sec[i]->str);

	}
	printf("\n");

	//Liberando memoria do array de structs secundario
	for (i = 0; i < 3; i++)
		free(sec[i]);

	return 0;
}
