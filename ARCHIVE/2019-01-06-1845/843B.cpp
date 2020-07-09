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

const int INF = 2e9;
const int N = 5e4+100;

int n, st, x;
bool vis[N];
int ans = INF;

pii qry (int v) {
	printf ("? %d\n", v);
	fflush (stdout);
	pii p;
	scanf ("%d %d", &p.x, &p.y);
	if (p.x == p.y and p.x == -1)
		exit (0);
	return p;
}

int main () {
	mt19937 rng((llu)chrono::steady_clock::now().time_since_epoch().count());
	
	scanf ("%d %d %d", &n, &st, &x);
	uniform_int_distribution<> dist (1, n);
	if (n > 1999) {
		pii acu = qry (st), now;
		vis[st] = true;
		for (int i = 1; i < 999; ++i) {
			int val = dist (rng);
			while (vis[val]) val = dist (rng);
			vis[val] = true;
			now = qry (val);
			if (now.x <= x and now.x > acu.x)
				acu = now;
		}
		
		now = acu;
		while (now.x < x and now.y != -1)
			now = qry (now.y);
		if (now.x >= x)
			ans = now.x;
	} else {
		for (int i = 1; i <= n; i++) {
			int val = qry (i).x;
			if (val >= x and val < ans)
				ans = val;
		}
	}
	
	
	if (ans == INF)
		ans = -1;
	printf("! %d\n", ans);
	fflush (stdout);

	return 0;
}
