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

const int DBG = 1;
const int N = 2e5 + 10;
const int INF = 1e9;

struct segTree {
	int n, lft;
	vector<ll> tree, lazy;
	vector<pll> pa;
	segTree(int _n) {
		n = _n;
		lft = 1;
		tree = vector<ll>(4*n, 0);
		lazy = vector<ll>(4*n, 0);
		pa = vector<pll>(4*n, {0, 0});
		// build(1, 1, n);
	}

	void build(int v, int tl, int tr) {
		if(tl == tr) {
			tree[v] = 1;
		}
		else {
			int tm = (tl+tr)/2;
			build(2*v, tl, tm);
			build(2*v+1, tm+1, tr);
			tree[v] = min(tree[2*v], tree[2*v+1]);
			// cout << "||tree[" << v << "] = " << tree[v] << '\n';
		}
	}

	void push(int v, int tl, int tr) {
		if(tl < tr) {
			if(pa[v].x) {
				if(DBG) {
					cout << "    ||push: v = " << v << " | tl, tr = " << tl << ", " << tr << '\n';
					cout << "    ||push: pa = " << pa[v].x << ", " << pa[v].y << '\n';
				}
				
				lazy[v] = 0;
				ll pa_st_now = (tl-pa[v].y)+pa[v].x;
				int tm = (tl+tr)/2;

				int amnt = tm-tl+1;
				tree[2*v] = ((pa_st_now+(pa_st_now+amnt-1))*amnt)/2;

				tm++;
				pa_st_now = (tm-pa[v].y)+pa[v].x;
				amnt = tr-(tm+1);
				tree[2*v+1] = ((pa_st_now+(pa_st_now+amnt-1))*amnt)/2;


				pa[2*v] = pa[v];
				pa[2*v+1] = pa[v];
				pa[v] = {0, 0};
			}
			else if(lazy[v]) {
				tree[2*v] += lazy[v];
				tree[2*v+1] += lazy[v];
				// if(DBG)
				// 	cout << "    ||push: lazy:" << tree[2*v] << ", " << tree[2*v+1] << '\n';
				lazy[2*v] += lazy[v];
				lazy[2*v+1] += lazy[v];
				lazy[v] = 0;
			}
		}
	}

	void add(int v, int l, int r, int tl, int tr, int val) {
		if(DBG)
			cout << "    ||add: v = " << v << "| {l, r} = " << l <<", " << r << " | val = " << val << '\n';
		if(l <= tl and tr <= r) {
			tree[v] += val;
			lazy[v] += val;
			// cout << "||lazy[" << v << "] = "<< lazy[v] << '\n';
		} else if(tl <= r and l <= tr) {
			push(v, tl, tr);
			int tm = (tl+tr)/2;
			add(2*v, l, r, tl, tm, val);
			add(2*v+1, l, r, tm+1, tr, val);
			tree[v] = min(tree[2*v], tree[2*v+1]);
			// cout << "||tree[" << v << "] = " << tree[v] << '\n';
		}
	}

	void add_pa(int v, int l, int r, int tl, int tr, ll pa_start) {
		if(DBG)
			cout << "    ||add_pa: v = "<<v<<"| {l, r} = "<<l <<", " << r << '\n';
		push(v, tl, tr);
		if(l <= tl and tr <= r) {
			ll pa_st_now = (tl-l)+pa_start;
			int amnt = tr-tl+1;
			tree[v] = ((pa_st_now+(pa_st_now+amnt-1))*amnt)/2;
			pa[v] = {pa_start, l};
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
		// if(DBG)
		// 	cout << "      ||_get_min = " << v << '\n';
		push(v, tl, tr);
		if(l <= tl and tr <= r) {
			return tree[v];
		} else if(tl <= r and l <= tr) {
			push(v, tl, tr);
			int tm = (tl+tr)/2;
			return tree[v] = min(	_get_min(2*v, l, r, tl, tm),
									_get_min(2*v+1, l, r, tm+1, tr));
		}
	}

	void upd(int l, int r) {
		if(DBG) {
			cout << "  ||upd: " << l << ' ' << r << '\n';
			cout << "  ||upd: lft = " << lft << '\n';
		}
		add(1, lft, n, 1, n, 1);
		if(DBG) {
			cout << "  ||upd: get_min: " << get_min() << '\n';
			for(int i = 1; i <= n; i++) {
				cout << "  ||upd: " << i << ": " << _get_min(1, i, i, 1, n) << '\n';
				// cout << "  ||upd: " << i << ": " << _get_min(1, i, i, 1, n) << '\n';
			}
		}

		if(l <= lft) {
			add(1, lft, r, 1, n, INF);
			lft = r+1;
		}
		else if(lft <= n and lft <= r) {
			// l = max(lft, l);
			if(l > lft) {
				cout << "  ||upd: " << l << ", " << r << '\n';
				int pa_start = _get_min(1, l-1, l-1, 1, n) + 1;
				cout << "  ||upd: pa_start = " << pa_start << " vs " << _get_min(1, l-1, l-1, 1, n) << '\n';
				add_pa(1, l, r, 1, n, pa_start);
				if(DBG)
					for(int i = 1; i <= n; i++)
						cout << "  ||upd: " << i << ": " << _get_min(1, i, i, 1, n) << '\n';

			}
		}
		if(DBG)
			cout << "  ||upd: get_min: " << get_min() << '\n';
	}

	ll get_min() {
		if(lft > n) return -1;
		return _get_min(1, lft, n, 1, n);
	}
};

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	int h, w;
	cin >> h >> w;

	segTree seg(w);
	for(int i = 1; i <= h; i++) {
		int a, b;
		cin >> a >> b;
		seg.upd(a, b);
		cout << seg.get_min() << '\n';
	}

	return 0;
}
