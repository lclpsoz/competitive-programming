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

set<ll> st;

ll prec (int b, int k) {
	ll ret = 1;
	for (int i = 0; i < k; i++) ret *= b;

	return ret;
}

int a[100010];

int main () {
	int n, k;
	scanf ("%d %d", &n, &k);
	for (ll i = 1; i < 100100; i++) {
		ll now = prec (i, k);
		if (now > 1e10 + 1000) break;
		st.insert (now);
	}

	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	int ans= 0 ;
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			ans += st.count (a[i]*1LL*a[j]);
	printf ("%d\n", ans);

	return 0;
}
