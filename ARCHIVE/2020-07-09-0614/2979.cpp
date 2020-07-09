#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e6;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 5010;

int n, m;
int dp[N][N];
int obs[N][N], prefCol[N][N], prefRow[N][N];

int main () {
	scanf ("%d %d", &n, &m);
	while (m--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		obs[x][y] = true;
	}

	prefCol[1][1] = prefRow[1][1] = 1;
	// printf ("%d %d\n", sum (1, 1), sum (2, 2));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != 1 or j != 1) {
				if (obs[i][j])
					prefRow[i][j] = 0, prefCol[i][j] = 0;
				else {
					int row = prefRow[i][j-1];
					int col = prefCol[i-1][j];
					// printf ("row = %d col = %d\n", row, col);
					prefRow[i][j] = (prefRow[i][j-1] + col + row)%MOD;
					prefCol[i][j] = (prefCol[i-1][j] + row + col)%MOD;
				}
				// printf ("(%3d, %3d)%c", prefRow[i][j], prefCol[i][j], " \n"[j==n]);
			}

	printf ("%d\n", (prefCol[n-1][n] + prefRow[n][n-1])%1000000);

	return 0;
}
