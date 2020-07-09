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
int ans;
int mat[105][105];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf ("%d", &mat[i][j]);
		
	for (int i = 0; i < n; i++) {
		int acu = 0;
		for (int j = 0; j <  m; j++)
			acu += mat[i][j];
		ans = max(acu, ans);
	}
	for (int i = 0; i < m; i++) {
		int acu = 0;
		for (int j = 0; j < n; j++)
			acu += mat[j][i];
		ans = max(acu, ans);
	}
	
	printf ("%d\n", ans);

	return 0;
}
