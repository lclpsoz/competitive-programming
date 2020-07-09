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

int n;
vector<int> ans[110];

int main () {
	scanf ("%d", &n);
	int n2 = n*n;
	for (int i = 1, j = n2; i <= n2/2; i++, j--) {
		ans[(i-1)/(n/2)].push_back (i);
		ans[(i-1)/(n/2)].push_back (j);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < len (ans[i]); j++) {
			if (j) putchar (' ');
			printf ("%d", ans[i][j]);
		}
		putchar ('\n');
	}

	return 0;
}
