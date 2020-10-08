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


class seg_tree {
private:
	const ll INF = 1e16;
	int n;
	vector<ll> tree;

	void _set_val(int v, int pos, int tl, int tr, ll val) {
		if(tl == tr and tl == pos)
			tree[v] = val;
		else if(tl <= pos and pos <= tr) {
			int tm = (tl+tr)/2;
			_set_val(2*v, pos, tl, tm, val);
			_set_val(2*v+1, pos, tm+1, tr, val);
			tree[v] = max(tree[2*v], tree[2*v+1]);
		}
	}

	ll _get_max(int v, int l, int r, int tl, int tr) {
		if(l <= tl and tr <= r)
			return tree[v];
		else if(l <= tr and tl <= r) {
			int tm = (tl+tr)/2;
			return max(	_get_max(2*v, l, r, tl, tm),
						_get_max(2*v+1, l, r, tm+1, tr));
		}
		return -INF;
	}

public:
	seg_tree(int _n) {
		n = _n;
		tree = vector<ll>(4*n);
	}

	ll get_max(int l, int r) {
		return _get_max(1, l, r, 1, n);
	}

	void set_val(int pos, ll val) {
		_set_val(1, pos, 1, n, val);
	}
};

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	int n;
	cin >> n;

	vi h(n);
	seg_tree seg(n);

	for(int i = 0; i < n; i++)
		cin >> h[i];
	for(int i = 0; i < n; i++) {
		int value;
		cin >> value;
		ll maxi = seg.get_max(1, h[i])+value;
		// cout << i << ' ' << value << ", maxi = " << maxi << '\n';
		seg.set_val(h[i], maxi);
	}

	cout << seg.get_max(1, n) << '\n';

	return 0;
}
