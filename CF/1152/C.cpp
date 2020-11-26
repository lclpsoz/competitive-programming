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

ll mdc (ll a, ll b) {
	if (a == 0) return b;
	return mdc (b%a, a);
}

ll mmc (ll a, ll b) { 
	if (a > b) swap (a, b);
	return a * (b/mdc (a, b));
	
}

vector<int> divs;

int main () {
	int a, b;
	scanf ("%d %d", &a, &b);
	if (a == b) {
	    printf ("0\n");
	    return 0;
	}
	if (a > b) swap (a, b);
	int delta = abs (a - b);
	ll ans = 1e18 + 10;
	ll bst = 1e18 + 10;
	for (int i = 1; i*i <= delta; i++) {
		if (delta%i == 0) {
			int g = i;
			ll x, y;
			x = ((a/g)) * g;
			if (x < a) x += g;
			y = b + (x-a);
			if (bst > mmc (x, y)) {
				bst = mmc (x, y);
				ans = x-a;
			}
			
			g = delta/i;
			x = ((a/g)) * g;
			if (x < a) x += g;
			y = b + (x-a);
			if (bst > mmc (x, y)) {
				bst = mmc (x, y);
				ans = x-a;
			}
		}
	}
	printf ("%lld\n", ans);
	
	return 0;
}