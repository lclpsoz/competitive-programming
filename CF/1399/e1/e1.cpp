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

const int N = 1e5 + 10;

vpii adj[N];
int subtree_size[N], weight_parent[N];

int fill_sub (int v, int p) {
	int &now = subtree_size[v];
	now = LEN(adj[v]) == 1;
	for (auto [u, w] : adj[v])
		if (u != p) {
			weight_parent[u] = w;
			now += fill_sub(u, v);
		}
	return now;		
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n;
		ll max_sum;
		cin >> n >> max_sum;
		for (int i = 1; i <= n; i++) {
			adj[i].clear();
		}
		for (int i = 0; i < n-1; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			adj[u].push_back({v, w});
			adj[v].push_back({u, w});
		}

		fill_sub(1, 1);
		ll sum = 0;
		set<pair<ll, int>> edges;
		for (int i = 2; i <= n; i++) {
			ll weight_now = subtree_size[i]*1LL*weight_parent[i];
			sum += weight_now;
			ll delta = weight_now - (subtree_size[i]*1LL*(weight_parent[i]/2));
			// cerr << " v = " << i << ", sub = " << subtree_size[i] << ", wei = " << weight_parent[i] << '\n';
			edges.insert({-delta, i});
		}
		int ans = 0;
		while (sum > max_sum) {
			auto [delta, id] = *edges.begin();
			edges.erase(edges.begin());
			sum += delta;
			weight_parent[id] /= 2;
			delta = subtree_size[id]*1LL*weight_parent[id] - (subtree_size[id]*1LL*(weight_parent[id]/2));
			edges.insert({-delta, id});
			++ans;
		}
		cout << ans << '\n';
		
	}

	return 0;
}
