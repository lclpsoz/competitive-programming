#include <bits/stdc++.h>
using namespace std;

int aux;
int arr[3];
int qnt[10100];

int main ()
{
	aux = 0;
	for (int i = 0; i < 58; i++) {
		aux = 1;
		for (int j = i; j < 101 && j*j <= 1e4; j++) {
			aux = 1;
			for (int k = j; k <= 1e4 && aux <= 1e4; k++) {
				aux = ((i*(j+k))+(j*k));
				// printf ("%d %d %d: %d\n", i, j, k, aux);
				if (aux <= 1e4)
					qnt[aux]++;
			}
		}
	}

	int n;
	while (scanf ("%d", &n), n != -1)
		printf ("%d\n", qnt[n]);

	return 0;
}
