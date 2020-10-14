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

const int INF = 1e9;

// map<pii, int> mp;

bool dijkstra(int n, int v_st, int v_en, vector<vpii> &adj, set<pii> &used) {
	vi dist(n+10, INF), dist_en(n+10, INF);
	set<pii> st;
	st.insert({0, v_st});
	dist[v_st] = 0;
	while(LEN(st)) {
		auto [w_path, v] = *st.begin();
		// cout << "v = " << v << '\n';
		st.erase(st.begin());
		if(dist[v] != w_path) continue;
		for(auto [u, w_edge] : adj[v]) {
			// cout << "  u = " << u << ", cost = " << w_path + w_edge << '\n';
			if(dist[v]+w_edge < dist[u]) {
				dist[u] = dist[v]+w_edge;
				st.insert({dist[u], u});
			}
		}
	}
	st.insert({0, v_en});
	dist_en[v_en] = 0;
	while(LEN(st)) {
		auto [w_path, v] = *st.begin();
		st.erase(st.begin());
		if(dist_en[v] != w_path) continue;
		for(auto [u, w_edge] : adj[v])
			// cout << "  u = " << u << ", cost = " << w_path + w_edge << '\n';
			if(dist_en[v]+w_edge < dist_en[u]) {
				dist_en[u] = dist_en[v]+w_edge;
				st.insert({dist_en[u], u});
			}
	}


	// for(int v = 1; v <= n; v++)
	// 	cout << "v = " << v << ", dist = " << dist[v] << ", dist_en = " << dist_en[v] << '\n';

	for(int v = 1; v <= n; v++)
		for(auto [u, w] : adj[v])
			if(dist[v]+dist_en[u]+w == dist[v_en] and used.count({v, u}) == 0)
				return true;

	return false;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m, k;

	cin >> n >> m >> k;
	vector<vpii> adj(n+10);
	set<pii> used;
	map<pii, int> mp_min;

	int bef = -1;
	for(int i = 0; i < k; i++) {
		int u;
		cin >> u;
		if(bef != -1) {
			used.insert({bef, u});
			used.insert({u, bef});
		}
		bef = u;
	}

	vector<pair<pii, int>> edges;
	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		if(u > v) swap(u, v);
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});

		if(used.count({u, v})) {
			edges.push_back({{u, v}, w});
			if(mp_min.count({u, v}) == 0)
				mp_min[{u, v}] = w;
			else
				mp_min[{u, v}] = min(w, mp_min[{u, v}]);
		}
	}
	for(auto [edge, w] : edges)
		if(abs(mp_min[edge]) == w) {
			if(mp_min[edge] > 0)
				mp_min[edge] = -mp_min[edge];
			else {
				cout << "yes\n";
				exit(0);
			}
		}

	cout << (dijkstra(n, 1, n, adj, used) ? "yes" : "no") << '\n';

	return 0;
}
