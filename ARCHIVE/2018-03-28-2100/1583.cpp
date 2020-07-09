#include <bits/stdc++.h>
using namespace std;

int x, y;
char mat[60][60];

void dfs (int i, int j)
{
	mat[i][j] = 'T';
	if (i > 0 && mat[i-1][j] == 'A')
		dfs (i-1, j);
	if (j > 0 && mat[i][j-1] == 'A')
		dfs (i, j-1);
	if (i < x-1 && mat[i+1][j] == 'A')
		dfs (i+1, j);
	if (j < y-1 && mat[i][j+1] == 'A')
		dfs (i, j+1);
}

int main ()
{
	while (scanf ("%d %d", &x, &y), x && y) {
		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				scanf (" %c", &mat[i][j]);

		for (int i = 0; i < x; i++)
			for (int j = 0; j < y; j++)
				if (mat[i][j] == 'T')
					dfs (i, j);

		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++)
				putchar (mat[i][j]);
			putchar ('\n');
		}
		putchar ('\n');
	}
	return 0;
}
