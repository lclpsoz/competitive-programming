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
		int n, m;
		cin >> n >> m;
		map<int, int> mp;
		while (m--) {
			int r, c;
			cin >> r >> c;
			mp[c] |= 1<<(r-1);
		}
		
		vector<pii> vec;
		for (auto [c, msk] : mp) {
			vec.push_back({msk, c});
		}
		
		bool ans = true;
		for (int i = 0; i < LEN(vec); i++) {
			cerr << "i = " << i << '\n';
			if (vec[i].x == 3)
				continue;
			if (i == LEN(vec)-1 or vec[i+1].x == 3) {
				ans = false;
				break;
			}
			if ((vec[i].x == vec[i+1].x) != (vec[i+1].y-vec[i].y)%2) {
				ans = false;
				break;
			}
			++i;
		}
		cout << (ans ? "YES" : "NO") << '\n';
	}

	return 0;
}
