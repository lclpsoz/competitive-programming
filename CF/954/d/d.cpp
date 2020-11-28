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

vi bfs(int n, int st, vector<vi> &adj) {
	vi dist(n+1, INF<int>);
	queue<pii> q;
	q.push({st, 0});
	while(!q.empty()) {
		auto [v, d] = q.front();
		q.pop();
		if(dist[v] != INF<int>) continue;
		dist[v] = d;
		for(int u : adj[v])
			q.push({u, d+1});
	}

	return dist;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m, s, t;
	cin >> n >> m >> s >> t;
	vector<vi> adj(n+1);
	set<pii> roads;
	for(int i = 1; i <= n; i++)
		for(int j = i+1; j <= n; j++)
			roads.insert({i, j});

	while(m--) {
		int u, v;
		cin >> u >> v;
		if(u > v) swap(u,v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		roads.erase({u, v});
	}

	vi dist_s = bfs(n, s, adj);
	vi dist_t = bfs(n, t, adj);
	// for(int i = 1; i <= n; i++)
	// 	cerr << i << ": " << dist_s[i] << ' ' << dist_t[i] << '\n';
	int min_dist = dist_s[t];
	assert(dist_t[s] == min_dist);
	int ans = 0;
	for(auto &[u, v] : roads) {
		int cur_dist = min((dist_s[u] + dist_t[v]+1),
							(dist_s[v] + dist_t[u]+1));
		if(cur_dist >= min_dist) {
			++ans;
			// cerr << u << ' ' << v << '\n';
		}
	}
	cout << ans << '\n';

	return 0;
}
