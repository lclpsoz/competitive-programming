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

int k;

int main () {
	scanf ("%d", &k);
	if (k%2 == 0) {
		int n = 2000;
		printf ("%d\n", n);
		printf ("0 -1");
		int val = (k + 2000)/2;
		for (int i = 3; i <= n; i++) {
			printf (" %d", min (1000000, val));
			val -= min (1000000, val);
		}
	} else {
		int n = 1999;
		printf ("%d\n", n);
		printf ("0 -1");
		int val = (k + 1999)/2;
		for (int i = 3; i <= n; i++) {
			printf (" %d", min (1000000, val));
			val -= min (1000000, val);
		}
	}
	putchar ('\n');

	return 0;
}
