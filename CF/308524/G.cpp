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

struct source_dest {
	int a;
	int b;
};	

struct cost {
	int c;
	int w;
};

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector<pair<source_dest, cost>> edges(m);
		for (int i = 0; i < m; i++) {
			int a, b, c, w;
			cin >> a >> b >> c >> w;
			edges[i] = {{a, b}, {c, w}};
		}

		long long ans = 1e18;
		int l, r;
		l = 0, r = 1e9;
		while (l < r) {
			int md = (l + r) / 2;

			vector<vector<pair<int, cost>>> adj(n + 1, vector<pair<int, cost>>());
			for (int i = 0; i < m; i++) {
				if (edges[i].second.w <= md) {
					int a = edges[i].first.a;
					int b = edges[i].first.b;
					adj[a].push_back({b, edges[i].second});
					adj[b].push_back({a, edges[i].second});
				}
			}

			vector<long long> cost(n + 1, 1e18);
			vector<long long> wisdom(n + 1, -1);
			priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
			cost[1] = 0;
			pq.push({0, 1});
			while (!pq.empty()) {
				int v = pq.top().second;
				pq.pop();

				for (auto st : adj[v]) {
					int u = st.first;
					int c = st.second.c;
					long long w = st.second.w;
					if (cost[u] > cost[v] + c) {
						cost[u] = cost[v] + c;
						wisdom[u] = max(w, wisdom[v]);
						pq.push({cost[u], u});
					}
				}
			}

			if (cost[n] < k && cost[n] != -1) {
				r = md;
				ans = min(ans, wisdom[n]);
			} else {
				l = md + 1;
			}
		}
		if (ans == 1e18)
			ans = -1;
		cout << ans << endl;
	}

	return 0;
}
