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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1001;

int n, m;
bool mat[N][N];
int dp[N][N];

int solve (int x, int y) {
	if (!mat[x][y]) return 0;
	if (x == n and y == m) return 1;
	int &r = dp[x][y];
	if (r != -1) return r;
	return r = mod (solve (x+1, y) + solve (x, y+1));
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char c; scanf (" %c", &c);
			mat[i][j] = c == '.';
		}
		
	printf ("%d\n", solve (1, 1));

	return 0;
}
