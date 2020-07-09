#include <stdio.h>
#include <string.h>

int i, j;
int qnt, test;
char mat[20][4][100], name[100], gift[100];

int main (void){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++)
		for (j = 0; j < 4; j++)
			scanf("%s", mat[i][j]);

	while (scanf("%s %s", name, gift) != EOF){

		for (i = 0; i < qnt && strcmp(name, mat[i][0]); i++);

		test = 0;
		for (j = 1; j < 4; j++)
			if (!strcmp(gift, mat[i][j]))
				test = 1;

		if (test)
			printf("Uhul! Seu amigo secreto vai adorar o/\n");
		else
			printf("Tente Novamente!\n");

	}

	return 0;
}

