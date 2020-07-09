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

map<int, int> mp;

int f (int x) {
	if (x == 0) return 1;
	if (x%2 == 0) return f (x/2);
	return f(x/2) + 1;
}

int main () {
	int n;
	scanf ("%d", &n);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		mp[f(x)]++;
	}
	for (auto p : mp)
		ans += (p.y*1LL*(p.y-1))/2;
	printf ("%lld\n", ans);
	return 0;
}
