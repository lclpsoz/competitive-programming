#include <bits/stdc++.h>
using namespace std;

const int MAXN = 150, MAXM = 150;

int i, j, l;
int rows, col, k;
int zeros, zeros_now, zeros_final, scr, scr_larger, scr_final;
int mat[MAXN][MAXM];

int main (){

	scanf("%d %d %d", &rows, &col, &k);
	for (i = 0; i < rows; i++)
		for (j = 0; j < col; j++)
			scanf("%d", &mat[i][j]);

	for (j = 0; j < col; j++){

		zeros = zeros_now = scr = scr_larger = 0;
		for (i = 0; i < rows; i++){

			if (mat[i][j]){

				//printf("i(%d)\n", i);
				for (l = i; l < min(i+k, rows); l++)
					if (mat[l][j]) scr++;

				if (scr > scr_larger){

					zeros = zeros_now;
					scr_larger = scr;


				}

				scr = 0;
				zeros_now++;

			}
		}
		//printf("%d: %d\n", j, scr_larger);

		zeros_final += zeros;
		scr_final += scr_larger;

	}

	printf("%d %d\n", scr_final, zeros_final);

	return 0;
}
