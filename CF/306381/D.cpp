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

const int N = 2e3 + 10;

int n, m, q;
vi adj[N];
vi cities_path[N];

vi get_dist (int v_start) {
	vi dist(N, INF<int>);
	vpii bfs;
	bfs.push_back({v_start, 0});
	for (int i = 0; i < LEN(bfs); i++) {
		int v = bfs[i].x;
		int d = bfs[i].y;
		// cerr << "v = " << v << '\n';
		if (dist[v] != INF<int>)
			continue;
		dist[v] = d;
		for (int u : adj[v])
			bfs.push_back({u, d+1});
		// cerr << "LEN(bfs) = " << LEN(bfs) << '\n';
	}
	bfs.clear();
	return dist;
}

int main () {
	freopen("ysys.in", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> m >> q;

	while (m--) {
		int u, v;
		cin >> u >> v;
		// cout << "u, v = " << u << ", " << v << '\n';
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vpii bombs;
	for (int i = 0; i < q; i++) {
		int d, c;
		cin >> d >> c;
		bombs.push_back({d, c});
	}
	sort(ALL(bombs));

	vpii paths;
	vi paths_cost;
	for (int i = 0; i < q-1; i++) {
		int v = bombs[i].y;
		int u = bombs[i+1].y;
		paths.push_back({v, u});
		cities_path[v].push_back(i);
		paths_cost.push_back(INF<int>);
	}

	int travel_time = 0;
	for (int v = 1; v <= n; v++)
		if (LEN(cities_path[v])) {
			vi dist = get_dist(v);
			for (int p : cities_path[v]) {
				int u = paths[p].y;
				paths_cost[p] = dist[u];
			}
		}

	// int d_max = min(bombs.front().x, bombs.back().x-travel_time);
	int d_max = bombs.front().x;
	for (int i = 0; i < q-1; i++) {
		if (i)
			paths_cost[i] += paths_cost[i-1];
		d_max = min(d_max, bombs[i+1].x-paths_cost[i]);
		// cerr << i << ": cost = " << paths_cost[i] << ", d_max = " << d_max << '\n';
	}
	
	assert(d_max >= 0);
	vi dist_start = get_dist(bombs.front().y);
	int ans = 0;
	// cerr << "d_max = " << d_max << '\n';
	for (int i = 1; i <= n; i++)
		ans += dist_start[i] <= d_max;
	cout << ans << '\n';


	return 0;
}
