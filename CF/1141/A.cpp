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
	int n, m;
	scanf ("%d %d", &n, &m);
	int x, y;
	x = y = 0;
	while (m%2 == 0) {
		m /= 2;
		++x;
	}
	
	while (m%3 == 0) {
		m/=3;
		++y;
	}
	while (n%2 == 0) {
		n /= 2;
		--x;
	}
	
	while (n%3 == 0) {
		n/=3;
		--y;
	}
	if (n != m or x < 0 or y < 0) printf ("-1\n");
	else printf ("%d\n", x+y);

	return 0;
}
