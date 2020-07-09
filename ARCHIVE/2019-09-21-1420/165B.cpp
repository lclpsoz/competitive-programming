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
ll di[100];

bool check (int now) {
	int p = 0;
	ll acu = 0;
	while (now/di[p] > 0) {
		acu += now/di[p++];
// 		printf ("acu = %d, p = %d\n", acu, p);
		if (acu >= n) return true;
	}
	
	return false;
}

int main () {
	scanf ("%d %d", &n, &k);
	
	di[0] = 1;
	di[1] = k;
	for (int i = 2; i <= 30; i++) {
		if ((di[i-1] * 1LL * k) > 2'000'000'000'000LL)
			break;
		di[i] = di[i-1] * k;
	}
	int l = 1, r = n;
	while (l < r) {
		int md = (l+r)/2;
// 		printf ("%d %d %d\n", l, md, r);
		if (check (md))
			r = md;
		else
			l = md + 1;
	}
	
	
	printf ("%d\n", l);

	return 0;
}
