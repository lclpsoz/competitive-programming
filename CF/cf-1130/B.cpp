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

const int N = 1e5 + 10;

int n;
map<int, pii> mp;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < 2*n; i++) {
		int x;
		scanf ("%d", &x);
		if (mp.count (x) == 0)
			mp[x].x = i;
		else
			mp[x].y = i;
	}
	ll ans = mp[1].x + mp[1].y;
	for (int i = 1; i < n; i++) {
		int p1 = abs (mp[i].x - mp[i+1].x) + 
					abs (mp[i].y - mp[i+1].y);
		int p2 = abs (mp[i].y - mp[i+1].x) + 
					abs (mp[i].x - mp[i+1].y);
		ans += min (p1, p2);
	}
	printf ("%lld\n", ans);

	return 0;
}
