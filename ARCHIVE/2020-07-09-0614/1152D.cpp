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

int n;

int dp[1010][1010][2];

int solve (int op, int aval, bool can) {
	if (aval < 0 or op < 0 or (op == 0 and aval == 0)) return 0;
	int &ret = dp[op][aval][can];
	if (ret != -1) return ret;
	if (can)
		ret = solve (op + 1, aval - 1, false) + solve (op - 1, aval, false) + 1;
	else
		ret = solve (op + 1, aval-1, true) + solve (op - 1, aval, true);
	// printf ("op = %d, aval = %d, can = %d, ret = %d\n", op, aval, can, ret);
	ret %= MOD;
	return ret;
}

int main () {
	scanf ("%d", &n);
	memset (dp, -1, sizeof dp);
	printf ("%d\n", solve (0, n, 0));

	return 0;
}
