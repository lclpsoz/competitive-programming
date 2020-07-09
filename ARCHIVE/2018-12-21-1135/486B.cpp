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

int n, m;
int mat[N][N], a[N][N], b[N][N];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf ("%d", &mat[i][j]);
			a[i][j] = 1;
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mat[i][j] == 0) {
				for (int k = 0; k < n; k++)
					a[k][j] = 0;
				for (int k = 0; k < m; k++)
					a[i][k] = 0;
			}
			
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j]) {
				for (int k = 0; k < n; k++)
					b[k][j] = 1;
				for (int k = 0; k < m; k++)
					b[i][k] = 1;
			}
			
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (mat[i][j] != b[i][j]) {
				printf ("NO\n");
				return 0;
			}
			
	printf ("YES\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (j)
				putchar (' ');
			printf ("%d", a[i][j]);
		}
		putchar ('\n');
	}

	return 0;
}
