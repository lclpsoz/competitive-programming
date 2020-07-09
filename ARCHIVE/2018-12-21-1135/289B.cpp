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

const int N = 105;

int n, m, d;
int mat[N][N];
int ax = -1;

int main () {
	scanf ("%d %d %d", &n, &m, &d);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf ("%d", &mat[i][j]);
			if (ax == -1)
				ax = mat[i][j]%d;
			else if (mat[i][j]%d != ax) {
				printf ("-1\n");
				return 0;
			}
			mat[i][j] /= d;
		}
	int ans = 2e9;
	for (int val = 0; val <= 10000; val++) {
		ax = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				ax += abs (val-mat[i][j]);
// 		printf ("%d: %d\n", val, ax);
		ans = min (ans, ax);
	}
	
	printf ("%d\n", ans);

	return 0;
}
