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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<vi> adj(n+1), adj_inv(n+1);
		vi d(n+1, INF<int>);
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj_inv[v].push_back(u);
		}
		vpii bfs;
		bfs.push_back({1, 0});
		for (int i = 0; i < LEN(bfs); i++) {
			auto [v, dist] = bfs[i];
			if (d[v] != INF<int>) continue;
			d[v] = dist;
			for (int u : adj[v])
				if (d[u] == INF<int>)
					bfs.push_back({u, dist+1});
		}
		// cerr << "n = " << n << '\n';
		// cerr << "d: ";
		// for (int i = 1; i <= n; i++)
		// 	cerr << d[i] << " \n"[i==n];

		vector<vi> dp(n+1, vi(2, INF<int>));
		set<pair<int, pii>> dij;
		for (int i = 1; i <= n; i++)
			dij.insert({d[i], {i, 0}});
		while (LEN(dij)) {
			auto [dist, v_used] = *dij.begin();
			auto [v, used] = v_used;
			dij.erase(dij.begin());
			if (dp[v][used] != INF<int>) continue;
			dp[v][used] = dist;
			// cerr << "dist = " << dist << ", v = " << v << ", used = " << used << '\n';
			for (int to : adj_inv[v]) {
				if (d[to] < d[v]) {
					dij.insert({dist, {to, used}});
				}
				else if (!used) {
					dij.insert({dist, {to, 1}});
				}
			}
		}
		for (int i = 1; i <= n; i++)
			cout << min(dp[i][0], dp[i][1]) << " \n"[i==n];
	}

	return 0;
}
