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

string a, b;

void yes () {
	printf ("YES\n");
	exit (0);
}

void no () {
	printf ("NO\n");
	exit (0);
}

int main () {
	cin >> a >> b;
	if (len (a) != len (b))
		printf ("NO\n");
	else if (a == b)
		printf ("YES\n");
	else {
		int p1, p2;
		p1 = -1, p2 = -1;
		for (int i = 0; i < len (a); i++) {
			if (a[i] != b[i])
				if (p1 == -1)
					p1 = i;
				else if (p2 == -1)
					p2 = i;
				else
					no ();
		}
		if (p2 != -1 and a[p1] == b[p2] and a[p2] == b[p1])
			yes();
		else
			no ();
	}

	return 0;
}
