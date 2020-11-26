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

int n, m, k;
vector<pii> adj[N];
vector<int> sp;
int dist[N];

int dijkstra (int start) {
	for (int i = 1; i <= n; i++)
		dist[i] = -1;
	set<pii> st;
	st.insert ({0, start});
	dist[start] = 0;
	while (!st.empty()) {
		int w = st.begin()->x, v = st.begin()->y;
		st.erase (st.begin());
		if (dist[v] < w) continue;
		for (pii p : adj[v]) {
			int u = p.x, wE = p.y;
			if (dist[u] == -1 or dist[u] > max (w, wE)) {
				dist[u] = max (w, wE);
				st.insert ({dist[u], u});
			}
		}
	}
	
	int ret = -1;
	for (int v : sp)
		ret = max (ret, dist[v]);
	
	return ret;
}

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int x;
		scanf ("%d", &x);
		sp.push_back (x);
	}
	
	while (m--) {
		int u, v, w;
		scanf ("%d %d %d", &u, &v, &w);
		adj[u].push_back ({v, w});
		adj[v].push_back ({u, w});
	}
	
	int ans = dijkstra (sp[0]);
	for (int i = 0; i < k; i++)
		printf ("%d%c", ans, " \n"[i==k-1]);

	return 0;
}
