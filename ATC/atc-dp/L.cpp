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

const int N = 3010;

int n;
ll dp[N][N];
ll a[N];
ll sum;

ll solve (int l, int r) {
	if (r < l) return 0;
	ll &ret = dp[l][r];
	if (ret != -1) return ret;
	return ret = max (min (solve (l+2, r), solve (l+1, r-1)) + a[l],
					min (solve (l+1, r-1), solve (l, r-2)) + a[r]);
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		sum += a[i];
	}
	
	ll x = solve (1, n);
	ll y = sum - x;
	printf ("%lld\n", x - y);

	return 0;
}
