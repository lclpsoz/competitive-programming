#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100, MAXL = 25;

int i, j;
int qnt, good, bad;
char type, mat_str[MAXN][MAXL], aux[MAXL];

int main (){

	scanf("%d", &qnt);

	for (i = 0; i < qnt; i++){

		scanf(" %c %s", &type, mat_str[i]);
		type == '+' ? good++: bad++;

	}

	for (i = 0; i < qnt; i++)
		for (j = i+1; j < qnt; j++)
			if (strcmp(mat_str[i], mat_str[j]) > 0){

				strcpy(aux, mat_str[i]);
				strcpy(mat_str[i], mat_str[j]);
				strcpy(mat_str[j], aux);

			}

	for (i = 0; i < qnt; i++)
		printf("%s\n", mat_str[i]);

	printf("Se comportaram: %d | Nao se comportaram: %d\n", good, bad);

	return 0;
}
