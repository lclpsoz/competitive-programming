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

const int N = 3e5 + 10;

int n;
ll a[N];
ll dp[N][6], x;

int main () {
	scanf ("%d %lld", &n, &x);
	for (int i = 0; i < n; i++)
		scanf ("%lld", &a[i]);
	
	dp[0][0] = 0;
	dp[0][1] = a[0];
	dp[0][2] = a[0]*x;
	
	ll ans = max (a[0], a[0]*x);
	ans = max (0ll, ans);
	for (int i = 1; i < n; i++) {
		dp[i][1] = max (dp[i-1][1] + a[i], a[i]);
		ans = max (ans, dp[i][1]);
		
		dp[i][2] = max (dp[i-1][1] + a[i]*x, a[i]*x);
		dp[i][2] = max (dp[i][2], dp[i-1][2] + a[i]*x);
		ans = max (ans, dp[i][2]);
		
		dp[i][3] = max (dp[i-1][2] + a[i], dp[i-1][3] + a[i]);
		ans = max (ans, dp[i][3]);
	}
	
	printf ("%lld\n", ans);

	return 0;
}
