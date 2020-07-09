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

int n, m, h;
int col[110], row[110], top[110][110];
int ans[110][110];

int main () {
	scanf ("%d %d %d", &n, &m, &h);
	for (int i = 0; i < m; i++)
		scanf ("%d", &col[i]);
	for (int i = 0; i < n; i++)
		scanf ("%d", &row[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf ("%d", &top[i][j]);
			if (top[i][j]) {
				ans[i][j] = min (row[i], col[j]);
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf ("%d%c", ans[i][j], " \n"[j==m-1]);




	return 0;
}
