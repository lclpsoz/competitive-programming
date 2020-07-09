#include <bits/stdc++.h>
using namespace std;

const int MAXR = 1e5+10, MAXC = 60, MODL = 1e9+7;

int i, j;
long long unsigned int times, mini, maxi;
//Will keep the first and last row with zeros, that way the code will work for all rows equally
long long unsigned int mat[MAXR][MAXC], sum;

int main(){

	scanf("%llu %llu %llu", &times, &mini, &maxi);

	for (i = mini; i <= maxi; i++)
		mat[i][0] = 1;

	for (i = 1; i < times; i++)
		for (j = mini; j <= maxi; j++){

			mat[j][i] = (mat[j-1][i-1] + mat[j+1][i-1]) % MODL;


			if (i == times-1){

				sum += mat[j][i];
				sum %= MODL;

			}
		}

	/*printf("\n");
	for (i = mini; i <= maxi;i++){

		for (j = 0; j < times; j++)
			printf("%llu ", mat[i][j]);
		printf("\n");

	}
	printf("\n");*/

	if (times == 1)
		sum = maxi - mini + 1;

	printf("%llu\n", sum % MODL);

	return 0;
}
