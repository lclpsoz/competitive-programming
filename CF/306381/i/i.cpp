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
	vi link, sz;
	dsu (int _n) : n(_n) {
		link = vi(n+1);
		sz = vi(n+1);
		this->reset();
	}

	int find (int x) {
		if (link[x] == x) return x;
		return link[x] = find(link[x]);
	}

	bool same (int x, int y) {
		return find(x) == find(y);
	}

	void join (int u, int v) {
		u = this->find(u);
		v = this->find(v);
		if (same(u, v))
			return;
		if (sz[u] > sz[v]) swap(u, v);
		sz[v] += sz[u];
		link[u] = v;
	}

	void reset () {
		for (int i = 1; i <= n; i++)
			link[i] = i, sz[i] = 1;
	}
};

int main () {
	// freopen("xot.in", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// assert(false);
	int n;
	cin >> n;
	set<pii> edges;
	map<int, int> dg;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int v;
			cin >> v;
			if (i < j and v) {
				edges.insert({i, j});
				dg[i]++;
				dg[j]++;
				// cerr << "|| " << i << " -> " << j << '\n';
			}
		}
	set<pii> edges_perm = edges;
	int m = LEN(edges);
	if (n%2 == 1 and LEN(edges)%2 == 1)
		cout << "-1\n";
	else {
		vector<vpii> trees;
		dsu now(n);
		dsu tree_first(n), tree_sec(n);
		while (LEN(edges) > 1) {
			vpii edges_rem;
			int st_v = -1;
			int mx_v = 0;
			for (auto [v, val] : dg)
				if (val > mx_v) {
					mx_v = val;
					st_v = v;
				}
			// cerr << "st_v = " << st_v << '\n';
			for (auto [u, v] : edges) {
				if (u != st_v and v != st_v) continue;
				// if (u != st_v and v != st_v and u != st_u and v != st_v) continue;
				if (!(now.same(u, v))) {
					edges_rem.push_back({u, v});
					now.join(u, v);
				}
			}
			// for (auto [u, v] : edges) {
			// 	if (st_v == -1) st_v = v;
			// 	if (u != st_v and v != st_v) continue;
			// 	// if (u != st_v and v != st_v and u != st_u and v != st_v) continue;
			// 	if (!(now.same(u, v))) {
			// 		edges_rem.push_back({u, v});
			// 		now.join(u, v);
			// 	}
			// }
			if (LEN(edges_rem)%2 == 1) edges_rem.pop_back();
			if (LEN(edges_rem) == 0) break;
			now.reset();
			
			vpii edges_first, edges_sec;
			for (int i = 0; i < LEN(edges_rem); i++) {
				auto [u, v] = edges_rem[i];
				if (i%2) {
					edges_first.push_back({u, v});
					tree_first.join(u, v);
				}
				else {
					edges_sec.push_back({u, v});
					tree_sec.join(u, v);
				}
			}
			
			for (int i = 1; i <= n; i++)
				for(int j = i+1; j <= n; j++)
					if (!tree_first.same(i, j) and !tree_sec.same(i, j)) {
						tree_first.join(i, j);
						tree_sec.join(i, j);
						edges_first.push_back({i, j});
						edges_sec.push_back({i, j});
					}

			trees.push_back(edges_first);
			trees.push_back(edges_sec);
			tree_first.reset();
			tree_sec.reset();
			for (auto e : edges_rem) {
				edges.erase(e);
				dg[e.x]--;
				dg[e.y]--;
			}
		}

		while (LEN(edges)) {
			int e_u = edges.begin()->x;
			int e_v = edges.begin()->y;
			edges.erase(edges.begin());

			vpii edges_first, edges_sec, edges_third;

			vi order;
			for (int i = 1; i <= n; i++)
				order.push_back(i);
			do {
				edges_third.push_back({e_u, e_v});
				cerr << "e_u = " << e_u << ", e_v = " << e_v << '\n';
				for (int i = 1, j = 0; i <= n; i++)
					if (i != e_u and i != e_v) {
						if (j%2) {
							edges_first.push_back({e_u, i});
							tree_first.join(e_u, i);
						}
						else {
							edges_sec.push_back({e_u, i});
							tree_sec.join(e_u, i);
						}
						edges_third.push_back({e_u, i});
						++j;
					}
				cerr << "LEN(edges_first) = " << LEN(edges_first) << '\n';
				cerr << "LEN(edges_sec) = " << LEN(edges_sec) << '\n';

				random_shuffle(ALL(order));
				for (int i : order)
					for(int j = i+1; j <= n; j++) {
						cerr << "st = " << i << '\n';
						if (!tree_first.same(i, j) and !tree_sec.same(i, j)) {
							cerr << "  " << i << " -> " << j << '\n';
							tree_first.join(i, j);
							tree_sec.join(i, j);
							edges_first.push_back({i, j});
							edges_sec.push_back({i, j});
						}
					}
				if (LEN(edges_first) != n-1) {
					edges_first.clear();
					edges_sec.clear();
					edges_third.clear();
					tree_first.reset();
					tree_sec.reset();
				}
			} while (LEN(edges_first) != n-1);
			trees.push_back(edges_first);
			trees.push_back(edges_sec);	
			trees.push_back(edges_third);	
			tree_first.reset();
			tree_sec.reset();
		}
		assert(LEN(trees) <= n+m);
		map<pii, int> mp;
		for (auto tree : trees) {
			assert(LEN(tree) == n-1);
			for (auto e : tree)
				mp[e]++;
		}
		for (auto p : mp)
			if (p.y%2 == 1) {
				// cerr << p.x.x << " -> " << p.x.y << '\n';
				assert(edges_perm.count(p.x));
				edges_perm.erase(p.x);
			}
		assert(LEN(edges_perm) == 0);
		cout << LEN(trees) << '\n';
		for (vpii tree : trees)
			for (auto [u, v] : tree)
				cout << u << ' ' << v << '\n';

		
	}

	return 0;
}
