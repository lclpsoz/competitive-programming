#include <bits/stdc++.h>
using namespace std;

int i;
int qnt, def, val, maxi, aux;

int main (){

	while(scanf("%d", &qnt) != EOF){

		scanf("%d", &def);
		aux = maxi = 0;
		for (i = 0; i < qnt; i++){

			scanf("%d", &val);

			aux = max(aux + val - def, val - def);
			maxi = max(aux, maxi);

		}

		printf("%d\n", maxi);

	}

	return 0;
}
