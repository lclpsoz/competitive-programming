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
	int ret = x%m;
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
		// map<int, pii> mini_x;
		map<int, vector<pii>> mp;
		for (int i = 1; i <= n; i++) {
			int x, y;
			cin >> x >> y;
			// mini_x[x] = {INF<int>, -1};
			// mini_x[y] = {INF<int>, -1};
			mp[x].push_back({y, i});
			mp[y].push_back({x, i});
		}
		pii mini = {INF<int>, -1};
		pii mini2 = {INF<int>, -1};
		vi ans(n+1, -1);
		for (auto [x, vec] : mp) {
			// mini_x[x] = mini;
			sort(ALL(vec));
			for (auto [y, idx] : vec) {
				if (mini.y == idx) {
					if (mini2.x < y)
						ans[idx] = mini2.y;
				}
				else if (mini.x < y)
					ans[idx] = mini.y;
			}
			if (vec[0].x < mini.x) {
				if (mini.x < mini2.x)
					mini2 = mini;
				mini = vec[0];
			}
			if (LEN(vec) > 1 and vec[1].x < mini2.x)
				mini2 = vec[1];
		}

		for (int i = 1; i <= n; i++)
			cout << ans[i] << " \n"[i==n];
	}

	return 0;
}
