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

int n;
vector<int> divs;
map<int, int> mp;

int mdc (int a, int b) {
	if (a == 0) return b;
	return mdc (b%a, a);
}

int mmc (int a, int b) { return (a*b)/mdc (a,b); }

int main () {
	scanf ("%d", &n);
	int x = 1, y = 1;
	int mx = 0;
	for (int i = 0; i < n; i++) {
		int v;
		scanf ("%d", &v);
		
		mx = max (mx, v);
		mp[v]++;
	}
	x = mx;
	
	for (pii p : mp)
		if (x % p.x == 0)
			mp[p.x]--;
	for (pii p : mp)
		if (p.y > 0)
			y = mmc (y, p.x);
		
	printf ("%d %d\n", x, y);
	
	return 0;
}
