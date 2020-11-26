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

const ll INF = 1e18 + 10;
const int N = 2e5 + 2010;

int n, m, k;
ll dp[N];
int a[N];
ll pref[N];
vector<pii> vec;

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf ("%d", &a[i]);
	sort (a+1, a+n+1);
	for (int i = 1; i <= n; i++) {
		pref[i] = pref[i-1] + a[i];
	}

	while (m--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		vec.push_back ({x, y});
	}
	sort (vec.begin(), vec.end());
	vec.resize (unique (vec.begin(), vec.end()) - vec.begin());

	for (int i = 0; i <= n; i++)
		dp[i] = pref[i];
	for (int i = n+1; i < N; i++) dp[i] = INF;

	for (int i = 0; i <= k; i++)
		for (auto p : vec)
			if (i+p.x <= k)
				dp[i+p.x] = min (dp[i+p.x], dp[i] + pref[i+p.x] - pref[i+p.y]);

	printf ("%lld\n", dp[k]);

	return 0;
}
