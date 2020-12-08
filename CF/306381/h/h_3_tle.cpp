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

int main () {
	// freopen("hide.in", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> m;

	// int min_val = INF<ll>;
	// int min_val_cnt = 0;
	for (int i = 1; i <= n; i++) {
		cin >> vals[i];
		// if (vals[i] < min_val) {
		// 	min_val = vals[i];
		// 	min_val_cnt = 1;
		// }
		// else if (vals[i] == min_val)
		// 	min_val_cnt++;
	}
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	set<pair<ll, int>> dij;
	set<int> valid;
	vi valid_now;
	vi vis_vals;
	vi order;
	for (int i = 1; i <= n; i++)
		order.push_back(i);
	sort(ALL(order), [&] (int lhs, int rhs) {
		return vals[lhs] < vals[rhs];
	});
	for (int i = 0; i < n; i++) {
		int v_st = order[i];
		dij.clear();
		valid_now.clear();
		for (auto [u, w] : adj[v_st])
			if (w-vals[v_st] <= 0)
				dij.insert({(ll)-vals[v_st]+w, u});
		// cerr << "v_st = " << v_st << '\n';
		while (LEN(dij)) {
			auto [d, v] = *dij.begin();
			// cerr << "  v = " << v << ", d = " << d << '\n';
			dij.erase(dij.begin());
			if (vis[v])
				continue;
			vis[v] = 1;
			vis_vals.push_back(v);
			if (d == 0)
				valid_now.push_back(v);
			else
				for (auto [u, w] : adj[v])
					if (!vis[u] and d+w <= 0)
						dij.insert({d+w, u});
		}
		while (LEN(vis_vals)) {
			vis[vis_vals.back()] = 0;
			vis_vals.pop_back();
		}

		if (LEN(valid) == 0) {
			for (int v : valid_now)
				valid.insert(v);
		}
		else {
			if (LEN(valid_now) == 0) {
				valid.clear();
				break;
			}
			for (int v : valid_now)
				if (valid.count(v))
					vis_vals.push_back(v);
			valid.clear();
			for (int v : vis_vals)
				valid.insert(v);
			vis_vals.clear();
			if (LEN(valid) == 0)
				break;
		}
	}

	if (LEN(valid) == 0)
		cout << "-1\n";
	else {
		cout << *valid.begin() << '\n';
	}

	return 0;
}
