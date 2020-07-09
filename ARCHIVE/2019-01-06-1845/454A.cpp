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

int n;

int main () {
	scanf ("%d", &n);
	bool dec = true;
	int qnt = n/2;
	for (int i = 1; i <= n; i++) {
		int aux = qnt;
		for (int j = 1; j <= n; j++) {
			if (j <= aux or (n-j) < aux)
				putchar ('*');
			else
				putchar ('D');
		}
		putchar ('\n');
		if (qnt == 0)
			dec = false;
		if (dec)
			qnt--;
		else
			qnt++;
	}

	return 0;
}
