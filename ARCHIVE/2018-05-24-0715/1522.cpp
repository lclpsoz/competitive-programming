#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 102;

int n;
int mat[MAXN][3];
// Na pratica foi substituida por bitmask:
int adj[][3] =	{	{1, 0, 0},
					{0, 1, 0},
					{0, 0, 1},
					{1, 1, 0},
					{1, 0, 1},
					{0, 1, 1},
					{1, 1, 1}	};
bool dp[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
int tt;

int solve (int a, int b, int c) {
	if (vis[a][b][c] == tt) return 0;
	// printf ("%d %d %d\n", a, b, c);
	if (a == n+1 || b == n+1 || c == n+1) return 0;
	if (a == b && b == c && c == n) return 1;
	int r = 0, aux;
	int &a1 = mat[a][0];
	int &b1 = mat[b][1];
	int &c1 = mat[c][2];
	for (int i = 1; i <= 7; i++) {
		aux = 0;
		if (i&1)
			aux += a1;
		if (i&2)
			aux += b1;
		if (i&4)
			aux += c1;
		if (aux == 0 || aux == 3 || aux == 6)
			r = solve (	a + (i&1 ? 1 : 0),
						b + (i&2 ? 1 : 0),
						c + (i&4 ? 1 : 0)	);
		if (r) return 1;
	}

	dp[a][b][c] = false;
	vis[a][b][c] = tt;
	return 0;
}

int main ()
{
	tt = 1;
	while (scanf ("%d", &n), n) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++) {
				scanf ("%d", &mat[i][j]);
				mat[i][j] %= 3;
			}
		printf ("%d\n", solve (0, 0, 0));
		tt++;
	}

	return 0;
}
