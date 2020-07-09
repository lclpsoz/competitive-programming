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

const int N = 5e4+100, K = 18;

int n, m;
int mat[N][K], ans;

void buildSparse () {
	for (int i = 1; (1<<i) <= n; i++)
		for (int j = 0; j <= n-(1<<(i-1)); j++)
			mat[j][i] = max (mat[j][i-1], mat[j+(1<<(i-1))][i-1]);
}

int query (int l, int r, int val) {
	if (l > r) swap (l, r);
	if (r-l+1 <= 2) return true;
	l++; r--;
	int k = 31 - __builtin_clz (r-l+1);
	return max (mat[l][k], mat[r+1-(1<<k)][k]) <= val;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf ("%d", &mat[i][0]);
	buildSparse ();
	while (m--) {
		int a, b;
		scanf ("%d %d", &a, &b);
		ans += query (a-1, b-1, mat[a-1][0]);
	}
	
	printf ("%d\n", ans);

	return 0;
}
