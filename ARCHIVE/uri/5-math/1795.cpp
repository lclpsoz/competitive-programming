#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

const int MAXN = 60;

int i, j;
int x;
llu mat[MAXN][MAXN];

int main (){

	mat[0][24] = 1;
	mat[0][0] = 1;
	for (i = 1; i < 21; i++)
		for (j = 24-i; j <= 24+i; j++){

			mat[i][j] = mat[i-1][j-1] + mat[i-1][j] + mat[i-1][j+1];
			mat[i][0] += mat[i][j];	//Sum of all numbers in the row

		}

	/*for (i = 0; i < 21; i++){

		for (j = 1; j < 59; j++)
			printf("%llu", mat[i][j]);
		printf("\n");

	}*/

	while (scanf("%d", &x) != EOF)
			printf("%llu\n", mat[x][0]);

	return 0;
}
