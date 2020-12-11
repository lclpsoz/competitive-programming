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

const bool DBG = false;

struct node {
	ll prop = 0, lazy = 0;
	int amount_positive, mini;
	bool leaf = false;

	node() {}
	node(int _prop) {
		prop = _prop;
		mini = prop;
		amount_positive = 1;
	}
	node(const node &lht, const node &rht) {
		prop = lht.prop + rht.prop;
		mini = min(lht.mini, rht.mini);
		amount_positive = lht.amount_positive + rht.amount_positive;
	}

	void merge(const node &lht, const node &rht) {
		prop = lht.prop + rht.prop;
		amount_positive = lht.amount_positive + rht.amount_positive;
		int mn1 = lht.mini, mn2 = rht.mini;
		if(mn1 > mn2)
			swap(mn1, mn2);
		if(mn1 == mn2 and mn1 == 0)
			mini = 0;
		else if(mn1 == 0)
			mini = mn2;
		else
			mini = min(mn1, mn2);
		if(DBG) {
			cout << "    ||merge: mn1 = " << mn1 << ", mn2 = " << mn2 << ", mini = " << mini << '\n';
			cout << "    ||merge: amnt_pos = " << amount_positive << '\n';
		}
	}

	void apply_lazy(int _lazy) {
		if(mini)
			mini -= _lazy;
		prop -= _lazy*amount_positive;
		if(leaf and !prop) amount_positive = 0;
		lazy += _lazy;
	}

};

struct segTree {
	int n;
	vector<node> tree;
	segTree(vi &values) {
		n = LEN(values);
		tree = vector<node>(4*n);
		build(1, 1, n, values);
	}

	void build(int v, int tl, int tr, vi &values) {
		if(DBG)
			cout << "  ||build: v = " << v << " | t = " << tl << ", " << tr << '\n';
		if(tl == tr) {
			tree[v] = node(values[tl-1]);
			tree[v].leaf = true;
		} else {
			int tm = (tl+tr)/2;
			build(2*v, tl, tm, values);
			build(2*v+1, tm+1, tr, values);
			tree[v] = node(tree[2*v], tree[2*v+1]);
		}
	}

	void push(int v, int tl, int tr) {
		ll &lazy = tree[v].lazy;
		if(tl < tr) {
			tree[2*v].apply_lazy(lazy);
			tree[2*v+1].apply_lazy(lazy);
			
			lazy = 0;
		}
	}

	void _upd_zero(int v, int l, int r, int tl, int tr) {
		if(tl <= r and l <= tr and tl < tr and tree[v].mini == 0){
			if(DBG)
				cout << "  ||_upd_zero: v = " << v << ", tl = " << tl << ", tr = " << tr << '\n';
			push(v, tl, tr);
			int tm = (tl+tr)/2;
			_upd_zero(2*v, l, r, tl, tm);
			_upd_zero(2*v+1, l, r, tm+1, tr);
			tree[v].merge(tree[2*v], tree[2*v+1]);
		}
	}

	void _sub(int v, int l, int r, int tl, int tr, int val) {
		if(l <= tl and tr <= r) {
			tree[v].apply_lazy(val);
		} else if(tl <= r and l <= tr){
			push(v, tl, tr);
			int tm = (tl+tr)/2;
			_sub(2*v, l, r, tl, tm, val);
			_sub(2*v+1, l, r, tm+1, tr, val);
			tree[v].merge(tree[2*v], tree[2*v+1]);
		}
	}

	ll _sum(int v, int l, int r, int tl, int tr) {
		if(l <= tl and tr <= r) {
			return tree[v].prop;
		} else if(tl <= r and l <= tr) {
			// cout << "  ||_sum: tl = " << tl << ", tr = " << tr << '\n';
			push(v, tl, tr);
			int tm = (tl+tr)/2;
			return _sum(2*v, l, r, tl, tm) + _sum(2*v+1, l, r, tm+1, tr);
		}
		return 0LL;
	}


	int get_min(int v, int l, int r, int tl, int tr) {
		if(l <= tl and tr <= r) {
			return tree[v].mini;
		} else if(tl <= r and l <= tr) {
			push(v, tl, tr);
			int tm = (tl+tr)/2;
			int mn1 = get_min(2*v, l, r, tl, tm);
			int mn2 = get_min(2*v+1, l, r, tm+1, tr);
			if(mn1 > mn2)
				swap(mn1, mn2);
			if(mn1 == mn2 and mn1 == 0)
				return 0;
			else if(mn1 == 0)
				return mn2;
			else
				return min(mn1, mn2);
		}
		return 1e9;
	}

	void add(int l, int r, int val) {
		val = abs(val);
		_upd_zero(1, l, r, 1, n);
		int mini = get_min(1, l, r, 1, n);
		if(DBG)
			cout << "  ||mini = " << mini << '\n';
		while(mini and mini < val) {
			_sub(1, l, r, 1, n, mini);
			val -= mini;
			mini = get_min(1, l, r, 1, n);
			if(DBG)
				cout << "  ||bef_upd_zero: mini = " << mini << ", val = " << val << '\n';
			_upd_zero(1, l, r, 1, n);
			mini = get_min(1, l, r, 1, n);
			if(DBG)
				cout << "  ||aft_upd_zero: mini = " << mini << ", val = " << val << '\n';
		}
		if(mini and val)
			_sub(1, l, r, 1, n, val);
	}

	ll sum(int l, int r) {
		return _sum(1, l, r, 1, n);
	}

};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, q;
	vi values;

	cin >> n >> q;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		values.push_back(x);
	}

	segTree seg(values);

	while(q--) {
		int opt;
		cin >> opt;
		int a, b;
		cin >> a >> b;
		if(DBG)
			cout << "qry: " << opt << ' ' << a << ' ' << b << '\n';
		if(opt == 1) {
			cout << seg.sum(a, b) << '\n';
		} else {
			int x;
			cin >> x;
			if(DBG)
				cout << "  x = " << x << '\n';
			seg.add(a, b, x);
		}
		if(DBG) {
			for(int i = 1; i <= 7; i++)
				cout << "  i = " << i << ": prop = " << seg.tree[i].prop << ", mini = " << seg.tree[i].mini << '\n';
		}
	}

	return 0;
}
