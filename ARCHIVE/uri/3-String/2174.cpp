#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+20;

int i, j;
int qnt, amnt;
char mat[MAXN][MAXN], aux[MAXN];

int main(){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++)
		scanf("%s", mat[i]);

	for (i = 0; i < qnt-1; i++)
		for (j = i+1; j < qnt; j++)
			if (strcmp(mat[i], mat[j]) > 0){

				strcpy(aux, mat[i]);
				strcpy(mat[i], mat[j]);
				strcpy(mat[j], aux);

			}

	amnt++;
	for (i = 1; i < qnt; i++)
		if (strcmp(mat[i], mat[i-1]) != 0)
			amnt++;

	printf("Falta(m) %d pomekon(s).\n", 151 - amnt);

	return 0;
}
