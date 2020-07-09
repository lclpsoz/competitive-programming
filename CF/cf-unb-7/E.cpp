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

const int N = 1e6 + 100;

int a, b, n;
bool ok[N];

int mdc (int x, int y) {
	if (y == 0) return x;
	return mdc (y, x%y);
}

int mmc (int x, int y) {
	return (x*y)/mdc (x, y);
}

int main () {
	scanf ("%d %d %d", &a, &b, &n);
	for (int i = 0; i <= b; i++)
		for (int j = 0; j <= a; j++)
			if ((ll)a*i + (ll)b*j < N)
				ok[a*i + b*j] = true;

	ll qnt = 0;
	int md = mdc (a, b);
	int mc = mmc (a, b);
	for (int i = 1; i <= min (n, mc); i++)	
		qnt += ok[i];
	qnt += max (0, n/md - mc/md);

	md = mdc (n, qnt);
	int ax = qnt/md;
	printf ("%d/%d\n", ax, n/md);
	//int v = n/md;
	//printf ("%d / %d\n", qnt/md, v);
	//printf ("%d / %d\n", qnt/md, n/md);

	return 0;
}