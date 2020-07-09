#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int i, j, k, l;
int qnt, n, m, p, x, y, troops;
int mat[MAXN][MAXN];
char c;

int main ()
{
	scanf ("%d", &qnt);
	for (i = 0; i < qnt; i++) {
		scanf ("%d %d %d", &n, &m, &p);
		//Start at (1, 1) and ENDs at (n, m), for generalization
		for (j = 1; j <= n; j++)
			for (k = 1; k <= m; k++) {
				scanf (" %c", &c);
				if (c == 'T')
					mat[j][k] = 1;
				else
					mat[j][k] = 0;
			}
		//Clean the next column and the next line
		for (j = n+1
		for (j = 0; j < p; j++) {
			scanf ("%d %d", &x, &y);
			troops = 0;
			for (k = x-1; k <= x+1; k++)
				for (l = y-1; l <= y+1; l++)
					if ((k != x || l != y) && mat[k][l])
						troops++;
			if (troops > 4)
				printf ("GRRR\n");
			else
				printf ("GG IZI\n");
		}
	}

	return 0;
}
