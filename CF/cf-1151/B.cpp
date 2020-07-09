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

const int N = 505;

int n, m;
int mat[N][N];
set<int> st[N];

int main () {
	scanf ("%d %d", &n, &m);
	bool any2 = false;
	int linha = -1;
	int col = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			scanf ("%d", &mat[i][j]);
			if (!any2) {
				st[i].insert (mat[i][j]);
				if (len (st[i]) > 1) {
					any2 = true;
					linha = i;
					col = j;
				}
			}
		}
		
	if (!any2) {
		int val = 0;
		for (int i = 1; i <= n; i++)
			val ^= mat[i][1];
		if (val == 0)
			printf ("NIE\n");
		else {
			printf ("TAK\n");
			for (int i = 1; i <= n; i++)
				printf ("1 ");
			putchar ('\n');
		}
	} else {
		int val = 0;
		for (int i = 1; i <= n; i++)
			val ^= mat[i][1];
		if (val != 0) {
			printf ("TAK\n");
			for (int i = 1; i <= n; i++)
				printf ("1 ");
			putchar ('\n');
		} else {
			printf ("TAK\n");
			for (int i = 1; i <= n; i++)
				if (i == linha)
					printf ("%d ", col);
				else
					printf ("1 ");
			putchar ('\n');
		}
	}
	

	return 0;
}
