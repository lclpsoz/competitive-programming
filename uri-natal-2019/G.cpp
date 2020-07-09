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

int main () {
	scanf ("%d", &n);
	while (n--) {
		ll x, d;
		ll j = 0, m = 0;
		for (int i = 0; i < 3; i++) {
			scanf ("%lld %lld", &x, &d);
			j += x*d;
		}
		for (int i = 0; i < 3; i++) {
			scanf ("%lld %lld", &x, &d);
			m += x*d;
		}
		if (m == j)
			printf ("EMPATE\n");
		else
			printf ("%s\n", j > m ? "JOAO" : "MARIA");
	}

	return 0;
}
