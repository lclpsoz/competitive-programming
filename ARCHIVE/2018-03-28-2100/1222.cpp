#include <bits/stdc++.h>
using namespace std;

int n, l, c;
char arr[100];
int aux, linhas;

int main ()
{
	while (scanf ("%d %d %d", &n, &l, &c) != EOF) {
		aux = 0;
		linhas = 0;
		for (int i = 0; i < n; i++) {
			scanf ("%s", arr);
			if (aux) aux++;
			aux += strlen (arr);
			if (aux > c) {
				linhas++;
				aux = strlen (arr);
			}
		}
		printf ("%d\n", (linhas/l)+1);
	}

	return 0;
}
