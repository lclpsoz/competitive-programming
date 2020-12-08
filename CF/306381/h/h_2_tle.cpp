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

const int N = 2e5 + 10;

int n, m;
ll vals[N];
vpii adj[N];
bitset<N> vis;

void dijkstra () {
	set<pair<ll, int>> dij;
	vi vis_vals;
	for (int st_v = 1; st_v <= n; st_v++) {
		dij.clear();
		// cerr << "st_v = " << st_v << '\n';
		for (auto [u, w] : adj[st_v])
			dij.insert({w, u});

		while (LEN(dij)) {
			auto [d, v] = *dij.begin();
			dij.erase(dij.begin());
			// cerr << "  v = " << v << ", d = " << d << '\n';
			if (vis[v])
				continue;
			if (vals[v] != d) {
				// cerr << "invalid[" << st << "] = 1" << "\n";
				break;
			}
			vis[v] = 1;
			vis_vals.push_back(v);
			for (auto [u, w] : adj[v])
				if (!vis[u])
					dij.insert({d+w, u});
		}
		if (LEN(vis_vals) == n) {
			cout << st_v << '\n';
			exit(0);
		}

		while (LEN(vis_vals)) {
			vis[vis_vals.back()] = 0;
			vis_vals.pop_back();
		}
	}

	cout << "-1\n";
}

int main () {
	// freopen("hide.in", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> vals[i];
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	dijkstra();

	return 0;
}
