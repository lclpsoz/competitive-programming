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
	int qntLst = 0;
	int qnt = 0, typ = -1;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		if (x != typ) {
			ans = max (ans, min (qnt, qntLst));
			typ = x;
			qntLst = qnt;
			qnt = 0;
			++qnt;
		} else
			++qnt;
	}
	ans = max (ans, min (qnt, qntLst));
	printf ("%d\n", ans*2);

	return 0;
}
