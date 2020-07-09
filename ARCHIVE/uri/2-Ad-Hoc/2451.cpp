#include <bits/stdc++.h>
using namespace std;

int i, j;
int size, food, maxi;
char mat[110][110];

int main (){

	scanf("%d", &size);
	for (i = 0; i < size; i++)
		scanf(" %[^\n] ", mat[i]);


	maxi = food = 0;
	for (i = 0; i < size; i++){

		if (!(i % 2)){

			for (j = 0; j < size; j++){

				if (mat[i][j] == 'o')
					food++;
				else if (mat[i][j] == 'A')
					food = 0;

				maxi = max(maxi, food);

			}

		}
		else if (i % 2){

			for (j = size-1; j >= 0; j--){

				if (mat[i][j] == 'o')
					food++;
				else if (mat[i][j] == 'A')
					food = 0;

				maxi = max(maxi, food);

			}
		}

	}

	printf("%d\n", maxi);

	return 0;
}
