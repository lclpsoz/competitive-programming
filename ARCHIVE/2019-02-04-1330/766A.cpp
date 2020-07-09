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
	string a, b;
	cin >> a >> b;
	if (len (a) != len (b))
		printf ("%d\n", max (len (a), len(b)));
	else {
		for (int i = 0; i < len (a); i++)
			if (a[i] != b[i]) {
				printf ("%d\n", len (a));
				exit (0);
			}
		printf ("-1\n");
	}
	

	return 0;
}
