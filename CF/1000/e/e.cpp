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

const int N = 3e5 + 10;

bitset<N> vis;
vi order, comp;

struct graph {
	int n;
	vector<vi> adj;

	graph(int _n) : n(_n) {
		adj = vector<vi>(n+5);
	}
};

void dfs(int v, int p, graph &g_bi, graph &g_dir, graph &g_inv) {
	vis[v] = 1;
	for(int u : g_bi.adj[v]) {
		if(u != p) {
			g_dir.adj[v].push_back(u);
			g_inv.adj[u].push_back(v);
			if(!vis[u])
				dfs(u, v, g_bi, g_dir, g_inv);
		}
	}
	order.push_back(v);
}

void dfs_2(int v, graph &g_inv) {
	comp.push_back(v);
	vis[v] = 1;
	for(int u : g_inv.adj[v])
		if(!vis[u]) {
			dfs_2(u, g_inv);
		}
}

int prof_far = -1;
int v_far = -1;

void dfs_far(int v, int prof, graph &g) {
	if(prof > prof_far) {
		prof_far = prof;
		v_far = v;
	}
	vis[v] = 1;
	for(int u : g.adj[v])
		if(!vis[u])
			dfs_far(u, prof+1, g);
}	

int dfs_ans(int v, int prof, graph &g) {
	int ret = prof;
	vis[v] = 1;
	for(int u : g.adj[v])
		if(!vis[u])
			ret = max(ret, dfs_ans(u, prof+1, g));
	return ret;
}	


int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	cin >> n >> m;
	graph g_bi(n), g_dir(n), g_inv(n);
	while(m--) {
		int x, y;
		cin >> x >> y;
		g_bi.adj[x].push_back(y);
		g_bi.adj[y].push_back(x);
	}

	dfs(1, 1, g_bi, g_dir, g_inv);
	vis.reset();
	reverse(ALL(order));
	vi comp_id(n+5);
	int comp_sz = 0;
	vector<vi> comp_vertz(n+5);
	for(int v : order)
		if(!vis[v]) {
			comp.clear();
			dfs_2(v, g_inv);
			comp_sz++;
			for(int u : comp) {
				// cerr << "comp(" << comp_sz << "), v = " << u << '\n';
				comp_id[u] = comp_sz;
				comp_vertz[comp_sz].push_back(u);
			}
		}

	graph g_comp(comp_sz);
	// cerr << "comp_sz = " << comp_sz << '\n';
	set<int> adj;
	for(int i = 1; i <= comp_sz; i++) {
		adj.clear();
		for(int v : comp_vertz[i])
			for(int u : g_dir.adj[v])
				adj.insert(comp_id[u]);
		for(int u_comp : adj) {
			if(u_comp == i) continue;
			g_comp.adj[i].push_back(u_comp);
			g_comp.adj[u_comp].push_back(i);
			// cerr << "||adj_comp: " << i << " -> " << u_comp << '\n';
		}
	}


	vis.reset();
	dfs_far(1, 0, g_comp);
	vis.reset();
	cout << dfs_ans(v_far, 0, g_comp) << '\n';;


	return 0;
}
