#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned int llu;
const int MAXN = 510;

int i, j;
llu val, aux, big;
llu bigs[MAXN];

int main (){

	for (i = 1; i < 501; i++){

		if (!bigs[i]){

			aux = i;
			big = 1;
			while (aux > 1){

				big = max(big, aux);
				while (aux % 2 == 0) aux /= 2;
				while (aux % 2 && aux > 1) aux = (3 * aux) + 1;

			}
			bigs[i] = big;
			//printf("%d: %llu\n", i, big);
			for (j = i*2; j < 501; j *= 2) bigs[j] = max((llu) j, big);

		}
		//printf("%d: %llu\n", i, bigs[i]);

	}
	scanf("%llu", &val);
	while (val){

		printf("%llu\n", bigs[val]);

		scanf("%llu", &val);
	}

	return 0;
}
