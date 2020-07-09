#include <bits/stdc++.h>
using namespace std;

int n, a, b, cont;
char str[2][100];

int main ()
{
	cont = 0;
	while (scanf ("%d", &n), n) {
		printf ("Teste %d\n", ++cont);
		scanf ("%s %s", str[0], str[1]);
		for (int i = 0; i < n; i++) {
			scanf ("%d %d", &a, &b);
			a += b;
			if (a & 1)
				printf ("%s\n", str[1]);
			else
				printf ("%s\n", str[0]);
		}
		printf ("\n");
	}
	return 0;
}
