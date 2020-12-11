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

using pll = pair<ll, ll>;

const int DBG = 0;
const int N = 2e5 + 10;
const int INF = 1e9;

struct segTree {
	int n, lft;
	vector<ll> tree, lazy;
	// vi tm_lazy;
	vector<pll> pa;
	// vi tm_pa;
	// int t_now;
	segTree(int _n) {
		n = _n;
		lft = 1;
		tree = vector<ll>(4*n, 0);
		lazy = vector<ll>(4*n, 0);
		// tm_lazy = vi(4*n);
		pa = vector<pll>(4*n, {0, 0});
		// tm_pa = vi(4*n);
		// t_now = 1;
	}

	ll _calc_pa(ll pa_start, ll l, int tl, int tr) {
		ll pa_st_now = pa_start+(tl-l);
		int amnt = tr-tl+1;
		return ((pa_st_now+(pa_st_now+amnt-1)) * amnt)/2;
	}

	void push(int v, int tl, int tr) {
		if(tl < tr) {
			// if(tm_pa[v] > tm_lazy[v])
			// 	lazy[v] = 0;
			if(pa[v].x) { // Update VALUE, if needed
				// if(DBG) {
				// 	cout << "    ||push: v = " << v << " | tl, tr = " << tl << ", " << tr << '\n';
				// 	cout << "    ||push: pa = " << pa[v].x << ", " << pa[v].y << '\n';
				// }
								
				// lazy[v] = 0; // TODO: Makes sense?
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
				// if(pa[v].x)
				// 	pa[v].x += lazy[v];
				// if(pa[v].x)
				// 	pa[v].x += lazy[v];
				// if(pa[2*v+1].x)
				// 	pa[2*v+1].x += lazy[v];
				// if(DBG)
				// 	cout << "    ||push: lazy:" << tree[2*v] << ", " << tree[2*v+1] << '\n';
				lazy[2*v] += lazy[v];
				lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
		}
	}

	void add(int v, int l, int r, int tl, int tr, int val) {
		// t_now++;
		push(v, tl, tr);
		// if(DBG)
		// 	cout << "    ||add: v = " << v << "| {l, r} = " << l <<", " << r << " | val = " << val << '\n';
		if(l <= tl and tr <= r) {
			tree[v] += val;
			lazy[v] += val;
			// tm_lazy[v] = t_now;
			// cout << "||lazy[" << v << "] = "<< lazy[v] << '\n';
		} else if(tl <= r and l <= tr) {
			int tm = (tl+tr)/2;
			add(2*v, l, r, tl, tm, val);
			add(2*v+1, l, r, tm+1, tr, val);
			tree[v] = min(tree[2*v], tree[2*v+1]);
			// cout << "||tree[" << v << "] = " << tree[v] << '\n';
		}
	}

	void add_pa(int v, int l, int r, int tl, int tr, ll pa_start) {
		// t_now++;
		push(v, tl, tr);
		// if(DBG)
		// 	cout << "    ||add_pa: v = "<<v<<"| {l, r} = "<<l <<", " << r << '\n';
		if(l <= tl and tr <= r) {
			// tree[v] = _calc_pa(pa_start, l, tl, tr);
			tree[v] = pa_start+(tl-l);
			pa[v] = {pa_start, l};
			lazy[v] = 0;
			// tm_pa[v] = t_now;
			// cout << "||lazy[" << v << "] = "<< lazy[v] << '\n';
		} else if(tl <= r and l <= tr) {
			int tm = (tl+tr)/2;
			add_pa(2*v, l, r, tl, tm, pa_start);
			add_pa(2*v+1, l, r, tm+1, tr, pa_start);
			tree[v] = min(tree[2*v], tree[2*v+1]);
			// cout << "||tree[" << v << "] = " << tree[v] << '\n';
		}
	}

	ll _get_min(int v, int l, int r, int tl, int tr) {
		// t_now++;
		push(v, tl, tr);
		// if(DBG)
		// 	cout << "      ||_get_min = " << v << '\n';
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
		if(DBG) {
			cout << "  ||upd: " << l << ' ' << r << '\n';
			cout << "  ||upd: lft = " << lft << '\n';
		}
		add(1, lft, n, 1, n, 1);
		// if(DBG) {
		// 	cout << "  ||upd: get_min: " << get_min() << '\n';
		// 	for(int i = 1; i <= n; i++) {
		// 		cout << "  ||upd: " << i << ": " << _get_min(1, i, i, 1, n) << '\n';
		// 		// cout << "  ||upd: " << i << ": " << _get_min(1, i, i, 1, n) << '\n';
		// 	}
		// }

		if(l <= lft and lft <= r) {
			add(1, lft, r, 1, n, INF);
			lft = r+1;
		}
		else if(lft < l) {
			// l = max(lft, l);
			if(l > lft) {
				ll pa_start = _get_min(1, l-1, l-1, 1, n) + 1;
				if(DBG)
					cout << "  ||upd: pa_start = " << pa_start << " vs " << _get_min(1, l-1, l-1, 1, n) << '\n';
				add_pa(1, l, r, 1, n, pa_start);

			}
		}
		// if(DBG)
		// 	cout << "  ||upd: get_min: " << get_min() << '\n';
	}

	ll get_min() {
		if(lft > n) return -1;
		// cout << "  ||get_min: lft = " << lft << '\n';
		return _get_min(1, lft, n, 1, n);
	}
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int h, w;
	cin >> h >> w;

	segTree seg(w);
	for(int i = 1; i <= h; i++) {
		int a, b;
		cin >> a >> b;
		seg.upd(a, b);
		cout << seg.get_min() << '\n';
	}
	// if(DBG) {
	// 	for(int i = 1; i <= w; i++)
	// 		for(int j = i; j <= i; j++)
	// 			cout << "  [" << i << ", " << j << "]: " << seg._get_min(1, i, j, 1, w) << '\n';
	// }

	return 0;
}
