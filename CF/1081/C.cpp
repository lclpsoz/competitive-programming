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

const int MOD = 998244353;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2010;

int n, m, k;
int dp[N][2]; // dp[QNT_DIFF][POS]
// int sumAll[N][2];// sumAll[QNT_DIFF][POS]

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	dp[0][0] = m;
	for (int i = 1; i < n; i++) {
		int p = i&1;
		dp[0][p] = dp[0][!p];
		for (int j = 1; j <= k; j++)
			dp[j][p] = mod (dp[j][!p] + mod (dp[j-1][!p] * 1LL * (m-1)));
	}
	
	printf ("%d\n", dp[k][(n-1)&1]);

	return 0;
}
