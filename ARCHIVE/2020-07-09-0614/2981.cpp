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

int c, g;

int main () {
	scanf ("%d %d", &c, &g);
	c /= g;
	c += 21;
	if (c > 30)
		printf ("A UFSC fecha dia %d de outubro.\n", c-30);
	else
		printf ("A UFSC fecha dia %d de setembro.\n", c);

	return 0;
}
