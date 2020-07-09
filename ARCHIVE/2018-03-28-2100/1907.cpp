#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1030;

int n, m;
char mat[MAXN][MAXN];

int dire[4][2] = {	{-1, 0},
					{0, 1},
					{1, 0},
					{0,-1}		};

void dfs (int x, int y)
{
	mat[x][y] = '-';
	for (int i = 0; i < 4; i++) {
		if (mat[x+dire[i][0]][y+dire[i][1]] == '.')
			dfs (x+dire[i][0], y+dire[i][1]);
	}
}

int main ()
{
	scanf ("%d %d ", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			mat[i][j] = getchar ();
		getchar (); //'\n'
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mat[i][j] == '.') {
				ans++;
				dfs (i, j);
			}

	printf ("%d\n", ans);

	return 0;
}
