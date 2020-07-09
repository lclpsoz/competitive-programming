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

llu dp[110][110];
char str[110];
llu lst[300];

int main () {
	int n;
	ll k;
	scanf ("%d %lld %s", &n, &k, str+1);
	vector<llu> vec;
	for (int i = 1; i <= n; i++)
		dp[0][i-1] = 1;
	vec.push_back (1);
	for (int t = 1; t <= n; t++) {
		memset (lst, 0, sizeof lst);
		for (int i = 1; i <= n; i++) {
			dp[t][i] = dp[t-1][i-1] + dp[t][i-1] - lst[str[i]];
			lst[str[i]] += dp[t][i] - dp[t][i-1];
		}
		// printf ("t = %d, qnt = %llu\n", t, dp[t][n]);
		vec.push_back (dp[t][n]);
	}
	ll ans = 0;
	int qnt = 0;
	while (k and !vec.empty ()) {
		llu now = vec.back();
		vec.pop_back ();
		ll use = min ((llu)k, now);
		k = k - use;
		ans += qnt * use;
		// printf ("k = %lld, ans = %lld\n", k, ans);
		qnt++;
	}
	if (k == 0) {
		printf ("%lld\n", ans);
	} else
		printf ("-1\n");

	return 0;
}
