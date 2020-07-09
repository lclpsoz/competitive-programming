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

int n, k, q;

int powMod (int b, int p) {
	int r = 1;
	while (p) {
		if (p&1)
			r = mod (r*1LL*b, n);
		
		p >>= 1;
		b = mod (b*1LL*b, n);
	}
	
	return r;
}

int invMod (int b) {
	return powMod (b, n-2);
}

int main () {
	scanf ("%d %d %d", &n, &k, &q);
	int invK = invMod (k);
	while (q--) {
		int c, d;
		scanf ("%d %d", &c, &d);
		int r = 0;
		if (k%n == 0) {
			if (d == 0)
				r = c;
		} else {
			r = c/n;
			c %= n;
			int aux = mod (invK*1LL*d, n);
			++aux;
			if (aux <= c)
				++r;
		}
		
		printf ("%d\n", r);
	}

	return 0;
}
