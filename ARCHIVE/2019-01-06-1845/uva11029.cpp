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

int powModRight (int b, int p) {
	int ans = 1;
	int m = 1000000;
	while (p) {
		if (p&1)
			ans = (ans * 1LL * b)%m;
		b = (b * 1LL * b) % m;
		p >>= 1;
	}
	
	return ans%1000;
}

int qntDig (ll x) {
	int r = 0;
	while (x) {
		x /= 10;
		++r;
	}
	
	return r;
}

ll modDig (ll x, int qD) {
	int q = qntDig (x);
	while (q-- > qD)
		x /= 10;
	
	return x;
}

ll multDig (ll b, ll tm, int qD) {
// 	printf ("b = %lld, tm =  %lld\n", b, tm);
	ll r = 0;
	while (tm) {
		if (tm&1) {
			r = r + b;
			if (qntDig (r) > qD) {
				r /= 10;
				b /= 10;
			}
		}
		b = b+b;
		if (qntDig (b) > qD) {
			r /= 10;
			b /= 10;
		}
		tm >>= 1;
// 		printf ("tm: %lld\n", tm);
	}

	return r;
}

int powModLeft (ll b, ll p) {
	ll ans = 1;
	int qD = 17;
	while (p) {
		if (p&1)
			ans = multDig (ans, b, qD);
		b = multDig (b, b, qD);
		p >>= 1;
// 		printf ("p = %d\n", p);
	}
	
	return modDig (ans, 3);
}

int main () {
// 	ll x, y;
// 	scanf  ("%lld %lld", &x, &y);
// 	
// 	printf ("%lld\n", multDig (x, y, 17));
	
	int t, b, p;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d", &b, &p);
		int rg = powModRight (b, p);
		int lf = powModLeft (b, p);
		printf ("%0.3d...%0.3d\n", lf, rg);
	}

	return 0;
}