#include <bits/stdc++.h>
using namespace std;

int i;
int qnt, s, d, prev, aux;

int main (){

	prev = 0;
	scanf("%d", &qnt);
	for (i = 0; i < qnt; i++){

		scanf("%d %d", &s, &d);

		aux = s;
		while (aux <= prev)
			aux += d;

		prev = aux;

	}

	printf("%d\n", prev);

	return 0;
}
