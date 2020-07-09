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

using pp = pair<int, pii>;

const int N = 1e3+100;

int n;
int vis[N], ans[N];
vector<pii> adj[N];
priority_queue<pp> pq;

int main () {
	scanf ("%d", &n);
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			int w;
			scanf ("%d", &w);
			adj[i].push_back ({w, j});
			adj[j].push_back ({w, i});
		}
	}
	
	vis[1] = true;
	for (pii p : adj[1])
		pq.push ({p.x, {p.y, 1}});
	
	int acu = 0;
	while (!pq.empty()) {
		int w = pq.top().x;
		int v = pq.top().y.x;
		int pr = pq.top().y.y;
		pq.pop();
		if (vis[v]) continue;
		vis[v] = true;
		ans[v] = pr;
		acu += w;
		for (pii p : adj[v])
			pq.push ({p.x, {p.y, v}});
	}
	
	printf ("%d\n", acu);
	for (int i = 2; i <= n; i++)
		printf ("%d\n", ans[i]);

	return 0;
}
