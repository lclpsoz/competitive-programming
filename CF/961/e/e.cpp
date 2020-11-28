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

struct seg_tree {
	int n;
	vector<vi> seg;
	seg_tree(int _n, vi &vec) : n(_n) {
		seg = vector<vi>(4*n);
		build(1, 1, n, vec);
	}

	void build(int v, int tl, int tr, vi &vec) {
		// cerr << "build = " << v << ", " << tl << " " << tr << '\n';
		for(int i = tl-1; i < tr; i++)
			seg[v].push_back(vec[i]);
		sort(ALL(seg[v]));
		if(tl < tr) {
			int tm = (tl + tr)/2;
			build(2*v, tl, tm, vec);
			build(2*v+1, tm+1, tr, vec);
		}
	}

	int cnt_geq(int v, int tl, int tr, int l, int r, int val) {
		// cerr << "cnt_geq: " << v << '\n';
		if(l <= tl and tr <= r) {
			// cerr << "  qry: " << l << ", " << r << ", tl = " << tl << ", tr = " << tr << ": " << (LEN(seg[v]) - (int)(lower_bound(ALL(seg[v]), val) - seg[v].begin())) << '\n';
			return LEN(seg[v]) - (int)(lower_bound(ALL(seg[v]), val) - seg[v].begin());
		}
		else if(tl <= r and l <= tr) {
			int tm = (tl+tr)/2;
			return cnt_geq(2*v, tl, tm, l, r, val)
					+ cnt_geq(2*v+1, tm+1, tr, l, r, val);
		}
		return 0;
	}

	int cnt_geq(int l, int r, int val) {
		if(l <= r)
			return cnt_geq(1, 1, n, l, r, val);
		else
			return 0;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vi vec(n);
	ll ans = 0;
	for(int &v : vec)
		cin >> v;
	seg_tree seg(n, vec);

	for(int i = 1; i < n; i++)
		ans += seg.cnt_geq(i+1, min(vec[i-1], n), i);
	cout << ans << '\n';

	return 0;
}
