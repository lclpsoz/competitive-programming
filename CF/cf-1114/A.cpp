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

void no () {
	printf ("NO\n");
	exit (0);
}

int main () {
	int x, y, z;
	int a, b, c;
	scanf ("%d %d %d", &x, &y, &z);
	scanf ("%d %d %d", &a, &b, &c);
	
	if (a >= x) {
		a -= x;
	} else {
		no ();
	}
	
	if ((a+b) >= y) {
		a -= y;
	} else
		no();
	
	if ((a+b+c) >= z)
		printf ("YES\n");
	else
		no();

	return 0;
}
