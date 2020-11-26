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

int n, radius;

ld radPol (ld x) { return x/(2*sin((ld)acos((ld)-1)/n)); }


ld verif (ld x) {
	ld b = radPol (x) - radius;
	ld a = x/2;
// 	printf ("a-b: %Lf\n", a-b);
	return a-b;
}

int main () {
// 	n = 4;
// 	printf ("%Lf\n", verif (2));
	scanf ("%d %d", &n, &radius);
	ld l, r;
	l = 1e-9, r = 1e9;
	int qnt = 0;
	while (cmp (l, r) == -1 and qnt < 1e5) {
		ld md = (l+r)/2;
		ld now = verif (md);
		if (cmp (now) == 0)
			l = r = md;
		else if (cmp (now) == -1) // a > b
			r = md+EPS;
		else
			l = md-EPS;
		++qnt;
	}
// 	printf ("%d\n", qnt);
	
	printf ("%.16Lf\n", l/2.0);

	return 0;
}
