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

bool a[400];

int main () {
	a[0] = true;
	int n, total = 0;
	cin >> n;
	if (n == 1) printf ("NO\n"), exit (0);
	while (n--) {
		int x;
		cin >> x;
		x /= 100;
		total += x;
		if (x == 1)
			for (int i = 399; i >= 1; i--)
				a[i] = a[i] or a[i-1];
		else
			for (int i = 399; i >= 2; i--)
				a[i] = a[i] or a[i-2];
	}
	printf ("%s\n", total%2 == 0 and a[total/2] ? "YES" : "NO");
	

	return 0;
}
