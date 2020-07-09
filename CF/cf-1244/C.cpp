#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((ll)(x).size())
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

const int W = 1e5 + 10;

ll mp[W];

int main () {
	memset (mp, -1, sizeof mp);
	ll n, p, w, d;
	cin >> n >> p >> w >> d;
	if (w*n < p)
		cout << -1 << '\n';
	else if (p%w == 0)
		cout << p/w << " 0 " << n-(p/w) << '\n';
	else {
		ll x = -1, y;
		for (ll i = p/w; i >= max (0LL, p/w - 1000000); i--)
			if ((p - w*i)%d == 0) {
				x = i, y = (p - w*i)/d;
				break;
			}


		if (x != -1 and x + y <= n)
			cout << x << ' ' << y << ' ' << n-(x+y) << '\n';
		else
			cout << -1 << '\n';
	}

	return 0;
}
