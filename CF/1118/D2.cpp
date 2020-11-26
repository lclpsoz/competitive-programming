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

const int N = 110;

int n, m;
int total;
int a[N];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		total += a[i];
	}
	int ans = n;
	int days = n;
	int totalNow = total;
	while (totalNow >= m) {
		ans = days;
		--days;
		totalNow = total;
		int x = days, y = n-days;
		int aux = 1;
		while (y > 0) {
			totalNow -= aux * min (y, x);
			y -= x;
			aux++;
		}
	}
	printf ("%d\n", ans);

	return 0;
}
