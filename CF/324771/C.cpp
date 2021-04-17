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
const T INF = (is_same<T, int>::value ? 1e9+1 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;

int n, m;

bool dijkstra (int maxi, vector<vpii> &adj) {
	// cerr << "maxi = " << maxi << '\n';
	set<pair<pair<int, bool>, int>> st;  // {{max_edge, used first or not}, vertex}
	vector<vi> dist(n+1, vi(2, INF<int>));
	st.insert({{0, false}, 1});
	dist[1][false] = 0;
	vector<vector<bool>> vis(N, vector<bool>(2));
	while (!st.empty()) {
		auto [info, v] = *st.begin();
		auto [d, used] = info;
		st.erase(st.begin());
		if (vis[v][used]) continue;
		vis[v][used] = 1;
		// cerr << "  v = " << v << ", d = " << d << ", used = " << used << '\n';
		for (auto [u, w] : adj[v]) {
			if (w < maxi or (w == maxi and used)) {
				int mx = max(w, d);
				if (mx < dist[u][used]) {
					dist[u][used] = mx;
					st.insert({{dist[u][used], used}, u});
				}
			}
			else if (!used) {
				if (d < dist[u][true]) {
					dist[u][true] = d;
					st.insert({{d, true}, u});
				}
				if (w == maxi) {
					int mx = max(w, d);
					if (mx < dist[u][used]) {
						dist[u][used] = mx;
						st.insert({{dist[u][used], used}, u});
					}
				}
			}
		}
	}

	return dist[n][true] != INF<int>;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> m;
	if (n == 1)
		cout << "0\n";
	else {
		vector<vpii> adj(n+1);
		vi values;
		while (m--) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
			values.push_back(w);
		}
		values.push_back(0);
		sort(ALL(values));
		values.resize(unique(ALL(values)) - values.begin());

		int l = 0, r = LEN(values)-1;
		while (l < r) {
			int md = (l+r)/2;
			if (dijkstra(values[md], adj))
				r = md;
			else
				l = md+1;
		}
		// cerr << "l = " << l << '\n';

		if (!dijkstra(values[l], adj))
			cout << "-1\n";
		else
			cout << values[l] << '\n';
	}

	return 0;
}
