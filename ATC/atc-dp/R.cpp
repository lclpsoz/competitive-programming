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

const int MOD = 1e9+7;
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
	ret[i][j] = mod (ret[i][j] + a[i][k] * 1LL * b[k][j]); // Using mod and long long!!
	
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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
	
	int n;
	ll k;
	cin >> n >> k;
	matrix mat = initMatrix(n, n);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> mat[i][j];
	
	// for(int i = 0; i < n; i++)
	// 	for(int j = 0; j < n; j++)
	// 		cout << mat[i][j] << " \n"[j==n-1];
	matrix ax = mat_powmod(mat, k);
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++) {
			// cout << ax[i][j] << " \n"[j==n-1];
			ans = (ans+ax[i][j])%MOD;
		}
	cout << ans << '\n';


	return 0;
}
