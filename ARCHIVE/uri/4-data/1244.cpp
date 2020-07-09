//Implementation using each line in a matriz 'mat' as the size of the string in it.
#include <bits/stdc++.h>
using namespace std;

const int MAXS = 100;

int qnt, max_len, min_len, size, pos[100];
char mat[MAXS][MAXS][MAXS];
char c, str[MAXS];

int main (){

	int i, j, k;

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		min_len = 99999;
		scanf("%s%c", str, &c);
		size = strlen(str);
		strcpy(mat[size][pos[size]], str);
		pos[size]++;
		min_len = min(min_len, size);
		while (c != '\n'){

			scanf("%s%c", str, &c);
			size = strlen(str);
			strcpy(mat[size][pos[size]], str);
			pos[size]++;
			min_len = min(min_len, size);

		}

		for (j = 55; j >= min_len; j--){

			for (k = 0; k < pos[j]; k++){

				printf("%s", mat[j][k]);
				if (j != min_len || k != pos[j]-1) printf(" ");

			}
			pos[j] = 0;

		}
		printf("\n");

	}

	return 0;
}
