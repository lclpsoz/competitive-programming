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
const int MOD = 1e9 + 7;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return x%m;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

struct Dsu {
	int n;
	vi sz, link, edge;

	Dsu (int _n) : n(_n) {
		sz = vi(n+1);
		link = vi(n+1);
		edge = vi(n+1, -1);
		for (int i = 1; i <= n; i++)
			link[i] = i, sz[i] = 1;
	}

	int find (int v) {
		if (v == link[v]) return v;
		return find(link[v]);
	}

	bool same (int u, int v) {
		return find(u) == find(v);
	}

	void unite (int u, int v, int idx) {
		u = find(u);
		v = find(v);
		if (u == v) return;
		if (sz[u] > sz[v]) swap(u, v);
		sz[v] += sz[u];
		link[u] = v;
		edge[u] = idx;
	}
};

void solve () {
	int n, m;
	cin >> n >> m;
	set<int> active;
	vi ans;
	vi lft(n+1), rig(n+1);
	vi indexes_two;
	vi val_one_to_idx(m+1);
	for (int i = 1; i <= n; i++) {
		int k, x, y = 0;
		cin >> k >> x;
		if (k == 1) y = -1;
		if (y == -1) {
			if (active.insert(x).y) {
				// ans.push_back(i);
				val_one_to_idx[x] = i;
			}
		}
		else {
			cin >> y;
			indexes_two.push_back(i);
			lft[i] = x;
			rig[i] = y;
		}
	}

	Dsu dsu(m+1);
	for (int idx : indexes_two) {
		int x = lft[idx];
		int y = rig[idx];
		if (!dsu.same(x, y)) {
			// cerr << "unite: " << x << " + " << y << '\n';
			dsu.unite(x, y, idx);
		}
	}

	vector<bool> vis(m+1);
	vector<vector<pii>> adj(m+1);
	for (int i = 1; i <= m; i++) {
		int comp = dsu.find(i);
			// cerr << "  i = " << i << ", comp = " << comp << ", dsu.sz[comp] = " << dsu.sz[comp] << '\n';
		if (!vis[comp] and dsu.sz[comp] > 1 and active.count(i)) {
			vis[comp] = 1;
		}
	}
	for (int i = 1; i <= m; i++) {
		int comp = dsu.find(i);
		if (vis[comp] and dsu.sz[comp] > 1 and comp != i) {
			int v = i;
			int to = dsu.link[i];
			adj[v].push_back({to, dsu.edge[i]});
			adj[to].push_back({v, dsu.edge[i]});
		}
	}

	set<pii> dij;
	vis.assign(LEN(vis), false);
	for (int i = 1; i <= m; i++)
		if (active.count(i)) {
			dij.insert({val_one_to_idx[i], i});
		}

	while (LEN(dij)) {
		auto [idx, v] = *dij.begin();
		dij.erase(dij.begin());
		if (vis[v]) continue;
		// cerr << "v = " << v << '\n';
		ans.push_back(idx);
		vis[v] = 1;
		active.insert(v);
		for (auto [to, idx] : adj[v])
			if (!vis[to])
				dij.insert({idx, to});
	}
	// cerr << "LEN(ans) = " << LEN(ans) << ", LEN(active) = " << LEN(active) << '\n';

	ll mult = 1;
	int n_comp = LEN(active);
	for (int i = 1; i <= m; i++) {
		// cerr << "dsu_sz[" << i << "] = " << dsu.sz[i] << '\n';
		int comp = dsu.find(i);
		if (!vis[comp] and dsu.link[i] == i and dsu.sz[i] > 1) {
			// n_comp++;
			int qnt = dsu.sz[i];
			int p2 = 1;
			for (int i = 0; i < qnt-1; i++)
				p2 = mod(p2*2);
			mult = mod(mult * 1LL * p2);
		}

		if (!vis[comp] and dsu.sz[comp] and i != comp) {
			assert(dsu.edge[i] >= 1);
			ans.push_back(dsu.edge[i]);
		}
	}


	ll sz_t = 1;
	for (int i = 0; i < n_comp; i++)
		sz_t = mod(sz_t*2);
	sz_t = mod(sz_t * mult);

	sort(ALL(ans));
	cout << sz_t << ' ' << LEN(ans) << '\n';
	for (int i = 0; i < LEN(ans); i++)
		cout << ans[i] << " \n"[i==LEN(ans)-1];
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	solve();

	return 0;
}