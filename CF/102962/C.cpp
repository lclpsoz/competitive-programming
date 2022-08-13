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

	long long n;
	cin >> n;

	bool found = false;
	long long ans_i, ans_j, ans_k;
	for (int i = 0; i < 1e3; i++) {
		for (int j = 0; j < 1e3; j++) {
			for (int k = 0; k <= 1; k++) {
				int m = 7 * i + 3 * j;
				if ((m + 5 * k) % 10 == n % 10 && m + 5 * k <= n) {
					found = true;
					ans_i = i;
					ans_j = j;
					ans_k = (n - m) / 5;
				} 
			}
		}
	}	

	if (found) {
		cout << ans_j << " " << ans_k << " " << ans_i << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
