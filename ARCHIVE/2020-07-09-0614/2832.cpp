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

const int N = 1e5 + 100;

int n, f;
int c[N];

bool check (int days) {
	int qnt = 0;
	for (int i = 0; i < n; i++) {
		qnt += days/c[i];
		if (qnt >= f) return true;
	}

	return false;
}

int main () {
	scanf ("%d %d", &n, &f);
	for (int i = 0; i < n; i++)
		scanf ("%d", &c[i]);
	int l = 0, r = 1e9 + 100;
	while (l < r) {
		// printf ("%lld %lld\n", l, r);
		int md = (l + r) / 2;
		if (check (md))
			r = md;
		else
			l = md + 1;
	}
	printf ("%d\n", l);

	return 0;
}
