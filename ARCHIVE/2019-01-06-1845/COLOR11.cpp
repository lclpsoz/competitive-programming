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

const int N = 210;

int n, m;
int k;
pii st;
bool mat[N][N];

int solve (int x, int y) {
	mat[x][y] = true;
	int r = 1;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (!mat[x+i][y+j])
				r += solve (x+i, y+j);
	
	return r;		
}

int main () {
	scanf ("%d %d %d %d %d", &n, &m, &st.x, &st.y, &k);
	for (int i = 0; i <= n+1; i++)
		mat[i][0] = mat[i][m+1] = true;
	for (int i = 0; i <= m+1; i++)
		mat[0][i] = mat[n+1][i] = true;
	
// 	for (int i = 0; i <= n+1; i++) {
// 		for (int j = 0; j <= m+1; j++)
// 			printf ("%d ", mat[i][j]);
// 		putchar ('\n');
// 	}
	while (k--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		mat[x][y] = true;
	}
	printf ("%d\n", solve (st.x, st.y));

	return 0;
}
