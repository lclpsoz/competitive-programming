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

const int N = 2e5 + 10;

map<pii, int> mp;
int a[N], b[N];

int mdc (int x, int y) {
	if (y == 0) return x;
	return mdc (y, x%y);
}

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf ("%d", &b[i]);
	
	int univ = 0;
	for (int i = 0; i < n; i++) {
		int x = a[i], y = b[i]; // y/x
		ll sig = x * 1LL * y * -1;
		if (x == 0 and y == 0)
			++univ;
		else if (y == 0)
			mp[{0, 0}]++;
		else if (x == 0)
			continue;
		else {
			x = abs (x), y = abs (y);
			int md = mdc (x, y);
			x /= md, y /= md;
			sig = sig > 0 ? 1 : -1;
			mp[{sig * y, x}]++;
		}
	}
	int ans = 0;
	for (auto p : mp)
		ans = max (ans, p.y);
	printf ("%d\n", ans+univ);

	return 0;
}
