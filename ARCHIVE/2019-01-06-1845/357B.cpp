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

int n, m;
int ans[N];
int dance[N][3];

void solve (int p) {
	if (p == m) {
		for (int i = 1; i <= n; i++) {
			if (i > 1) putchar (' ');
			printf ("%d", ans[i]);
		}
		exit (0);
	}
	
	int *now = dance[p];
	int col[3] = {1, 2, 3};
	do {
		bool test = true;
		for (int i = 0; i < 3; i++)
			if (ans[now[i]] != 0 and ans[now[i]] != col[i]) {
				test = false;
				break;
			}
			
		if (test) {
			for (int i = 0; i < 3; i++)
				ans[now[i]] = col[i];
			solve (p+1);
		}
	} while (next_permutation (col, col+3));
	
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 3; j++)
			scanf ("%d", &dance[i][j]);
		
	solve (0);

	return 0;
}
