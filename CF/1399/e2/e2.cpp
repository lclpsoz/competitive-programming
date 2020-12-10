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

vector<pair<int, pii>> adj[N];
int subtree_size[N], weight_parent[N], cost_parent[N];

int fill_sub (int v, int p) {
	int &now = subtree_size[v];
	now = LEN(adj[v]) == 1;
	for (auto [u, eg] : adj[v]) {
		auto [w, c] = eg;
		if (u != p) {
			weight_parent[u] = w;
			cost_parent[u] = c;
			now += fill_sub(u, v);
		}
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
			int u, v, w, c;
			cin >> u >> v >> w >> c;
			adj[u].push_back({v, {w, c}});
			adj[v].push_back({u, {w, c}});
		}

		fill_sub(1, 1);
		ll sum = 0;
		set<pair<ll, int>> edges_one, edges_two;
		for (int i = 2; i <= n; i++) {
			ll weight_now = subtree_size[i]*1LL*weight_parent[i];
			sum += weight_now;
			ll delta = weight_now - (subtree_size[i]*1LL*(weight_parent[i]/2));
			// cerr << " v = " << i << ", sub = " << subtree_size[i] << ", wei = " << weight_parent[i] << '\n';
			if (cost_parent[i] == 1)
				edges_one.insert({delta, i});
			else
				edges_two.insert({delta, i});
		}

		auto divide_edge = [&] (const int id, ll delta, set<pair<ll, int>> &edges) {
			edges.erase({delta, id});
			weight_parent[id] /= 2;
			delta = subtree_size[id]*1LL*weight_parent[id] - (subtree_size[id]*1LL*(weight_parent[id]/2));
			edges.insert({delta, id});
		};

		vector<ll> dp(40*(n+1));
		int lst_pos_one = 0;
		if (LEN(edges_one))
			for (int i = 1; i <= 20*LEN(edges_one) and edges_one.rbegin()->x; i++) {
				auto [delta, id] = *edges_one.rbegin();
				dp[i] = dp[i-1] + delta;
				divide_edge(id, delta, edges_one);
				lst_pos_one = i;
			}

		// for (int i = 1; i <= lst_pos_one; i++)
		// 	cerr << "  dp_aft_1[" << i << "] = " << dp[i] << '\n';

		ll delta_need = sum - max_sum;
		if (LEN(edges_two)) {
			int cost_two = 0;
			ll delta_two = 0;
			for (int i = lst_pos_one; i >= 0; i--) {
				ll nxt_dp = delta_two + dp[i];
				while (edges_two.rbegin()->x and nxt_dp < delta_need) {
					delta_two += edges_two.rbegin()->x;
					nxt_dp += edges_two.rbegin()->x;
					divide_edge(edges_two.rbegin()->y, edges_two.rbegin()->x, edges_two);
					cost_two += 2;
				}
				// cerr << "    i = " << i << ", edges_two.rbegin()->x = " << edges_two.rbegin()->x << '\n';
				dp[i+cost_two] = max(dp[i+cost_two], nxt_dp);
			}
		}
		// cerr << "t = " << t << '\n';
		// cerr << "  delta_need = " << delta_need << '\n';
		for (int i = 0; i < LEN(dp); i++) {
			// cerr << "  dp[" << i << "] = " << dp[i] << '\n';
			if (dp[i] >= delta_need) {
				cout << i << '\n';
				break;
			}
		}
		// cerr << '\n';
	}

	return 0;
}
