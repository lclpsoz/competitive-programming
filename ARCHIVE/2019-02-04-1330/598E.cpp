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

const int INF = 1e9;
int t, n, m, k;
int dp[31][31][51];

int solve (int x, int y, int acu) {
	if (acu == 0 or acu == x*y)
		return 0;
	if (acu > x*y or acu < 0)
		return INF;
	
	int &ret = dp[x][y][acu];
	if (ret != -1) return ret;
	ret = INF;
	for (int i = 1; i < x; i++) {
		ret = min (ret, solve (x-i, y, acu - (i * y)) + y * y);
		ret = min (ret, solve (x-i, y, acu) + y * y);
	}
	for (int i = 1; i < y; i++) {
		ret = min (ret, solve (x, y-i, acu - (i*x)) + x * x);
		ret = min (ret, solve (x, y-i, acu) + x * x);
	}
// 	printf ("x: %d, y: %d, acu: %d, ret = %d\n", x, y, acu, ret);
	
	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &n, &m, &k);
		printf ("%d\n", solve (n, m, k));
	}

	return 0;
}
