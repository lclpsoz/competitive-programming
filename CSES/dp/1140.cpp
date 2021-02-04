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

int n;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n;
	vi vals;
	vector<pair<pii, int>> inp;
	while (n--) {
		int a, b, p;
		cin >> a >> b >> p;
		vals.push_back(a);
		vals.push_back(b);
		inp.push_back({{a, b}, p});
	}
	sort(ALL(vals));
	vals.resize(unique(ALL(vals)) - vals.begin());

	vector<vector<pii>> intervals(4e5 + 10);
	vi joker(4e5 + 10);
	for (auto [ab, p] : inp) {
		auto [a, b] = ab;
		a = lower_bound(ALL(vals), a) - vals.begin() + 1;
		b = lower_bound(ALL(vals), b) - vals.begin() + 1;
		// cerr << "[" << a << ", " << b << "] -> " << p << '\n';
		intervals[b].push_back({a, p});
	}

	vector<ll> dp(4e5 + 10);

	for (int i = 1; i < 4e5 + 10; i++) {
		for (auto [l, p] : intervals[i])
			dp[i] = max(dp[i], dp[l-1] + p);
		dp[i] = max(dp[i], dp[i-1]);
		// if (i < 15)
		// 	cerr << "dp[" << i << "] = " << dp[i] << '\n';
	}
	cout << *max_element(ALL(dp)) << '\n';

	return 0;
}
