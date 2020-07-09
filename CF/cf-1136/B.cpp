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

int n, k;
bool ok[5010];
int p;
int ans;

void esq () {
	while (p > 1) {
		++ans;
		--p;
		if (!ok[p]) {
			ok[p] = true;
			ans += 2;
		}
	}
}

void dir () {
	while (p < n) {
		++ans;
		++p;
		if (!ok[p]) {
			ok[p] = true;
			ans += 2;
		}
	}
}

int main () {
	scanf ("%d %d", &n, &k);
	ans = 3; 
	ok[k] = true;
	p = k;
	if (k <= n/2) {
		esq();
		dir();
	} else {
		dir();
		esq();
	}

	printf ("%d\n", ans);

	return 0;
}
