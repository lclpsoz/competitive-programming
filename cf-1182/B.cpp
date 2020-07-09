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
char mat[501][501];

int main () {
	scanf ("%d %d", &n, &m);
	int qnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf (" %c", &mat[i][j]);
			qnt += mat[i][j] == '*';
		}
	if (!qnt) {
		printf ("NO\n");
		exit (0);
	}

	bool tried = false;
	for (int i = 1; i < n-1 and !tried; i++)
		for (int j = 1 ; j < m-1; j++) {
			// printf ("%d %d : %c\n", i, j, mat[i][j]);
			if (mat[i][j] == '*' and
				mat[i+1][j] == '*' and
				mat[i-1][j] == '*' and
				mat[i][j+1] == '*' and
				mat[i][j-1] == '*') {
					tried = true;
					--qnt;
					for (int k = i+1; k < n and mat[k][j] == '*'; k++)
						--qnt;
					for (int k = i-1; k >= 0 and mat[k][j] == '*'; k--)
						--qnt;
					for (int k = j+1; k < m and mat[i][k] == '*'; k++)
						--qnt;
					for (int k = j-1; k >= 0 and mat[i][k] == '*'; k--)
						--qnt;
				break;
			}
		}
	printf ("%s\n", qnt == 0 ? "YES" : "NO");

	return 0;
}
