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

int a, b, c;
string s = "ffrcfcr";

int main () {
	cin >> a >> b >> c;
	int weeks = min (a/3, min (b/2, c/2));
	a -= 3*weeks;
	b -= 2*weeks;
	c -= 2*weeks;
	int ans = -1;
	for (int i = 0; i < 7; i++) {
		int x = a, y = b, z = c;
		int now = 0;
		for (int j = 0;true; j++) {
			int d = (i+j)%7;
			if (s[d] == 'f') {
				if (!x) { now = j; break; }
				--x;
			} else if (s[d] == 'r') {
				if (!y) { now = j; break; }
				--y;
			} else {
				if (!z) { now = j; break; }
				--z;
			}
		}
		ans = max (now, ans);
	}
	printf ("%d\n", ans + 7*weeks);

	return 0;
}
