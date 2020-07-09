#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 510;

int adj[4][2] = {	{1, 0},
					{-1, 0},
					{0, 1},
					{0, -1}	};
int vert;
char mat[MAXN][MAXN];
bool vis[MAXN][MAXN];
pii maxi;
int val;

// Saves  vertice with maximum distance
// to start
int dfs (pii v, int p) {
	if (p > val) {
		maxi = v;
		val = p;
	}
	vis[v.x][v.y] = true;
	for (int i = 0; i < 4; i++) {
		int x = v.x+adj[i][0];
		int y = v.y+adj[i][1];
		if (mat[x][y] == '.' && !vis[x][y])
			dfs ({x, y}, p+1);
	}
	vis[v.x][v.y] = false;
}

int main ()
{
	int n, m;
	while (scanf ("%d %d", &n, &m), n || m) {

		for (int i = 1; i <= n; i++) {
			getchar ();
			for (int j = 1; j <= m; j++) {
				mat[i][j] = getchar ();
				if (mat[i][j] == '.')
					maxi = {i, j};
			}
			mat[i][m+1] = '\0';
		}
		for (int i = 1; i <= m+1; i++)
			mat[n+1][i] = '\0';

		val = -1;
		dfs (maxi, 0);
		dfs (maxi, 0);

		printf ("%d\n", val);
	}


	return 0;
}
