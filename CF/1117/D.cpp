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
	ret[i][j] = (ret[i][j] + a[i][k] * 1LL * b[k][j])%MOD; // Using mod and long long!!
	
	return ret;
}

void operator*= (matrix &a, matrix &b) {
	a = a*b;
}

matrix mat_powmod (matrix &a, ll p) {
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

int main () {
	// matrix m = {{0, 1, 0}, {0, 0, 1}, {1, 1, 1}};
	// for (int i = 0; i < 3; i++)
	// 	for (int j = 0; j < 3; j++)
	// 		printf ("%2d%c", m[i][j], " \n"[j==2]);
	// matrix m2 = m*m;
	// for (int i = 0; i < 3; i++)
	// 	for (int j = 0; j < 3; j++)
	// 		printf ("%2d%c", m2[i][j], " \n"[j==2]);
	// m2 *= m2;
	// for (int i = 0; i < 3; i++)
	// 	for (int j = 0; j < 3; j++)
	// 		printf ("%2d%c", m2[i][j], " \n"[j==2]);
	// m2 *= m2;
	// for (int i = 0; i < 3; i++)
	// 	for (int j = 0; j < 3; j++)
	// 		printf ("%2d%c", m2[i][j], " \n"[j==2]);
	ll n;
	int m;
	scanf ("%lld %d", &n, &m);
	matrix mt = initMatrix (m, m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			if (i+1 == j)
				mt[i][j] = 1;
	mt[m-1][0] = mt[m-1][m-1] = 1;
	// for (int i = 0; i < m; i++)
	// 	for (int j = 0; j < m; j++)
	// 		printf ("%2d%c", mt[i][j], " \n"[j==m-1]);
	// printf ("_____\n");
	mt = mat_powmod (mt, n);
	// for (int i = 0; i < m; i++)
	// 	for (int j = 0; j < m; j++)
	// 		printf ("%2d%c", mt[i][j], " \n"[j==m-1]);
	printf ("%d\n", mt[m-1][m-1]);
	return 0;
}
