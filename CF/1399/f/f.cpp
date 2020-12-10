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

const int N = 6005;

vi intervals[N];
int dp[N][N];

int solve (int l, int r) {
	// cerr << "l = " << l << ", r = " << r << '\n';
	if (l > r) return 0;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	if (LEN(intervals[l])) {
		auto it = lower_bound(ALL(intervals[l]), r);
		if (it == intervals[l].end() or (it != intervals[l].begin() and *it > r)) --it;
		while (l <= *it and *it <= r) {
			ret = max(ret, solve(l, *it-1) + solve(*it+1, r) + 1);
			if (it != intervals[l].begin())
				--it;
			else
				break;
		}
	}
	ret = max(ret, solve(l+1, r));
	ret = max(ret, solve(l, r-1));
	// cerr << "  l = " << l << ", r = " << r << ", ret = " << ret << '\n';
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	vector<pair<pii, int>> spread;
	while (t--) {
		spread.clear();
		int n;
		cin >> n;
		vpii vec(n+1);
		for (int i = 1; i <= n; i++) {
			auto &[x, y] = vec[i];
			cin >> x >> y;
			spread.push_back({{x, -y}, -i}); // Start first ones that ends last
			spread.push_back({{y, -x}, i}); // Ends first who started last
		}
		sort(ALL(spread));
		int lst_coord_val = 1;
		for (auto &[coord, i] : spread) {
			coord.x = lst_coord_val++;
			if (i < 0)
				vec[-i].x = coord.x;
			else
				vec[i].y = coord.x;
		}
		for (int i = 0; i <= lst_coord_val+1; i++)
			intervals[i].clear();
		// cerr << '\n';
		for (int i = 1; i <= n; i++) {
			auto [l, r] = vec[i];
			// cerr << "[" << l << ", " << r << "]\n";
			intervals[l].push_back(r);
		}

		for (int i = 0; i <= lst_coord_val+1; i++) {
			sort(ALL(intervals[i]));
			for (int j = 0; j <= lst_coord_val+1; j++)
				dp[i][j] = -1;
		}

		cout << solve (0, lst_coord_val+1) << '\n';
	}

	return 0;
}
