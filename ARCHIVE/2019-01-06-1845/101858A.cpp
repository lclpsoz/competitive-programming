#include <bits/stdc++.h>
using namespace std;

// ------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (x%m);
}

// ------------

const int N = 1e7+100;

int n, bef, now, acu;

int main () {
	scanf ("%d", &n);
	if (n&1) {
		printf ("0\n");
		return 0;
	}
	bef = 1;
	acu = 2*bef;
	for (int i = 1; i <= n/2; i++) {
		now = mod (bef + acu);
		acu = mod (2*1LL*now + acu);
		bef = now;
	}
	printf ("%d\n", now);
		
	return 0;
}
