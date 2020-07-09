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

int p;

int powMod (int b, int pt) {
	int r = 1;
	while (pt) {
		if (pt&1)
			r = (r * b)%p;
		pt>>=1;
		b = (b*b)%p;
	}
	
	return r;
}

bool eval (int x) {
	for (int i = 1; i < p-1; i++)
		if (powMod (x, i) == 1)
			return false;
		
	return powMod (x, p-1) == 1;
}

int main () {
	scanf ("%d", &p);
	int ans = 0;
	for (int i = 1; i < p; i++)
		if (eval (i))
			++ans;
	printf ("%d\n", ans);

	return 0;
}
