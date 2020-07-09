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

const int N = 90010;

int n, m, k;
vector<pii> ans[N];

void solve (int x, int y, int qnt, int id, char dir) {
	if (y == m+1) {
		++x;
		y = m;
		dir = 'L';
	} else if (y == 0) {
		++x;
		y = 1;
		dir = 'R';
	}
	if (x == n+1) return;
	
	if (qnt == 1)
		ans[id].emplace_back (x, y);
	else {
		if (len (ans[id]) == 1) {
			ans[id].emplace_back (x, y);
			++id;
			--qnt;
		} else
			ans[id].emplace_back (x, y);
	}
	if (dir == 'R')
		solve (x, y+1, qnt, id, dir);
	else
		solve (x, y-1, qnt, id, dir);
}

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	
	solve (1, 1, k, 1, 'R');
	for (int i = 1; i <= k; i++) {
		printf ("%d", len (ans[i]));
		for (pii p : ans[i])
			printf (" %d %d", p.x, p.y);
		putchar ('\n');
	}

	return 0;
}
