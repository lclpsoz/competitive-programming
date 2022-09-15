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

int solve(int n) {
	int ans = 1e9;
	for (ll p2 = 1; p2 <= 4e18; p2*=2) {
		string str_n = to_string(n);
		string str_p2 = to_string(p2);
		reverse(str_n.begin(), str_n.end());	
		reverse(str_p2.begin(), str_p2.end());	

		int cost = 0;
		while (LEN(str_n) && LEN(str_p2)) {
			if (str_n.back() == str_p2.back())
				str_p2.pop_back();
			else
				cost++;
			str_n.pop_back();
		}
		cost += LEN(str_p2) + LEN(str_n);
		ans = min(cost, ans);
	}
	return ans;
}

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
		cout << solve(n) << '\n';
	}

	return 0;
}
