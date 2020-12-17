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

struct graph {
	int n;
	vector<vi> adj;

	graph (int _n) : n(_n) {
		adj = vector<vi>(n+1);
	}	
};

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

void no () {
	cout << "0\n";
	exit(0);
}

void top_sort (int v, int p, vi &color, graph &comp, vi &order) {
	// cerr << "top_sort -> v = " << v << ", p = " << p << '\n';
	if (color[v] == 1)
		no();
	if (color[v] == 2)
		return;
	color[v] = 1;
	for (int u : comp.adj[v])
		if (u != p) {
			top_sort(u, v, color, comp, order);
		}
	order.push_back(v);
	color[v] = 2;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, k;
	cin >> n >> k;
	vi parent(n+1);
	vector<vi> adj(n+1);
	int start_v = -1;
	for (int i = 1; i <= n; i++) {
		cin >> parent[i];
		if (parent[i] == 0) start_v = i;
		adj[parent[i]].push_back(i);
	}

	dsu st(n);
	vpii pairs;
	vi x_to_y(n+1), y_to_x(n+1);
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		pairs.push_back({x, y});
		if (st.same(x, y))
			no();
		else
			st.join(x, y);
		x_to_y[x] = y;
		y_to_x[y] = x;
	}
	// for (int i = 1; i <= n; i++)
	// 	cerr << "st.find(" << i << ") = " << st.find(i) << '\n';
	sort(ALL(pairs));
	vector<vi> elements(n+1);
	// for (int i = 1; i <= n; i++)
	// 	if (i == st.find(i))
	// 		cerr << "LEN(elements[" << i << "]) = " << LEN(elements[i]) << '\n';
	for (auto [x, y] : pairs) {
		// cerr << "x = " << x << ", y = " << y << '\n';
		int root = st.find(x);
		// cerr << "|| root = " << root << ", LEN = " << LEN(elements[root]) << '\n';
		elements[root].push_back(x);
		elements[root].push_back(y);
	}

	// sort elements:
	// cerr << "Sort elements:\n";
	for (int i = 1; i <= n; i++)
		if (LEN(elements[i]) > 1) {
			sort(ALL(elements[i]));
			elements[i].resize(unique(ALL(elements[i])) - elements[i].begin());
			int st = -1;
			for (int v : elements[i]) {
				if (y_to_x[v] == 0) {
					if (st != -1)
						no();
					st = v;
				}
				// cerr << "v = " << v << ", y_x = " << y_to_x[v] << '\n';
			}
			if (st == -1)
				no();
			
			int ori_sz = LEN(elements[i]);
			elements[i].clear();
			for (int now = st; now; now = x_to_y[now])
				elements[i].push_back(now);
			// cerr << "  elements[" << i << "] = ";
			// for (int v : elements[i])
			// 	cerr << v << ' ';
			// cerr << '\n';

		}

	for (int i = 1; i <= n; i++)
		if (LEN(elements[i]) > 1) {
			set<int> used;
			for (auto it = elements[i].rbegin(); it != elements[i].rend(); it++) {
				// cerr << "*it = " << *it << '\n';
				if (used.count(parent[*it]))
					no();
				else
					used.insert(*it);
			}
		}

	int n_new = 0;
	vi comp_idxs;
	for (int i = 1; i <= n; i++) {
		if (st.find(i) == i) {
			n_new++;
			comp_idxs.push_back(i);
		}
	}
	// cerr << "n_new = " << n_new << '\n';
	vector<vi> comp_to_v(n_new+1);
	vi v_to_comp(n+1);
	for (int i = 1; i <= n; i++) {
		int root = st.find(i);
		int v = (lower_bound(ALL(comp_idxs), root)-comp_idxs.begin())+1;
		comp_to_v[v].push_back(i);
		v_to_comp[i] = v;
	}
	
	graph comp(n_new);
	for (int i = 1; i <= n_new; i++) {
		// cerr << "LEN(comp_to_v[" << i << "] = " << LEN(comp_to_v[i]) << '\n';
		for (int v : comp_to_v[i])
			for (int u : adj[v]) {
				int u_comp = v_to_comp[u];
				if (u_comp != i) {
					comp.adj[i].push_back(u_comp);
					// cerr << i << ' ' << u_comp << '\n';
				}
			}
		sort(ALL(comp.adj[i]));
		comp.adj[i].resize(unique(ALL(comp.adj[i])) - comp.adj[i].begin());
	}

	vi color(comp.n+1);
	vi order;
	top_sort(v_to_comp[start_v], v_to_comp[start_v], color, comp, order);

	reverse(ALL(order));
	vi prt;
	for (int i = 0; i < LEN(order); i++) {
		// cerr << "  order[" << i << "] = " << order[i] << '\n';
		if (LEN(comp_to_v[order[i]]) > 1) {
			int root = st.find(comp_to_v[order[i]].front());

			for (int v : elements[root])
				prt.push_back(v);
		}
		else
			prt.push_back(comp_to_v[order[i]].front());
	}
	for (int i = 0; i < LEN(prt); i++)
		cout << prt[i] << " \n"[i == LEN(prt)-1];

	return 0;
}
