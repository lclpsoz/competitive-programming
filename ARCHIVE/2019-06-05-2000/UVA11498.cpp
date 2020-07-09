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
	int k, a, b;
	while (scanf ("%d", &k), k) {
		int x, y;
		scanf ("%d %d", &x, &y);
		while (k--) {
			scanf ("%d %d", &a, &b);
			a -= x;
			b -= y;
			if (!a or !b)
				printf ("divisa");
			else {
				putchar (b > 0 ? 'N' : 'S');
				putchar (a > 0 ? 'E' : 'O');
			}
			putchar ('\n');
		}
	}

	return 0;
}
