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

vpii sq(4);
vi cnt(4);
vi vals_x(4), vals_y(4);
vpii pts(4);

ll eval(int sz) {
	ll ret = 0;
	sq[1].x = sz;
	sq[2].x = sz;
	sq[2].y = sz;
	sq[3].y = sz;
	for(int i = 0; i < 4; i++) {
		vals_x[i] = sq[i].x-pts[i].x;
		vals_y[i] = sq[i].y-pts[i].y;
	}
	sort(ALL(vals_x));
	sort(ALL(vals_y));
	int delta_x = 0;
	int delta_y = 0;
	if(vals_x[2] < 0)
		delta_x += vals_x[2];
	if(vals_x[1] > 0)
		delta_x += vals_x[1];
	if(vals_y[2] < 0)
		delta_y += vals_y[2];
	if(vals_y[1] > 0)
		delta_y += vals_y[1];
	for(int i = 0; i < 4; i++)
		ret += abs(vals_x[i]-delta_x) + abs(vals_y[i]-delta_y);

	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		for(auto &[x, y] : pts)
			cin >> x >> y;
		// cerr << "l = " << l << '\n';
		sort(ALL(pts));
		ll ans = INF<ll>;
		do {
			int l = 0, r = INF<int>;
			while(l < r) {
				int md = (l+r)/2;
				if(eval(md) > eval(md+1))
					l = md+1;
				else
					r = md;
			}
			ans = min(ans, eval(l));
		} while(next_permutation(ALL(pts)));
		cout << ans << '\n';
	}

	return 0;
}
