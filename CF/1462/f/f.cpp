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
		vpii vec;
		vi compress;
		for (int i = 0; i < n; i++) {
			int l, r;
			cin >> l >> r;
			vec.push_back({l, r});
			compress.push_back(l);
			compress.push_back(r);
		}
		sort(ALL(compress));
		compress.resize(unique(ALL(compress)) - compress.begin());
		for (auto &[l, r] : vec) {
			l = (lower_bound(ALL(compress), l)-compress.begin()) + 1;
			r = (lower_bound(ALL(compress), r)-compress.begin()) + 1;
		}
		sort(ALL(vec));
		vi pref_l(LEN(compress)+10);
		vi pref_r(LEN(compress)+10);
		for (auto [l, r] : vec) {
			pref_l[l]++;
			pref_r[r]++;
		}
		for (int i = 1; i < LEN(pref_l); i++) {
			pref_l[i] = pref_l[i] + pref_l[i-1];
			pref_r[i] = pref_r[i] + pref_r[i-1];
		}
		int ans = 0;
		for (auto [l, r] : vec) {
			ans = max(ans, pref_l[r] - pref_r[l-1]);
			// cerr << "[" << l << ", " << r << "] = " << pref_l[r] << " - " << pref_r[l-1] << '\n';
		}
		cout << n - ans << '\n';
	}

	return 0;
}
