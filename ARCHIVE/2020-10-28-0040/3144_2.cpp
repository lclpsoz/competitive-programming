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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////



int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	int n, m;
	int start;

	cin >> n >> m;
	cin >> start;
	vector<vpii> adj(n+10);
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	set<pii> dij;
	int INF = 1E9;
	vi dist(n+10, INF), edge_used(n+10);

	dij.insert({0, start});
	dist[start] = 0;
	while(LEN(dij)) {
		auto [w, v] = *dij.begin();
		// cout << w << ' ' << v << '\n';
		dij.erase(dij.begin());
		if(dist[v] != w) continue;
		for(auto [u, w_edge] : adj[v]) {
			if(dist[v]+w_edge < dist[u]) {
				dist[u] = dist[v]+w_edge;
				edge_used[u] = w_edge;
				dij.insert({dist[u], u});
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans += edge_used[i]*2;
	cout << ans << '\n';

	return 0;
}
