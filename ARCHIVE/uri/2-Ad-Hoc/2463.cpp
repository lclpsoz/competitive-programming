#include <bits/stdc++.h>
using namespace std;

int i;
int qnt, val, aux, maxi;

int main (){

	scanf("%d", &qnt);
	maxi = -10;
	for (i = 0; i < qnt; i++){

		scanf("%d", &val);
		aux += val;
		aux = max(val, aux);
		maxi = max(maxi, aux);

	}

	printf("%d\n", maxi);

	return 0;
}
