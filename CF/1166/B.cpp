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

string s = "aeiou";

int main () {
	int k;
	scanf ("%d", &k);
	int n, m;
	n = m = -1;
	for (int i = 5; i <= k; i++) {
		if (k%i == 0) {
			n = i;
			m = k/i;
			break;
		}
	}
	if (m < 5) {
		printf ("-1\n");
		exit (0);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			putchar (s[(i+j)%5]);
	putchar ('\n');

	return 0;
}
