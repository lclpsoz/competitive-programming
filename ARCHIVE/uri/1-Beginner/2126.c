#include <stdio.h>
#include <string.h>

int i, j;
int n1_size, count, pos, qnt;
char n1[10], n2[32];

int main (void){

	while (scanf("%s %s", n1, n2) != EOF){

		count++;

		for (i = 0; i < 10; i++)
			if (n1[i] != '\0')
				n1_size++;

		for (i = 0, j = 0; j < 32; j++){

			if (n1[i] == n2[j])
				i++;
			else if (n1[0] == n2[j])
				i = 1;
			else
				i = 0;

			if (i == n1_size){

				i = 0;
				pos = j - n1_size + 2;
				qnt++;

			}
		}

		printf("Caso #%d:\n", count);
		if (qnt == 0)
			printf("Nao existe subsequencia\n\n");
		else{

			printf("Qtd.Subsequencias: %d\n", qnt);
			printf("Pos: %d\n\n", pos);

		}

		pos = 0;
		qnt = 0;
		n1_size = 0;
		memset(n1, '\0', 10);
		memset(n2, '\0', 32);

	}

	return 0;
}
