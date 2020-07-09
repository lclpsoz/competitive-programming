#include <stdio.h>
#include <string.h>

int i, j;
int meat_qnt, meat_exp;
char meat[51][21], aux[21];

int main (void){

	while (scanf("%d", &meat_qnt) != EOF){

		for (i = 0; i < meat_qnt; i++){

			scanf("%s %d", aux, &meat_exp);

			strcpy(meat[meat_exp], aux);

		}

		for (i = 0, j = 1; i < 51; i++){

			if (meat[i][0] != '\0'){

				printf("%s", meat[i]);
				if (j++ < meat_qnt)
					printf(" ");

			}

			meat[i][0] = '\0';

		}
		printf("\n");

	}

	return 0;
}
