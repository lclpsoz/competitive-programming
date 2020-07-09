#include <bits/stdc++.h>
using namespace std;

int n, m;
long long unsigned mat[30][30];

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		if (i)
			putchar ('\n');
		scanf ("%d", &m);
		for (int j = 0; j < m; j++)
			mat[0][j] = 0;

		for (int j = 1; j <= m; j++)
			for (int k = 0; k < m; k++) {
				scanf ("%llu", &mat[j][k]);
				mat[j][k] *= mat[j][k];
				if (mat[j][k] == 0)
					mat[0][k] = max (mat[0][k], (long long unsigned) 1);
				else
					mat[0][k] = max (mat[0][k], (long long unsigned)((int)log10 (mat[j][k])+1));
			}

		printf ("Quadrado da matriz #%d:\n", i+4);
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < m; k++) {
				printf ("%*llu", (int) mat[0][k], mat[j][k]);
				if (k < (m-1))
					putchar (' ');

			}
			putchar ('\n');
		}
	}

	return 0;
}
