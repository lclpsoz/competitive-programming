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

const int INF = 1e9;

int a, b;
map<int, int> mpA;
queue<pii> q;
set<int> vis;

int main () {
	scanf ("%d %d", &a, &b);
	
	q.push ({a, 0});
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		if (vis.count (p.x)) continue;
		vis.insert (p.x);
		mpA[p.x] = p.y;
		for (int i = 2; i <= 5; i++)
			if ((i == 2 or i == 3 or i == 5) and p.x%i == 0)
				q.push ({p.x / i, p.y+1});
	}
	
	int ans = INF;
	q.push ({b, 0});
	vis.clear();
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		if (vis.count (p.x)) continue;
		vis.insert (p.x);
		if (mpA.count (p.x) == 1)
			ans = min (ans, p.y + mpA[p.x]);
		for (int i = 2; i <= 5; i++)
			if ((i == 2 or i == 3 or i == 5) and p.x%i == 0)
				q.push ({p.x / i, p.y+1});
	}
	
	if (ans == INF)
		printf ("-1\n");
	else
		printf ("%d\n", ans);

	return 0;
}
