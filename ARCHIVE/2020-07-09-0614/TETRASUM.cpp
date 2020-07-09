#include <bits/stdc++.h>
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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(x%m);
}

////////////////////////// Solution starts below. //////////////////////////////

using row = vector<int>; // Values are int!!
using matrix = vector<row>;

matrix initMatrix (int nRow, int nCol) {
	matrix ret (nRow, row(nCol));

	return ret;
}

matrix operator* (matrix &a, matrix &b) {
	assert (len (a) && len (a[0]) == len (b)); // check if (Ma(a x n), Mb(n x b)) holds
	int nRow = len (b);
	int nCol = min (len(a), len(b[0]));
	matrix ret = initMatrix (nRow, nCol);
	for (int i = 0; i < nRow; i++)
		for (int j = 0; j < nCol; j++)
			for (int k = 0; k < nRow; k++)
	ret[i][j] =  (ret[i][j] + a[i][k] * 1LL * b[k][j])%MOD; // Using mod and long long!!
	
	return ret;
}

void operator*= (matrix &a, matrix &b) {
	a = a*b;
}

matrix mat_powmod (matrix &a, int p) {
	matrix ret = initMatrix (len(a), len(a[0]));
	for (int i = 0; i < min (len (a), len(a[0])); i++)
		ret[i][i] = 1;

	while (p) {
		if (p&1)
			ret = ret * a;
		p >>= 1;
		a = a*a;
	}

	return ret;
}

int solve (int x) {
	if (x == -1) return 0;
	matrix m = initMatrix (5, 5);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (i+1 == j or i == 3) m[i][j] = 1;
	m[3][4] = m[4][4] = 1;
	m = mat_powmod (m, x);
	// for (int i = 0; i < 4; i++)
	// 	for (int j = 0; j < 4; j++)
	// 		printf ("%3d%c", m[i][j], "\t\n"[j==3]);
	// putchar ('\n');
	// putchar ('\n');
	matrix v = {{0}, {0}, {0}, {1}, {1}};
	v = m*v;
	// for (int i = 0; i < 4; i++)
	// 	for (int j = 0; j < 1; j++)
	// 		printf ("%3d%c", v[i][j], "\t\n"[j==0]);
	// putchar ('\n');

	return v[0][0];
}

int main () {
	int t;
	scanf ("%d", &t);
	while (t--) {
		int l, r;
		scanf ("%d %d", &l, &r);
		printf ("%lld\n", (solve (r) - (ll)solve (l-1) + MOD)%MOD);
	}
	
	return 0;
}
