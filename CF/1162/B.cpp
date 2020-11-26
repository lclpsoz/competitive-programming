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

int n, m;
int a[60][60], b[60][60];


int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) scanf ("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) scanf ("%d", &b[i][j]);

	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			if (a[i][j] > b[i][j]) swap (a[i][j], b[i][j]);
			if (a[i][j] <= a[i-1][j] or a[i][j] <= a[i][j-1] or
				b[i][j] <= b[i-1][j] or b[i][j] <= b[i][j-1]) {
					printf ("Impossible\n");
					exit (0);
				}
		}
	printf ("Possible\n");

	return 0;
}
