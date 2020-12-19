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

struct Dsu {
	int n;
	int t;
	vi sz, link, tm;

	Dsu (int _n) : n(_n) {
		sz = vi(n+1, 1);
		tm = vi(n+1, 0);
		link = vi(n+1);
		for (int i = 1; i <= n; i++)
			link[i] = i;
		t = 0;
	}

	int find (int x, int t_max) {
		if (link[x] == x or tm[x] > t_max) return x;
		return find(link[x], t_max);
	}

	bool same (int x, int y, int t_max) {
		return this->find(x, t_max) == this->find(y, t_max);
	}

	void join (int x, int y) {
		++t;
		x = find(x, t+1);
		y = find(y, t+1);
		if (this->same(x, y, t+1)) return;
		if (sz[x] > sz[y]) swap(x, y);

		sz[y] += sz[x];
		tm[x] = t;
		link[x] = y;
	}

	int tm_join (int x, int y) {
		++t;
		assert(x != y);
		int l = 0, r = t;
		while (l < r) {
			int md = (l+r)/2;
			if (this->same(x, y, md))
				r = md;
			else
				l = md+1;
		}
		if (l == t)
			return -1;
		return l;
	}
};


int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n, m;

		cin >> n >> m;
		Dsu dsu(n);
		while (m--) {
			int opt, u, v;
			cin >> opt >> u >> v;
			if (opt == 1) {
				dsu.join(u, v);
			}
			else {
				int ret = dsu.tm_join(u, v);
				cout << ret << '\n';
			}
		}
	}

	return 0;
}
