#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int n, q, m;
int mat[MAXN][MAXN];

int sum (int x, int y)
{
	int s = 0;
	for (; x >= 1; x-=x&-x)
		for (int j = y; j >= 1; j-=j&-j)
			s += mat[x][j];
	return s;
}

void add (int val, int x, int y)
{
	for (; x <= n; x+=x&-x)
		for (int j = y; j <= n; j+=j&-j) {
			mat[x][j]+=val;
		}
}

int main ()
{
	int val;
	while (scanf ("%d %d", &n, &m) != EOF) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				mat[i][j] = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf ("%d", &val);
				if (val)
					add (1, i, j);
				// printf ("%d ", mat[i][j]);
			}
			// putchar ('\n');
		}

		int x1, y1, x2, y2;
		while (m--) {
			// printf ("--------------\n");
			scanf ("%d %d", &x1, &y1);
			add (1, x1, y1);
			scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
			/*for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= n; j++)
					printf ("%d ", mat[i][j]);
				putchar ('\n');
			}*/
			/*printf ("%d %d %d %d\n",
					sum (x2, y2),
					sum(x1-1, y2),
					sum (x2, y1-1),
					sum (x1-1, y1-1));*/
			int s =   sum (x2, y2)
					- sum (x1-1, y2)
					- sum (x2, y1-1)
					+ sum (x1-1, y1-1);
			printf ("%d\n", s);
		}
	}

	return 0;
}
