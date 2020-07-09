//Teorema de Euler, V + F = A + 2
#include <bits/stdc++.h>
using namespace std;

typedef long long unsigned llu;

llu i, fp, fh, v, f, a;

int main (){

	i = 1;
	while (scanf("%llu %llu", &fp, &fh) != EOF){


		f = fp + fh;
		a = (5*fp + 6*fh)/2;
		v = a - f + 2;

		printf("Molecula #%llu.:.\n", i++);
		printf("Possui %llu atomos e %llu ligacoes\n\n", v, a);

	}

	return 0;
}
