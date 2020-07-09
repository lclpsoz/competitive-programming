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
	return (int)(((x%m) + m)%m);
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

int main () {
	char s[5];
	int t;
	scanf ("%d", &t);
	while (t--) {
		int c, n, q;
		scanf ("%d %d %d", &c, &n, &q);

		matrix m = initMatrix (n, n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				m[i][j] = 1;
		while (q--) {
			scanf (" %s", s);
			if (s[1]-'a' < n and s[0]-'a' < n)
				m[s[1]-'a'][s[0]-'a'] = 0;
		}
		if (c == 1) {
			printf ("%d\n", n);
			continue;
		}
		m = mat_powmod (m, c-1);
		// for (int i = 0; i < n; i++)
		// 	for (int j = 0; j < n; j++)
		// 		printf ("%d%c", m[i][j], " \n"[j==n-1]);
		matrix m1 = initMatrix (n, 1);
		for (int i = 0; i < n; i++)
			m1[i][0] = 1;
		m1 = m*m1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = (ans + m1[i][0])%MOD;
			// printf ("m1[%d][0] = %d\n", i, m1[i][0]);
		}
		printf ("%d\n", ans);
	}
	
	return 0;
}
