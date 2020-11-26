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

const int MOD = 998244353;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+10;

map<int, int> posMin, posMax;
int a[N];

int powMod (int b, int p) {
	int ret = 1;
	while (p) {
		if (p&1) ret = mod (ret * 1LL * b);
		p >>= 1;
		b = mod (b * 1LL * b);
	}
	
	return ret;
}

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		if (posMin.count (a[i]) == 0)
			posMin[a[i]] = i;
		posMax[a[i]] = i;
	}
	
	int qnt = 0;
	int r = 0;
	for (int i = 0; i < n; i++) {
		if (r < i)
			r = i;
		r = max (r, posMax[a[i]]);
		if (i == r)
			++qnt;
	}
	printf ("%d\n", powMod (2, qnt-1));

	return 0;
}
