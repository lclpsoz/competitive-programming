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

const ll INF = 1e18;
const int N = 210;

int a[N];
ll dp[N][N];

ll n, k, x;

ll solve (int p, int qnt) {
	if (qnt == x) {
		if (n-p <= k)
			return 0;
		return -INF;
	}
 	if (qnt > x)
		return -INF;

	ll &r = dp[p][qnt];
	if (r != -1)
		return r;
	
	r = -INF;
	for (int i = 1; i <= k and (p+i) < n; i++)
		r = max (r, solve (p+i, qnt+1) + a[p+i]);
	
	return r;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d %d", &n, &k, &x);
	for (int i = 0; i < n; i++)
		scanf ("%lld", &a[i]);

	if (n/k > x) {
		printf ("-1\n");
		return 0;
	}
	
	ll ans = 0;
	for (int i = 0; i < k; i++)
		ans = max (ans, solve (i, 1) + a[i]);
	assert (ans >= 0);
	printf ("%lld\n", ans);
	
	return 0;
}
