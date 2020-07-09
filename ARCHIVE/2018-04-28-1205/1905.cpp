#include <bits/stdc++.h>
using namespace std;

int adj[][2] = {{0, 1},
				{1, 0},
				{0, -1},
				{-1, 0}	};
bool mat[7][7];
bool ans;

void dfs (int x, int y)
{
	mat[x][y] = true;
	// printf ("%d %d\n", x, y);
	if (x == 5 && y == 5)
		ans = true;
	for (int i = 0; i < 4; i++) {
		if (mat[x+adj[i][0]][y+adj[i][1]] == 0)
			dfs (x+adj[i][0], y+adj[i][1]);
	}
}

int main ()
{
	int n;
	ans = false;
	scanf ("%d", &n);
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			mat[i][j] = true;
	while (n--) {
		ans = false;
		for (int i = 1; i <= 5; i++)
			for (int j = 1; j <= 5; j++) {
				int x;
				scanf ("%d", &x);
				mat[i][j] = x;
			}
		dfs (1, 1);
		printf ("%s\n", ans ? "COPS" : "ROBBERS");
	}


	return 0;
}
