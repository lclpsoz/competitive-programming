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

const int N = 2e5 + 10;

int n, m, k;
set<pair<ll, pair<pii, pii>>> st;
map<int, set<int>> vis;
vector<pii> adj[N];

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		st.insert ({w, {{u, u}, {v, v}}});
		adj[u].push_back ({w, v});
		adj[v].push_back ({w, u});
	}
	while (!st.empty() and k > 1) {
		ll w = st.begin()->x;
		int u, v;
		u = st.begin()->y.x.x;
		v = st.begin()->y.y.x;
		st.erase (st.begin());
		if (u == v) continue;
		if (u > v) swap (u, v);
		if (vis.count(u) and vis[u].count (v)) continue;
		vis[u].insert (v);
		// printf ("%d %d %lld\n", u, v, w);
		for (auto p : adj[u])
			st.insert ({w+p.x, {v, p.y}});
		for (auto p : adj[v])
			st.insert ({w+p.x, {u, p.y}});
		--k;
	}
	printf ("%lld\n", st.begin()->x);

	return 0;
}
