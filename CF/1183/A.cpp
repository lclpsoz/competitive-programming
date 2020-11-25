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


int main () {
	int a;
	scanf ("%d", &a);
	for (int i = a;; i++) {
		int aa = i;
		int val = 0;
		while (aa > 0) {
			val += aa%10;
			aa/=10;
		}
		if (val%4 == 0) {
			printf ("%d\n", i);
			exit (0);
		}
	}
	printf ("%d\n", a);

	return 0;
}
