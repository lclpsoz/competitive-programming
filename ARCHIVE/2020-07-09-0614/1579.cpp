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

const int N = 102;

int nP, nC, frete;
int t;
int a[N];

bool check (int x) {
	int qnt = 1;
	int carga = 0;
	for (int i = 0; i < nP; i++) {
		if (a[i] > x) return false;
		carga += a[i];
		if (carga > x) {
			++qnt;
			carga = a[i];
		}
		// printf ("x = %d, carga = %d, qnt = %d\n", x, carga, qnt);
	}

	return qnt <= nC;
}

int main () {
	scanf ("%d", &t);
	while (t--) {
		scanf ("%d %d %d", &nP, &nC, &frete);

		for (int i = 0; i < nP; i++)
			scanf ("%d", &a[i]);
		for (int i = 0;; i++)
			if (check (i)) {
				printf ("%d $%lld\n", l, nC*l*1LL*frete);
				break;
			}
	}

	return 0;
}
