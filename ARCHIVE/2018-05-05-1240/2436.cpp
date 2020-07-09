#include <bits/stdc++.h>
using namespace std;

char mat[1010][1010];
int adj[][2] = {{0, 1},
				{0, -1},
				{1, 0},
				{-1, 0}	};

int fx, fy;

void dfs (int x, int y) {
	fx = x;
	fy = y;
	mat[x][y] = '-';
	for (int i = 0; i < 4; i++)
		if (mat[x+adj[i][0]][y+adj[i][1]] == 'P')
			dfs (x+adj[i][0], y+adj[i][1]);
}

int main ()
{
	int l, c, x, y, z;
	scanf ("%d %d", &l, &c);
	scanf ("%d %d", &x, &y);
	for (int i = 1; i <= l; i++)
		for (int j = 1; j <= c; j++) {
			scanf ("%d", &z);
			if (z == 1) mat[i][j] = 'P';
			else mat[i][j] = 'B';
		}
	dfs (x, y);
	printf ("%d %d\n", fx, fy);

	return 0;
}
