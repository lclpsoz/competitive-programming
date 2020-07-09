#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4+10, MAXM = 40;

int i, j;
int rows, col, total;
int mat[MAXN][MAXM];

int mdc (int a, int b){

	if (a == 0) return b;
	return mdc(b%a, a);

}

int main (){

	scanf("%d %d", &rows, &col);

	while (rows){

		total = 0;
		for (i = 0; i < rows; i++)
			for (j = 0; j < col; j++){

				scanf("%d", &mat[i][j]);
				if (j == col-1) total += mat[i][j];

			}

		for (i = 0, j = col-1; i < rows; i++)
			printf("%d / %d\n", mat[i][j]/mdc(mat[i][j], total), total/mdc(mat[i][j], total));

		scanf("%d %d", &rows, &col);
	}

	return 0;
}
