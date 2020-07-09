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

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int M = 210, C = 22;

int t;
int m, c, k;
bool dp[M][C];

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &m, &c);
		memset (dp, 0, sizeof dp);
		dp[0][0] = true;
		for (int i = 1; i <= c; i++) {
		scanf ("%d", &k);
			while (k--) {
				int x;
				scanf ("%d", &x);
				for (int j = x; j <= m; j++)
					if (dp[j-x][i-1]) dp[j][i] = true;
			}
		}
		int ans = -1;
		for (int i = 0; i <= m; i++)
			if (dp[i][c]) ans = i;
		if (ans == -1) printf ("no solution\n");
		else printf ("%d\n", ans);

	}
	
	return 0;
}
