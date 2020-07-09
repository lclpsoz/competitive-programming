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
	int n;
	scanf("%d", &n);
	ld best = 1e18;
	ld ans = 0;
	while(n--) {
		ld price; int g;
		scanf("%Lf %d", &price, &g);
		if(price/g < best) {
			best = price/g;
			ans = (price/g)*1000;
		}
	}
	printf("%.2Lf\n", ans);

	return 0;
}
