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

struct dsu {
	int n;
	vi sz, link;

	dsu (int _n) : n(_n) {
		sz = vi(n+1, 1);
		link = vi(n+1);
		for (int i = 1; i <= n; i++)
			link[i] = i;
	}

	int find (int x) {
		if (link[x] == x) return x;
		return link[x] = find(link[x]);
	}

	bool same (int x, int y) {
		return this->find(x) == this->find(y);
	}

	void join (int x, int y) {
		x = find(x);
		y = find(y);
		if (this->same(x, y)) return;
		if (sz[x] > sz[y]) swap(x, y);

		sz[y] += sz[x];
		link[x] = y;
	}
};

struct graph {
	int n;
	vector<vi> adj;

	graph (int _n) : n(_n) {
		adj = vector<vi>(n+1);
	}
};

void no () {
	cout << "0\n";
	exit(0);
}

void top_sort (int v, int p, vi &color, vi &order, graph &g) {
	// cerr << "top_sort: " << v << ", " << p << '\n';
	if (color[v] == 2)
		return;
	if (color[v] == 1)
		no();
	color[v] = 1;
	for (int u : g.adj[v])
		if (u != p)
			top_sort(u, v, color, order, g);
	color[v] = 2;
	order.push_back(v);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, k;
	cin >> n >> k;
	graph base(n);
	vi parent(n+1);
	int start_v = -1;
	for (int i = 1; i <= n; i++) {
		int p;
		cin >> p;
		if (!p) start_v = i;
		else base.adj[p].push_back(i);
		parent[i] = p;
	}

	dsu comp(n);
	vi x_to_y(n+1), y_to_x(n+1);
	while (k--) {
		int x, y;
		cin >> x >> y;
		if (comp.same(x, y))
			no();
		else
			comp.join(x, y);
		x_to_y[x] = y;
		y_to_x[y] = x;
	}

	// Get components ids
	vi roots;
	for (int i = 1; i <= n; i++)
		if (comp.find(i) == i)
			roots.push_back(i);
	int n_comp = LEN(roots);

	// Get components
	graph comp_g(n_comp);
	vector<vi> comp_to_v(n_comp+1);
	vi v_to_comp(n+1);
	for (int i = 1; i <= n; i++) {
		int root = lower_bound(ALL(roots), comp.find(i))-roots.begin() + 1;
		comp_to_v[root].push_back(i);
		v_to_comp[i] = root;
		// cerr << i << " -> " << root << '\n';
	}

	// Sort components
	for (int i = 1; i <= n_comp; i++)
		if (LEN(comp_to_v[i]) > 1) {
			vi &cur_comp = comp_to_v[i];
			int st = -1;
			for (int v : cur_comp)
				if (y_to_x[v] == 0) {
					if (st != -1) no();
					st = v;
				}
			if (st == -1) no();

			int sz_bef = LEN(cur_comp);
			cur_comp.clear();
			for (int now = st; now; now = x_to_y[now])
				cur_comp.push_back(now);
			if (sz_bef != LEN(cur_comp))
				no();
			
			set<int> used;
			for (auto it = cur_comp.rbegin(); it != cur_comp.rend(); it++) {
				if (used.count(parent[*it]))
					no();
				else
					used.insert(*it);
			}
		}


	// cerr << "Fill\n";
	// Fill comp_g.adj
	for (int v_comp = 1; v_comp <= n_comp; v_comp++) {
		vi &cur_adj = comp_g.adj[v_comp];
		for (int v : comp_to_v[v_comp])
			for (int u : base.adj[v]) {
				int u_comp = v_to_comp[u];
				if (u_comp != v_comp) {
					cur_adj.push_back(u_comp);
				}
			}
		sort(ALL(cur_adj));
		cur_adj.resize(unique(ALL(cur_adj)) - cur_adj.begin());
	}
	
	// cerr << "n_comp = " << n_comp << '\n';
	vi color(n_comp+1);
	vi order;
	top_sort(v_to_comp[start_v], v_to_comp[start_v], color, order, comp_g);
	reverse(ALL(order));
	
	// Get vertice to print
	vi prt;
	for (int v_comp : order)
		for (int v : comp_to_v[v_comp])
			prt.push_back(v);
	
	for (int i = 0; i < LEN(prt); i++)
		cout << prt[i] << " \n"[i == LEN(prt)-1];


	return 0;
}
