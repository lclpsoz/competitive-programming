#include <bits/stdc++.h>
using namespace std;

const int MAXN = 210;

char mat[MAXN][MAXN];
int adj[][2] = { {0,0},
				{0,1},
				{0,-1},
				{1,0},
				{1,1},
				{1,-1},
				{-1,0},
				{-1,1},
				{-1,-1}	};

int ans;

void dfs (int x, int y)
{
	if (mat[x][y] == 'v') {
		ans++;
		mat[x][y] = 'p';
		for (int i = 0; i < 9; i++)
			dfs (adj[i][0]+x, adj[i][1]+y);
	}
}


int main ()
{

	int n, m, x, y, k;
	scanf ("%d %d %d %d %d", &n, &m, &x, &y, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			mat[i][j] = 'v';

	int a, b;
	while (k--) {
		scanf ("%d %d", &a, &b);
		mat[a][b] = 'c';
	}

	dfs (x, y);

	printf ("%d\n", ans);

	return 0;
}
