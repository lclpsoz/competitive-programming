#include <bits/stdc++.h>
using namespace std;

int i;
long long unsigned int numb, aux, rest;
char str[50];

int main (void){

	do{

		scanf("%llu", &numb);
		i = 0;
		aux = numb;
		do{

			rest = aux % 32;
			aux /= 32;
			if (rest > 9){

				rest -= 10;
				str[i++] = 'A' + rest;

			}
			else
				str[i++] = rest + '0';

		}while (aux);

		for (i--; i >= 0; i--)
			printf("%c", str[i]);
		printf("\n");

	}while (numb);

	return 0;
}
