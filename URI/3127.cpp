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
	cout.precision(6);

	int n;
	cin >> n;
	if (n <= 2) {
		cout << "0\n";
		exit(0);
	}
	ld ans = 0;
	vector<pair<pii, int>> vec(n);
	for (auto &[xy, t] : vec) {
		auto &[x, y] = xy;
		cin >> x >> y >> t;
	}
	sort(ALL(vec), [&](auto lft, auto rht) {
		return lft.y < rht.y;
	});
	reverse(ALL(vec));
	vec.push_back({{-1, -1}, -1});
	reverse(ALL(vec));
	vector<vector<ld>> speed(1010, vector<ld>(1010, 0));
	for (int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++) {
			ld dt = vec[j].y-vec[i].y;
			ll dx = vec[j].x.x-vec[i].x.x;
			ll dy = vec[j].x.y-vec[i].x.y;
			speed[i][j] = sqrt(dx*dx + dy*dy)/dt;
		}

	vector<bitset<1010>> vis(1010);
	set<pair<ld, pii>> dij;
	dij.insert({0, {0, 1}});
	while (LEN(dij)) {
		auto [spd, positions] = *dij.begin();
		auto [p1, p2] = positions;
		// cerr << "p1 = " << p1 << ", p2 = " << p2 << ", spd = " << spd << '\n';
		dij.erase(dij.begin());
		if (vis[p1][p2]) continue;
		vis[p1][p2] = 1;
		if (p2 == n) {
			cout << fixed << spd << '\n';
			exit(0);
		}
		dij.insert({max(spd, speed[p2][p2+1]), {p1, p2+1}});
		dij.insert({max(spd, speed[p1][p2+1]), {p2, p2+1}});
	}

	return 0;
}
