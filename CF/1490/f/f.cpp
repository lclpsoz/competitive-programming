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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi vec(n);
		map<int, int> mp, mp_2;
		for (int &x : vec) {
			cin >> x;
			mp[x]++;
		}
		for (auto [v, q] : mp)
			mp_2[q]++;
		vpii vals;
		for (auto [q, qq] : mp_2) {
			vals.push_back({q, qq});
			// cerr << "q = " << q << ", qq = " << qq << '\n';
		}
		ll rig = 0, cnt_rig = 0;
		ll lft = 0;
		for (int i = LEN(vals)-1; i; i--) {
			cnt_rig += vals[i].y;
			rig += (vals[i].x-vals.front().x)*vals[i].y;
		}
		cnt_rig += vals.front().y;
		ll ans = INF<ll> + 1;
		for (int i = 0; i < LEN(vals); i++) {
			cnt_rig -= vals[i].y;
			ans = min(ans, lft + rig);
			// cerr << "i = " << i << ", now = " << lft + rig << '\n';
			lft += vals[i].x*vals[i].y;
			if (i < LEN(vals)-1)
				rig -= cnt_rig*(vals[i+1].x-vals[i].x);
		}
		cout << ans << '\n';
	}

	return 0;
}
