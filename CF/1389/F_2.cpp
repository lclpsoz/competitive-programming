#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

struct seg_tree {
	int n;
	vi t;
	
	seg_tree(int _n) {
		n = _n;
		t = vi(4*n);
	}

	int get(int idx, int tl, int tr, int l, int r) {
		if(l <= tl and tr <= r)
			return t[idx];
		else if(tl <= r and l <= tr) {
			int tm = (tl+tr)/2;
			return max(	get(2*idx, tl, tm, l, r),
						get(2*idx+1, tm+1, tr, l, r));
		}
		return 0;
	}

	void upd(int idx, int tl, int tr, int pos, int val) {
		if(tl == tr and tl == pos)
			t[idx] = val;
		else if(tl <= pos and pos <= tr) {
			int tm = (tl+tr)/2;
			upd(2*idx, tl, tm, pos, val);
			upd(2*idx+1, tm+1, tr, pos, val);
			t[idx] = max(t[2*idx], t[2*idx+1]);
		}
	}

	int get(int l, int r) {
		return get(1, 1, n, l, r);
	}

	void upd(int pos, int val) {
		return upd(1, 1, n, pos, val);
	}
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vector<pair<pii, bool>> vec;
	vi all_vals;
	for(int i = 0; i < n; i++) {
		int l, r, t;
		cin >> l >> r >> t;
		all_vals.push_back(l);
		all_vals.push_back(r);
		t--;
		vec.push_back({{r, l}, t});
	}
	sort(ALL(all_vals));
	all_vals.resize(unique(ALL(all_vals)) - all_vals.begin());
	sort(ALL(vec));
	vi t0_r, t1_r;
	for(auto &[iter, t] : vec) {
		iter.x = (int)(lower_bound(ALL(all_vals), iter.x)-all_vals.begin())+1;
		iter.y = (int)(lower_bound(ALL(all_vals), iter.y)-all_vals.begin())+1;
		if(t)
			t1_r.push_back(iter.x);
		else
			t0_r.push_back(iter.x);
		// cout << iter.y << ' ' << iter.x << '\n';
	}
	seg_tree t0l(LEN(all_vals)+10), t1l(LEN(all_vals)+10);
	seg_tree t0r(LEN(all_vals)+10), t1r(LEN(all_vals)+10);
	for(auto [iter, t] : vec)
		if(t) {
			auto [r, l] = iter;
			// cout << r << ' ' << l << '\n';
			int pos_l = (int)(lower_bound(ALL(t0_r), l)-t0_r.begin())+1;
			int ans = t1l.get(1, pos_l)+1;
			ans = max(ans, t0r.get(1, l-1)+1);
			t1l.upd(pos_l, ans);
			t1r.upd(r, ans);
		} else {
			auto[r, l] = iter;
			int pos_l = (int)(lower_bound(ALL(t1_r), l)-t1_r.begin())+1;
			int ans = t0l.get(1, pos_l)+1;
			ans = max(ans, t1r.get(1, l-1)+1);
			t0l.upd(pos_l, ans);
			t0r.upd(r, ans);
		}

	cout << max(t0l.get(1, t0l.n), t1l.get(1, t1l.n)) << '\n';

	return 0;
}
