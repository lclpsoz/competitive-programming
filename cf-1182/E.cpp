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
	ret[i][j] = (ret[i][j] + a[i][k] * 1LL * b[k][j])%(MOD-1); // Using mod and long long!!
	
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

int powMod (int base, ll p) {
	int ret = 1;
	while (p) {
		if (p&1) ret = (ret * 1LL * base) % MOD;
		base = (base * 1LL * base)%MOD;
		p >>= 1;
	}

	return ret;
}

ll n;
int f1, f2, f3, c;

int main () {
	scanf ("%lld", &n);
	scanf ("%d %d %d %d", &f1, &f2, &f3, &c);
	matrix base = initMatrix (3, 3), stF1 = {{1}, {1}, {2}};
	matrix baseC = {{0, 1, 0, 0, 0},
					{0, 0, 1, 0, 0},
					{1, 1, 1, 0, 1},
					{0, 0, 0, 1, 0},
					{0, 0, 0, 1, 1},	};
	matrix stF2 = {{1}, {2}, {3}};
	matrix stF3 = {{1}, {2}, {4}};
	matrix cc = {{0}, {0}, {2}, {2}, {4}}; // fn = f(n-1) + f(n-2) + f(n-3) + 2*(n-3)

	for (int i = 0; i<=1; i++) base[i][i+1] = 1;
	for (int i = 0; i < 3; i++) base[2][i] = 1;

	if (n > 5) {
		base = mat_powmod (base, n-4);
		baseC = mat_powmod (baseC, n-4);
	}
	// for (int i = 0; i < 3; i++)
	// 	for (int j = 0; j < 3; j++)
	// 		printf ("%d%c", base[i][j], " \n"[j==2]);
	// for (int i = 0; i < 5; i++)
	// 	for (int j = 0; j < 5; j++)
	// 		printf ("%d%c", baseC[i][j], " \n"[j==4]);
	stF1 = base*stF1;
	stF2 = base*stF2;
	stF3 = base*stF3;
	cc = baseC*cc;
	// for (int i = 0; i < 3; i++)
	// 	printf ("c = %d, F1 = %d, F2 = %d, F3 = %d\n", cc[i][0], stF1[i][0], stF2[i][0], stF3[i][0]);
	// for (int i = 3; i < 5; i++)
	// 	printf ("c = %d\n", cc[i][0]);

	ll ans = 1;
	ans = powMod (c, cc[2][0]);
	// printf ("%d\n", ans);
	// printf ("%d %d %d\n", powMod (f1, 2), powMod (f2, 3), powMod (f3, 4));
	ans = (ans * 1LL * powMod (f1, stF1[0][0]))%MOD;
	ans = (ans * 1LL * powMod (f2, stF2[0][0]))%MOD;
	ans = (ans * 1LL * powMod (f3, stF3[0][0]))%MOD;
	printf ("%lld\n", ans);
	
	return 0;
}
