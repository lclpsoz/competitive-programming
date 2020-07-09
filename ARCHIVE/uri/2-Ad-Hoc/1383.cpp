#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10;

int i, j, k, l;
int qnt;
int mat[MAXN][MAXN];
bool arr[MAXN], ans;

int main (){

	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		ans = true;
		for (j = 0; j < 9; j++){

			for (k = 0; k < 9; k++){

				scanf("%d", &mat[j][k]);

				//Test each line
				if (arr[mat[j][k]]) ans = false;
				else arr[mat[j][k]] = true;

			}
			if (ans) memset(arr, 0, sizeof(arr));

		}

		//Test each column
		for (j = 0; j < 9 && ans; j++){

			for (k = 0; k < 9 && ans; k++){

				if (arr[mat[k][j]]) ans = false;
				else arr[mat[k][j]] = true;

			}
			if (ans) memset(arr, 0, sizeof(arr));

		}

		//Test each 3x3
		for (j = 0; j < 7 && ans; j += 3){

			for (k = 0; k < 7 && ans; k += 3){

				for (l = 0; l < 9 && ans; l++)
					if (arr[mat[j + (l/3)][k + (l%3)]]) ans = false;
					else arr[mat[j + (l/3)][k + (l%3)]] = true;

				if (ans) memset(arr, 0, sizeof(arr));
			}
		}

		if (ans) printf("Instancia %d\nSIM\n\n", i+1);
		else printf("Instancia %d\nNAO\n\n", i+1);

		memset(arr, 0, sizeof(arr));

	}

	return 0;
}
