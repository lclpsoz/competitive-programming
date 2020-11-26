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
int a[505][505], b[505][505];


int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf ("%d", &b[i][j]);
			b[i][j] ^= a[i][j];
		}
	for (int i = 0; i < n-1; i++)
		for (int j = 0; j < m-1; j++) {
			if (b[i][j] == 1) {
				for (int k = 0; k <= 1; k++)
					for (int l = 0; l <= 1; l++)
						b[i+k][j+l] ^= 1;
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (b[i][j]) {
				printf ("No\n");
				exit (0);
			}
	printf ("Yes\n");
	


	return 0;
}
