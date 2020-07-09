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

const int N = 1e5 + 100;

int dp[N];

int main () {
	int n; scanf ("%d", &n);
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (i-1 >= 0) dp[i] = (dp[i]+dp[i-1])%MOD;
		if (i-2 >= 0) dp[i] = (dp[i]+dp[i-2])%MOD;
		if (i-3 >= 0) dp[i] = (dp[i]+dp[i-3])%MOD;
	}
	printf ("%d\n", dp[n]);
	
	return 0;
}
