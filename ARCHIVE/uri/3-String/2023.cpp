#include <bits/stdc++.h>
using namespace std;

const int MAXS = 100, MAXN = 1010;

int i, j;
int pos[MAXN], maxi, aux;
char mat[MAXN][MAXS], mat_low[MAXN][MAXS], str_aux[MAXS];

int main(){

	while (scanf(" %[^\n]", mat[i]) != EOF){

		pos[i] = i;

		j = 0;
		while (mat[i][j] != '\0'){

			if (mat[i][j] >= 'A' && mat[i][j] <= 'Z')
				mat_low[i][j] = mat[i][j++] - 'A' + 'a';
			else
				mat_low[i][j] = mat[i][j++];

		}
		maxi = ++i;
	}

	for (i = 0; i < maxi-1; i++)
		for (j = i+1; j < maxi; j++)
			if (strcmp(mat_low[j], mat_low[i]) > 0){

				strcpy(str_aux, mat_low[j]);
				strcpy(mat_low[j], mat_low[i]);
				strcpy(mat_low[i], str_aux);
				aux = pos[j];
				pos[j] = pos[i];
				pos[i] = aux;

			}

	printf("%s\n", mat[pos[0]]);

	return 0;
}
