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
char mat[60][60];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf (" %c", &mat[i][j]);

	
	for (int i = 1; i < n-1; i++)
		for (int j = 1; j < n-1; j++)
			if (mat[i][j] == '.' and
				mat[i-1][j] == '.' and
				mat[i+1][j] == '.' and
				mat[i][j-1] == '.' and
				mat[i][j+1] == '.')
				mat[i][j] = mat[i-1][j] =  mat[i+1][j] =  mat[i][j-1] =  mat[i][j+1] = '!';

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (mat[i][j] == '.') {
				printf ("NO\n");
				exit (0);
			}
	printf ("YES\n");
	

	return 0;
}
