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
	// ios_base::sync_with_stdio(false);
	// cin.tie(NULL);
	// cout.precision(10);

	int n;
	cin >> n;
	map<char, int> mp;
	vector<char> choice(n);
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		mp[c]++;
		choice[i] = c;
	}
	vector<int> point(n);
	int maxi = -1e9;
	for (int i = 0; i < n; i++) {
		if (choice[i] == 'R') {
			point[i] = mp['S'] - mp['P'];
		} else if (choice[i] == 'S') {
			point[i] = mp['P'] - mp['R'];
		} else {
			point[i] = mp['R'] - mp['S'];
		}
		maxi = max(maxi, point[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (point[i] == maxi);
	}
	cout << ans << endl;

	return 0;
}
