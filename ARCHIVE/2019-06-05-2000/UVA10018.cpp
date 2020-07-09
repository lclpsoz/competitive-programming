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

int t;
unsigned int x;

bool isPal (string s) {
	for (int i = 0, j = len (s) - 1; i < j; i++, j--)
		if (s[i] != s[j]) return false;
	return true;
}

unsigned int inv (unsigned int v) {
	unsigned int r = 0;
	while (v) {
		r *= 10;
		r += v%10;
		v /= 10;
	}
	
	return r;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%u", &x);
		int qnt = 0;
		while (!isPal (to_string (x)))
			x += inv (x), ++qnt;
		
		printf ("%d %u\n", qnt, x);
	}

	return 0;
}
