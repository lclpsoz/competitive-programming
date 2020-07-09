#include "bits/stdc++.h"
using namespace std;

// -------------------------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int) (((x%m) + m)%m);
}

// ------

const int N = 105;

int n, k;
int mat[N][N];
set<int> col[N], lin[N];

void no () {
	printf ("no\n");
	exit (0);
}

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			scanf ("%d", &mat[i][j]);
			if (lin[i].count (mat[i][j]) == 1 or 
				col[j].count (mat[i][j]) == 1)
				no ();
			lin[i].insert (mat[i][j]);
			col[j].insert (mat[i][j]);
		}
	}
	
	for (int i = k; i < n; i++) {
		for (int j = 0; j < n; j++) {
			set<int> now;
			for (int v = 1; v <= n; v++)
				now.insert (v);
			for (int v : lin[i])
				now.erase (v);
			for (int v : col[j])
				now.erase (v);
			
			printf ("%d %d %d\n", i, j, len (now));
			assert (!now.empty());
			mat[i][j] = *now.begin();
			printf ("v = %d\n", mat[i][j]);
			lin[i].insert (mat[i][j]);
			col[j].insert (mat[i][j]);
		}
	}
	printf ("yes\n");
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf ("%d%c", mat[i][j], " \n"[j==(n-1)]);

	return 0;
}