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
ll dist[N];
vpii adj[N];
bitset<N> vis;

void no () {
	cout << "-1\n";
	exit(0);
}

int main () {
	// freopen("hide.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> dist[i];
	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	vector<pair<ll, int>> order;
	for (int i = 1; i <= n; i++)
		order.push_back({dist[i], i});
	sort(ALL(order));
	reverse(ALL(order));

	set<int> processed, valid;
	processed.insert(order.back().y);
	for (auto [u, w] : adj[order.back().y])
		if (w == order.back().x)
			valid.insert(u);

	order.pop_back();
	while (LEN(order)) {
		int v = order.back().y;
		order.pop_back();
		bool all_valid = false;
		vi keep_valid;
		sort(ALL(adj[v]));
		for (auto [u, w] : adj[v]) {
			if (processed.count(u)) {
				if (dist[u]+w < dist[v]) {
					no();
				} else if (dist[u]+w == dist[v])
					all_valid = true;
			}
			if (w < dist[v])
				valid.erase(u);
			else if (w == dist[v])
				keep_valid.push_back(u);
		}
		vi to_rem;
		if (!all_valid) {
			int p = 0;
			for (int u : valid) {
				while (p < LEN(keep_valid) and keep_valid[p] < u)
					++p;
				if (p == LEN(keep_valid) or keep_valid[p] != u)
					to_rem.push_back(u);
			}
			for (int u : to_rem)
				valid.erase(u);
		}
		processed.insert(v);
	}

	if (!LEN(valid))
		no();
	cout << *valid.begin() << '\n';
	
	return 0;
}
