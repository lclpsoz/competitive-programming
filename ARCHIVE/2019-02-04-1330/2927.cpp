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

int a, c, x, y;

int main () {
	scanf ("%d %d %d %d", &a, &c, &x, &y);
	if (c-x-y-1 >= a)
		printf ("Igor feliz!\n");
	else if (x > y/2)
		printf ("Caio, a culpa eh sua!\n");
	else
		printf ("Igor bolado!\n");

	return 0;
}
