#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int n, m;
vpii adj[1010];

vi dijkstra(int st) {
	vi dist(n+10, INF<int>);
	set<pii> dij;
	dij.insert({0, st});
	dist[st] = 0;
	while(LEN(dij)) {
		int d = dij.begin()->x;
		int v = dij.begin()->y;
		dij.erase(dij.begin());
		if(dist[v] != d) continue;
		for(pii p : adj[v]) {
			int u = p.x, w = p.y;
			if(dist[v]+w < dist[u]) {
				dist[u] = dist[v]+w;
				dij.insert({dist[u], u});
			}
		}
	}

	return dist;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int k;
	vpii edges;

	cin >> n >> m >> k;
	vector<vi> dists(n+10);
	for(int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back({u, v});
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	for(int i = 1; i <= n; i++)
		dists[i] = dijkstra(i);

	int ans = 0;
	vpii couriers;
	while(k--) {
		int st, en;
		cin >> st >> en;
		couriers.push_back({st, en});
		ans += dists[st][en];
	}
	for(pii e : edges) {
		int now = 0;
		for(pii cr : couriers) {
			int st = cr.x, en = cr.y;
			now += min(dists[st][en],
				min(	dists[st][e.x] + dists[e.y][en],
						dists[st][e.y] + dists[e.x][en]));
		}
		ans = min(now, ans);
	}
	cout << ans << '\n';

	return 0;
}
