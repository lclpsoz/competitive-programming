#include <stdio.h>

int i, j;
int test, qnt, id;
char mat[4][9] = {"Rolien", "Naej", "Elehcim", "Odranoel"};

int main (void){

	scanf("%d", &test);

	for (i = 0; i < test; i++){

		scanf("%d", &qnt);
		for (j = 0; j < qnt; j++){

			scanf("%d", &id);
			printf("%s\n", mat[id - 1]);

		}
	}

	return 0;
}
