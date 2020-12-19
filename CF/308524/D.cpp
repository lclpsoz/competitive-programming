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

void dfs (int v, int p, vector<vpii> &adj,
			vi &mini_edge, vector<ll> &t_entry, ll t_now = 0) {
	
	t_entry[v] = t_now;
	int min_e = mini_edge[v];
	for (auto [u, c] : adj[v])
		if (u != p)
			dfs (u, v, adj, mini_edge, t_entry, t_now + min_e + (c-min_e)*2);
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
		cin >> n;
		vector<vpii> adj(n+1);
		vi min_edge(n+1, INF<int>);
		for (int i = 2; i <= n; i++) {
			int p, c;
			cin >> p >> c;
			adj[p].push_back({i, c});
			min_edge[p] = min(min_edge[p], c);
		}

		vector<ll> t_entry(n+1);
		dfs (1, 1, adj, min_edge, t_entry);
		vector<ll> vals;
		for (int i = 1; i <= n; i++)
			if (min_edge[i] == INF<int>) {
				vals.push_back(t_entry[i]);
				// cerr << i << ": " << leafs[i] << '\n';
			}
		sort(ALL(vals));

		int q;
		cin >> q;
		while (q--) {
			ll tm;
			cin >> tm;
			cout << upper_bound(ALL(vals), tm) - vals.begin() << '\n';
		}
	}

	return 0;
}
