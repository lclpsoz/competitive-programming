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
bitset<N> invalid;
set<int> vis[N];

void dijkstra () {
	set<pair<int, pair<ll, int>>> dij;
	vi mp(n+1), mp_back(n+1);
	for (int i = 1; i <= n; i++)
		mp[i] = i;
	// random_shuffle(ALL(mp));
	for (int i = 1; i <= n; i++)
		mp_back[mp[i]] = i;
	for (int v = 1; v <= n; v++)
		for (auto [u, w] : adj[v])
			dij.insert({mp[v], {w, u}});

	
	while (LEN(dij)) {
		auto [st, _pp] = *dij.begin();
		dij.erase(dij.begin());
		auto [d, v] = _pp;
		st = mp_back[st];
		// cerr << "st = " << st << ", v = " << v << ", d = " << d << '\n';
		if (invalid[st] or vis[st].count(v) != 0)
			continue;
		if (vals[v] != d) { // d == dist[v][st]
			// cerr << "invalid[" << st << "] = 1" << "\n";
			invalid[st] = 1;
			vis[st].clear();
			continue;
		}
		vis[st].insert(v);
		if (LEN(vis[st]) == n) break;
		for (auto [u, w] : adj[v])
			dij.insert({mp[st], {d+w, u}});
	}

	for (int i = 1; i <= n; i++)
		if (LEN(vis[i]) == n) {
			cout << i << '\n';
			exit(0);
		}
	cout << "-1\n";
}

int main () {
	freopen("hide.in", "r", stdin);
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
