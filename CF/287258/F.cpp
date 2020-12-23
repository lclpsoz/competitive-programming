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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		vector<int> count(5);
		for (int i = 0; i < 7; i++) {
			char c;
			cin >> c;
			count[c - 'A']++;
		}
		bool ans = true;
		for (int i = 0; i < 5; i++) {
			if (!count[i]) {
				if (i == 0) {
					ans = false;
				} else if (i == 1) {
					if (count[0] > 2) {
						count[0] -= 2;
						count[1]++;
					} else
						ans = false;
				} else if (i == 2) {
					if (count[0] > 1 && count[1] > 1) {
						count[0]--, count[1]--;
						count[2]++;
					} else if (count[0] > 3) {
						count[0] -= 3;
						count[2]++;
					} else
						ans = false;
				} else if (i == 3) {
					if (count[0] > 1 && count[2] > 1) {
						count[0]--, count[2]--;
						count[3]++;
					} else if (count[0] > 4) {
						count[0] -= 4;
						count[3]++;
					} else
						ans = false;
				} else if (i == 4) {
					if ((count[1] > 1 && count[2] > 1) || (count[0] > 1 && count[3] > 1))
						;
					else
						ans = false;
				}
			}
		}
		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}


	return 0;
}
