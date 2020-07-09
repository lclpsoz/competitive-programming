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

int c;
inline int mod (ll x, int m = c) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int gcd (int a, int b) {
	if (a == 0) return b;
	return gcd (b%a, a);
}
	
int powMod (int b, int e, int m = c) {
	int r = 1;
	while (e) {
		if (e&1) r = mod (r * 1LL * b, m);
		b = mod (b * 1LL * b, m);
		e >>= 1;
	}
	
// 	printf ("r: %d\n", r);
	return r;
}

int invMod (int b, int m = c) {
	return powMod (b, m-2, m);
}

// Return Geometric Series of a**0 + a**1 + a**2 + ... + a**n-1.
int geoSeriesDivConq (int a, int n) {
	if (n == 1)
		return 1;
	int r = 0; 
	if (n&1) {
		r = powMod (a, n-1);
		--n;
	}
	return mod (r + (1 + powMod (a, n/2)) * 1LL * geoSeriesDivConq (a, n/2));
}

int main () {
	int x, a, n;
	while (scanf ("%d", &x), x) {
		scanf ("%d %d %d", &a, &n, &c);
		int frst = mod (x * 1LL * powMod (a, n));
		int sec = geoSeriesDivConq (a, n+1);
		printf ("%d\n", mod (frst - sec + 1));
	}

	return 0;
}
