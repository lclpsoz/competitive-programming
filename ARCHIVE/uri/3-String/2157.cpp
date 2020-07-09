#include <bits/stdc++.h>
using namespace std;

const int MAXS = 1e6+10;

int i, j, k, l;
int qnt;
int mini, maxi, aux, size, amnt;
char str[MAXS];

int main(){

	scanf("%d", &qnt);
	for (l = 0; l < qnt; l++){

		k = 0;

		scanf("%d %d", &mini, &maxi);
		for (j = mini; j <= maxi; j++){

			aux = j;
			size = floor(log10(aux)) + 1;
			k += size-1;
			while (aux){

				//printf("%d\n", aux);
				//printf("k: %d   %d\n", k,size);
				str[k--] = aux - (floor(aux/10)*10) + '0';
				aux /= 10;
				//printf("%d\n", aux);

			}
			k += size+1;
			//printf("k: %d %d\n", k, size);
			//printf("\t%s\n", str);


		}
		for (i = k-1, j = k; i >= 0; i--, j++)
			str[j] = str[i];

		printf("%s\n", str);
		for (i = 0; i < k*2; i++)
			str[i] = 0;

	}

	return 0;
}
