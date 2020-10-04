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

ll a, b, x;

bool check(ll n, int digi) {
	// cout << "n = " << n << " digi = " << digi << '\n';
	ll ax = x-b*digi;
	if(ax <= 0) return false;
	ll maxi = ax/a;
	return n <= maxi;
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	cin >> a >> b >> x;
	ll mini = 1;
	ll ans = 0;
	for(int i = 1; i <= 10; i++) {
		ll l = mini, r = min(1000000000LL, mini*10 - 1);
		while(l < r) {
			// cout << l << ' ' << r << '\n';
			ll md = (l+r+1)/2;
			if(check(md, i)) {
				// cout << "TRUE!!!" << '\n';
				l = md;
			}
			else
				r = md-1;
		}
		if(check(l, i))
			ans = max(ans, l);
		mini *= 10;
	}
	cout << ans << '\n';

	return 0;
}
