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

vi shortest_path;
bool dijkstra(int n, int v_st, int v_en, vector<vpii> &adj) {
	vi dist(n+10, INF);
	set<pii> st;
	st.insert({0, v_st});
    dist[v_st] = 0;
    
	while(LEN(st)) {
		auto [w_path, v] = *st.begin();
		st.erase(st.begin());
		
		if(dist[v] != w_path) continue;

		for(auto [u, w_edge] : adj[v]) {
			if(dist[u] > w_path + w_edge) {
				dist[u] = w_path + w_edge;
				st.insert({dist[u], u});
			}
		}
	}

    for(int i = 0; i < LEN(shortest_path) - 1; i++)
    {
        int cnt = 0;
        for(auto [u, _] : adj[shortest_path[i]])
            if(dist[shortest_path[i + 1]] == dist[u]) cnt++;
        if(cnt > 1) return true;
    }
	
	return false;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m, k;
	cin >> n >> m >> k;

	vector<vpii> adj(n+10);

	for(int i = 0; i < k; i++) {
		int u;
		cin >> u;
		shortest_path.push_back(u);
	}

	while(m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	cout << (dijkstra(n, 1, n, adj) ? "yes" : "no") << '\n';

	return 0;
}
