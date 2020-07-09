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
	int l = 0, r = 0;
	bool sw = false;
	for (int i = 0; i < n; i++) {
		int x = 0, y = 0;
		scanf ("%d %d", &x, &y);
		l = (l+x)%2;
		r = (r+y)%2;
		if (y&1)
			swap (x, y);
		if (x&1 and !(y&1))
			sw = true;
	}
	if (l%2 == 0 and r%2 == 0)
		printf ("0\n");
	else if (l%2 == 1 and r%2 == 1 and sw)
		printf ("1\n");
	else
		printf ("-1\n");

	return 0;
}