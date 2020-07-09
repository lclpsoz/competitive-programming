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

const int N = 1e5+10;

int m, n;
ld ans;
ld mat[20][N];

int main () {
	scanf ("%d %d", &m, &n);
	int p = 0;
	for (int i = 1; i <= m; i++)
		mat[p][i-1] = (ld)i*(powl ((ld)i/m, n) - powl ((ld)(i-1)/m, n));
	
	while (m > 1) {
		m = (m+1)/2; ++p;
		for (int i = 0; i < m; i++)
			mat[p][i] = mat[p-1][2*i] + mat[p-1][2*i+1];
	}
	
	printf ("%.12Lf\n", mat[p][0]);
	
	return 0;
}
