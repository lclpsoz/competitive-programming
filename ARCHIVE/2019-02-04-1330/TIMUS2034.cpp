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
int s, f, r;
vector<int> adj[N];
int distS[N], distF[N], distR[N];
bool vis[N];

void bfs (int st, int *dist) {
	queue<pii> q;
	memset (vis, 0, sizeof vis);
	q.push ({0, st});
	while (!q.empty()) {
		int d = q.front().x, v = q.front().y;
		q.pop();
		if (vis[v]) continue;
		vis[v] = true;
		dist[v] = d;
		for (int u : adj[v])
			if (!vis[u])
				q.push ({d+1, u});
	}
}

int main () {
	scanf ("%d %d", &n, &m);
	while (m--) {
		int a, b;
		scanf ("%d %d", &a, &b);
		adj[a].push_back (b);
		adj[b].push_back (a);
	}
	
	scanf ("%d %d %d", &s, &f, &r);
	bfs (s, distS);
	bfs (f, distF);
	bfs (r, distR);
	
	memset (vis, false, sizeof vis);
	int mnSF = distS[f];
	if (distS[f] != distF[s])
		assert (false);
	for (int i = 1; i <= n; i++) {
		if (distS[i] + distF[i] > mnSF)
			vis[i] = true;
		else if (distS[i] + distF[i] < mnSF)
			assert (false);
	}
	int ans = -1;
	queue<pair<int, pii>> q;
	q.push ({0, {distR[s], s}});
	while (!q.empty()) {
		int d = q.front().x, v = q.front().y.y, minD = q.front().y.x;
		q.pop();
		if (v == f) {
			ans = max (ans, minD);
			continue;
		}
		if (vis[v]) continue;
		for (int u : adj[v])
			if (distF[u]+d+1 == mnSF)
				q.push ({d+1, {min (minD, distR[u]), u}});
	}
	printf ("%d\n", ans);

	return 0;
}
