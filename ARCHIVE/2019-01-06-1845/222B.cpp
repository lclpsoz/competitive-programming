#include "stdio.h"
#include "algorithm"

int n, m, k;
char opt;
int x, y, ax;
int mat[1001][1001];
int col[1001], row[1001];

int main () {
	for (int i = 1; i <= 1000; i++)
		col[i] = row[i] = i;
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf ("%d", &mat[i][j]);
	
		while (k--) {
		scanf (" %c %d %d", &opt, &x, &y);
		if (opt == 'g') {
			x = row[x];
			y = col[y];
			printf ("%d\n", mat[x][y]);
		} else if (opt == 'c')
			std::swap (col[x], col[y]);
		else if (opt == 'r')
			std::swap (row[x], row[y]);
	}

	return 0;
}
