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
	int n, k;
	scanf ("%d %d", &n, &k);
	if (n == k)
		while (n--)
			putchar ('1');
	else if (k == 2) {
		putchar ('1');
		n-=2;
		while (n--)
			putchar ('0');
		putchar ('1');
	} else if (k == 1) {
		putchar ('1');
		n--;
		while (n--)
			putchar ('0');
	} else {
		int md = (n - k)/2 + 1;
		for (int i = 0; i < n; i++)
			putchar (i%md == 0 ? '1' : '0');
	}
	putchar ('\n');

	return 0;
}
