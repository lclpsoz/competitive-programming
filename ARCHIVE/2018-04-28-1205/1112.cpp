#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1010;

int n, m, p, q;
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
		for (int j = y; j <= m; j+=j&-j) {
			mat[x][j]+=val;
		}
}

int main ()
{
	int val;
	while (scanf ("%d %d %d", &n, &m, &p), n || m || p) {
		scanf ("%d", &q);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				mat[i][j] = 0;

		int x1, y1, x2, y2, val;
		while (q--) {
			// printf ("--------------\n");
			char c;
			scanf (" %c", &c);
			if (c == 'A') {
				scanf ("%d %d %d", &val, &x1, &y1);
				x1++;
				y1++;
				add (val, x1, y1);
			}
			else {
				scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
				x1++;
				y1++;
				x2++;
				y2++;
				if (x1 > x2)
					swap (x1, x2);
				if (y1 > y2)
					swap (y1, y2);
				/*for (int i = 1; i <= n; i++) {
					for (int j = 1; j <= m; j++)
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
				printf ("%d\n", s*p);
			}
		}
		printf ("\n");
	}

	return 0;
}
