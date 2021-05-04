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

	int n;
	cin >> n;
	map<int, pii> mp;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		x*=2;
		if (!mp.count(y))
			mp[y] = {INF<int>, -INF<int>};
		mp[y].x = min(mp[y].x, x);
		mp[y].y = max(mp[y].y, x);
	}
	vector<pair<int, pii>> events;
	events.push_back({0, {0, 0}});
	for (auto &[value, pp] : mp) {
		events.push_back({value, pp});
	}
	events.push_back({n+1, {0, 0}});
	ll ans = 0;
	ll pos = 0;
	for (int i = 0; i < LEN(events); i++) {
		pair<ll, ll> now = events[i].y;
		pair<ll, ll> aft = events[i+1].y;
		ll md_now = (now.x+now.y)/2;
		ll md_aft = (aft.x+aft.y)/2;
		if (pos < now.x) {
			ans += now.x-pos;
			pos = now.x;
		}
		else if (now.y < pos) {
			ans += pos - now.y;
			pos = now.y;
		}
		if (md_now <= md_aft) {
			ans += pos-now.x;
			ans += now.y-now.x;
			pos = now.y;
		}
		else { // md_aft < md_now
			ans += now.y-pos;
			ans += now.y-now.x;
			pos = now.x;
		}
		cerr << "i = " << i << ", now = {" << now.x << ", " << now.y << "}\n";
		cerr << "i = " << i << ", pos = " << pos << ", ans = " << ans << '\n';
	}
	cout << ans/2 << '\n';

	return 0;
}
