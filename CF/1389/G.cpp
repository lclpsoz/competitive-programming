#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int DBG = 0;

struct graph {
	int n, k;
	vector<bool> special;
	vector<ll> values;
	vector<vpii> g;

	graph() {
		return;
	}

	graph(int _n) {
		n = _n;
		special = vector<bool>(n+1);
		values = vector<ll>(n+1);
		g = vector<vpii>(n+1);
	}

	void calc_k() {
		k = 0;
		for(bool v : special)
			k += v;
	}
};

struct compress_g {
	int n, m, k;
	graph base;
	vector<vpii> g_r;
	vi w_base;
	vector<bool> vis, vis_edge;
	vi order, compressed;

	vi v_comp;

	compress_g() {
		read_input();
	}

	graph get_comp() {
		for(int i = 1; i <= base.n; i++)
			if(!vis[i])	
				dfs1(i);
		reverse(ALL(order));
		vis.assign(LEN(vis), 0);
		int n_comp = 0;
		v_comp = vi(base.n+1);
		for(int v : order)
			if(!vis[v]) {
				dfs2(v);
				n_comp++;
				while(LEN(compressed)) {
					int u = compressed.back();
					compressed.pop_back();
					v_comp[u] = n_comp;
				}
			}
		
		graph comp = graph(n_comp);
		for(int v = 1; v <= base.n; v++) {
			comp.special[v_comp[v]] = comp.special[v_comp[v]] or base.special[v];
			comp.values[v_comp[v]] += base.values[v];
			// Will never have double edge. If it had, the two vertice would be
			// the same component.
			for(auto [u, id_edge] : base.g[v])
				if(v_comp[v] != v_comp[u])
					comp.g[v_comp[v]].push_back({v_comp[u], id_edge});
		}

		comp.calc_k();
		return comp;
	}

	void dfs1(int v) {
		vis[v] = 1;
		for(auto [u, id_edge] : base.g[v]) {
			if(!vis_edge[id_edge]) {
				vis_edge[id_edge] = 1;
				if(!vis[u])
					dfs1(u);
				if(DBG)
					cout << "g_r += " << u << " -> " << v << '\n';
				g_r[u].push_back({v, id_edge});
			}
		}
		order.push_back(v);
	}

	void dfs2(int v) {
		vis[v] = 1;
		for(auto [u, id_edge] : g_r[v])
			if(!vis[u])
				dfs2(u);
		compressed.push_back(v);
	}

	void read_input() {
		cin >> n >> m >> k;
		base = graph(n);
		vis = vector<bool>(n+1);
		g_r = vector<vpii>(n+1);
		for(int i = 0; i < k; i++) {
			int v;
			cin >> v;
			base.special[v] = 1;
		}
		for(int i = 1; i <= n; i++)
			cin >> base.values[i];

		w_base = vi(m);
		vis_edge = vector<bool>(m);
		for(int &v : w_base)
			cin >> v;
		for(int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			base.g[u].push_back({v, i});
			base.g[v].push_back({u, i});
		}
	}
};

const int N = 3e5 + 10;

compress_g compress;
graph g;
ll dp[N];
vi cnt_spc; // amount of specials in subtree v, based on edge u -> v, with u < v

int amount_specials(int v, int p) {
	int ret = 0;
	for(auto [u, e_id] : g.g[v])
		if(u != p) {
			int now = amount_specials(u, v);
			cnt_spc[e_id] = now;
			if(u > v) // complement, because cnt_spc[e_id] is u -> v, u < v
				cnt_spc[e_id] = g.k-now;
			ret += now;
		}
	
	return ret + g.special[v];
}

void fill_dp(int v, int p) {
	// Maybe would be interesting to know how many specials exist in
	// each direction of each edge in G. This will I would know when
	// I really need to let a edge be bidirectional.

	// Just noticed that in 1 DFS it's possible to obtain the information
	// for all edges. The inverse of the current direction is the complement
	// of the amount of special vertices. One way to implement it is using
	// edge indexes, to keep track of the amount of special vertices in each
	// direcion.
	dp[v] = g.values[v];
	for(auto [u, e_id] : g.g[v])
		if(u != p) {
			fill_dp(u, v);
			int spc_now = cnt_spc[e_id];
			if(spc_now == 0 or spc_now == g.k)
				dp[v] += dp[u];
			else
				dp[v] += max(0LL, dp[u]-compress.w_base[e_id]);
		}
}

void solve(int v, int p, int e_id_p) {
	// Rerooting, don't look quite challenging:
	// 1. Remove dp[v] from dp[p], based on how was used in fill_dp
	// 2. Treat p as any other child, calculate dp[v] just like fill_dp, as a root
	// 3. Call children
	// 4. Restore dp[p]
	if(v != p) {
		ll dp_p = dp[p];
		int spc_now = cnt_spc[e_id_p];
		if(spc_now == 0 or spc_now == g.k) {
			dp[p] -= dp[v];
			dp[v] += dp[p];
		}
		else {
			dp[p] -= max(0LL, dp[v]-compress.w_base[e_id_p]);
			dp[v] += max(0LL, dp[p]-compress.w_base[e_id_p]);
		}
		dp[p] = dp_p;
	}

	for(auto [u, e_id] : g.g[v])
		if(u != p)
			solve(u, v, e_id);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	g = compress.get_comp();

	cnt_spc = vi(compress.m);
	amount_specials(1, 1);

	if(DBG) {
		for(int i = 1; i <= compress.n; i++)
			cout << "i = " << i << ", comp = " << compress.v_comp[i] << '\n';
		for(int i = 1; i <= g.n; i++)
			cout << "comp = " << i << ", value = " << g.values[i] << '\n';
	}

	fill_dp(1, 1);
	solve(1, 1, -1);
	for(int i = 1; i <= compress.base.n; i++)
		cout << dp[compress.v_comp[i]] << " \n"[i==compress.base.n];

	return 0;
}
