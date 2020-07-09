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
int mat[105][105];

int sumSq (int x, int y, int a, int b) {
	return mat[a][b] - mat[a][y-1] - mat[x-1][b] + mat[x-1][y-1];
}

int solveN4 () {
	int ret = - 1e9;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= i; k++)
				for (int l = 1; l <= j; l++)
					ret = max (ret, sumSq (k, l, i, j));
		}
		
	return ret;
}

int lin (int x, int y, int h) {
	return mat[h][y] - mat[h-1][y] - mat[h][x-1] + mat[h-1][x-1];;
}

int solveN3 () {
	int ret = - 1e9;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			int acu = - 1e9;
			for (int k = 1; k <= n; k++) {
				int ax = lin (i, j, k);
				acu = max (acu + ax, ax);
				ret = max (ret, acu);
			}
		}
		
	return ret;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf ("%d", &mat[i][j]);
			mat[i][j] += (mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1]);
		}
		
	printf ("%d\n", solveN3 ());
		
	return 0;
}
