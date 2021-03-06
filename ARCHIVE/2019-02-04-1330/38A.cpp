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
int d[110];

int main () {
	scanf ("%d", &n);
	for (int i = 1; i < n; i++)
		scanf ("%d", &d[i]);
	int a, b;
	scanf ("%d %d", &a, &b);
	int ans = 0;
	for (int i = a; i < b; i++)
		ans += d[i];
	printf ("%d\n", ans);

	return 0;
}
