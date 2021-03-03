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

bitset<1010> msk, ax;
bool is_valid;

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
		vector<string> a(n), b(n);
		for (string &s : a)
			cin >> s;
		for (string &s : b)
			cin >> s;
		msk.reset();
		is_valid = true;
		for (int i = 0; is_valid and i < n; i++) {
			// cerr << "i = " << i << '\n';
			if (i == 0) {
				for (int j = 0; j < n; j++)
					msk[j] = a[i][j] != b[i][j];
			}
			else {
				ax.reset();
				for (int j = 0; j < n; j++)
					ax[j] = a[i][j] != b[i][j];
				if (ax != msk) {
					for (int j = 0; j < n; j++)
						if (ax[j] == msk[j])
							is_valid = false;
				}
			}
		}
		cout << (is_valid ? "YES" : "NO") << '\n';
	}

	return 0;
}
