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

const int N = 2e5 + 10;

int n, q;
int segs[2][4*N];

void upd(int *seg, int p, int val, int node, int l, int r) {
	if(l <= p and p <= r) { 
		seg[node] = max(val, seg[node]);
		if(l < r) {
			int node_l = 2*node;
			int node_r = 2*node+1;
			upd(seg, p, val, node_l, l, (l+r)/2);
			upd(seg, p, val, node_r, (l+r)/2 + 1, r);
		}
	}
}

int qry(int *seg, int val, int node, int l, int r) {
	if(seg[node] >= val) { 
		if(l < r) {
			int node_l = 2*node;
			int node_r = 2*node+1;
			int ret = qry(seg, val, node_l, l, (l+r)/2);
			if(ret)
				return ret;
			return qry(seg, val, node_r, (l+r)/2 + 1, r);
		} else
			return l;
	} else
		return 0;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> q;
	ll ans = 0;
	upd(segs[0], n, n, 1, 1, n);
	upd(segs[1], n, n, 1, 1, n);
	while(q--) {
		int opt, x;
		cin >> opt >> x;
		if(opt == 1) {
			int maxi = qry(segs[0], x, 1, 1, n);
			maxi--;
			// cout << "maxi = " << maxi << '\n';
			ans += maxi-1;
			upd(segs[1], x, maxi, 1, 1, n);
		}
		else {
			int maxi = qry(segs[1], x, 1, 1, n);
			maxi--;
			// cout << "maxi = " << maxi << '\n';
			ans += maxi-1;
			upd(segs[0], x, maxi, 1, 1, n);
		}
	}
	cout << (n-2)*1ll*(n-2) - ans << '\n';

	return 0;
}
