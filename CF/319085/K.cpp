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

	int n;
	cin >> n;
	vector<int> loot(n);
	for (int i = 0; i < n; i++) {
		cin >> loot[i];
	}
	multiset<int> jack_loot;
	long long jack_sum, fer_sum;
	jack_sum = fer_sum = 0;
	for (int i = 0; i < n;) {
		if (i + 1 < n) {
			if (loot[i] < loot[i + 1]) {
				int tmp = loot[i];
				loot[i] = loot[i + 1];
				loot[i + 1] = tmp;
			}

			jack_loot.insert(loot[i]);

			if (loot[i + 1] > *jack_loot.begin()) {
				jack_loot.erase(jack_loot.begin());
				jack_loot.insert(loot[i + 1]);
			}
		}
		else {
			jack_loot.insert(loot[i]);
			break;
		}
		i++;
		fer_sum += loot[i];
		i++;
	}

	cout << accumulate(loot.begin(), loot.end(), 0ll) - fer_sum << " " << fer_sum << endl;

	return 0;
}
