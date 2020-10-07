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
const int INF = 1e7;

struct segTree {
	int n, lft;
	vi tree, lazy;
	vpii pa;
	segTree(int _n) {
		n = _n;
		lft = 1;
		tree = vi(4*n, 0);
		lazy = vi(4*n, 0);
		pa = vpii(4*n, {0, 0});
	}

	void push(int v, int tl, int tr) {
		if(tl < tr) {
			if(pa[v].x) {
				int tm = (tl+tr)/2;
				int pa_start = pa[v].x;
				int l = pa[v].y;
				tree[2*v] = pa_start+(tl-l);
				tree[2*v+1] = pa_start+(tm+1-l);

				pa[2*v] = pa[v];
				pa[2*v+1] = pa[v];
				lazy[2*v] = 0;
				lazy[2*v+1] = 0;
				pa[v] = {0, 0};
			}
			if(lazy[v]) {
				tree[2*v] += lazy[v];
				tree[2*v+1] += lazy[v];
				lazy[2*v] += lazy[v];
				lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
		}
	}

	void add(int v, int l, int r, int tl, int tr, int val) {
		push(v, tl, tr);
		if(l <= tl and tr <= r) {
			tree[v] += val;
			lazy[v] += val;
		} else if(tl <= r and l <= tr) {
			int tm = (tl+tr)/2;
			add(2*v, l, r, tl, tm, val);
			add(2*v+1, l, r, tm+1, tr, val);
			tree[v] = min(tree[2*v], tree[2*v+1]);
		}
		push(v, tl, tr);
	}

	void add_pa(int v, int l, int r, int tl, int tr, int pa_start) {
		push(v, tl, tr);
		if(l <= tl and tr <= r) {
			tree[v] = pa_start+(tl-l);
			pa[v] = {pa_start, l};
			lazy[v] = 0;
		} else if(tl <= r and l <= tr) {
			int tm = (tl+tr)/2;
			add_pa(2*v, l, r, tl, tm, pa_start);
			add_pa(2*v+1, l, r, tm+1, tr, pa_start);
			tree[v] = min(tree[2*v], tree[2*v+1]);
		}
		push(v, tl, tr);
	}

	int _get_min(int v, int l, int r, int tl, int tr) {
		push(v, tl, tr);
		if(l <= tl and tr <= r) {
			return tree[v];
		} else if(tl <= r and l <= tr) {
			int tm = (tl+tr)/2;
			return min(	_get_min(2*v, l, r, tl, tm),
						_get_min(2*v+1, l, r, tm+1, tr));
		}
		return INF;
	}

	void upd(int l, int r) {
		add(1, lft, n, 1, n, 1);

		if(l <= lft and lft <= r) {
			add(1, lft, r, 1, n, INF);
			lft = max(lft, r+1);
		}
		else if(lft < l) {
			int pa_start = _get_min(1, l-1, l-1, 1, n) + 1;
			add_pa(1, l, r, 1, n, pa_start);
		}
	}

	int get_min() {
		if(lft > n) return -1;
		int ret = _get_min(1, lft, n, 1, n);
		ret = (ret > 1e6 ? -1 : ret);
		return ret;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int h, w;
	cin >> h >> w;

	segTree seg(w);
	for(int q= 1; q <= h; q++) {
		int a, b;
		cin >> a >> b;
		seg.upd(a, b);
		cout << seg.get_min() << '\n';
	}

	return 0;
}
