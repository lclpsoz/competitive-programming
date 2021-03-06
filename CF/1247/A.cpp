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
	int da, db;
	cin >> da >> db;
	if (da == db-1) {
		printf ("%d9 %d0", da, db);
	} else if (da == db) {
		printf ("%d0 %d1", da, db);
	} else if (da == 9 and db == 1)
		printf ("9 10\n");
	else
		printf ("-1\n");

	return 0;
}
