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

const int N = 1e3 + 10;

vi adj[N], adj_inv[N];
bitset<N> vis;
vi order, comp_cur;

vi comp_adj[N], comp_to_v[N];
vi comp_sz(N), v_to_comp(N);
vi comp_in_degree(N);

void dfs1 (int v, int p) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : adj[v])
		if (u != p)
			dfs1(u, v);
	order.push_back(v);
}

void dfs2 (int v, int p) {
	if (vis[v]) return;
	vis[v] = 1;
	for (int u : adj_inv[v])
		if (u != p)
			dfs2(u, v);
	comp_cur.push_back(v);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj_inv[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs1(i, i);
	vis.reset();

	int comp_len = 0;
	reverse(ALL(order));
	for (int v_cur : order)
		if (!vis[v_cur]) {
			// cerr << "order: " << v_cur << '\n';
			dfs2(v_cur, v_cur);
			++comp_len;
			comp_sz[comp_len] = LEN(comp_cur);
			// cerr << "comp[" << comp_len << "] = ";
			for (int v : comp_cur) {
				// cerr << v << ' ';
				comp_to_v[comp_len].push_back(v);
				v_to_comp[v] = comp_len;
			}
			comp_cur.clear();
			// cerr << '\n';
		}
	for (int v_comp = 1; v_comp <= comp_len; v_comp++)
		for (int v : comp_to_v[v_comp])
			for (int u : adj[v]) {
				int u_comp = v_to_comp[u];
				if (u_comp != v_comp) {
					// cerr << "comp_adj[" << v_comp << "] += " << u_comp << '\n';
					comp_adj[v_comp].push_back(u_comp);
					comp_in_degree[u_comp]++;
				}
			}
	
	int ans = 0;
	vi bfs;
	for (int v = 1; v <= comp_len; v++)
		if (!comp_in_degree[v] and comp_sz[v] <= 3)
			bfs.push_back(v);
	for (int i = 0; i < LEN(bfs); i++) {
		int v = bfs[i];
		for (int u : comp_adj[v]) {
			comp_in_degree[u]--;
			if (comp_in_degree[u] == 0 and comp_sz[u] <= 3)
				bfs.push_back(u);
		}
		ans += comp_sz[v];
	}
	cout << ans << '\n';

	return 0;
}
