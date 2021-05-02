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

	vector<vi> mat(32, vi(32));

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				cin >> mat[i][j];
		vector<pair<pii, int>> vec;
		vec.push_back({{1, 1}, 1});
		vpii level(70);
		set<pii> vis;
		for (int i = 0; i < LEN(vec); i++) {
			auto [xy, lvl] = vec[i];
			if (vis.count(xy)) continue;
			vis.insert(xy);
			auto [x, y] = xy;
			if (mat[x][y])
				level[lvl].y++;
			else
				level[lvl].x++;
			if (x < n)
				vec.push_back({{x+1, y}, lvl+1});
			if (y < m)
				vec.push_back({{x, y+1}, lvl+1});
		}
		int ln = n+m-1;
		int ans = 0;
		for (int i = 1; i <= ln/2; i++) {
			pii now = level[i];
			now.x += level[ln-i+1].x;
			now.y += level[ln-i+1].y;
			ans += min(now.x, now.y);
		}
		cout << ans << '\n';
	}

	return 0;
}
