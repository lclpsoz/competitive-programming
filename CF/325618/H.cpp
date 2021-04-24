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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int k;
	cin >> k;
	string s;
	cin >> s;
	int i = 0, j = 0;
	int count = 0;
	int ans = 0;
	int final_i, final_j;
	vector<int> vis(26, 0);
	while (j < s.size()) {
		if (vis[s[j] - 'a'] == 0)
			count++;
		vis[s[j] - 'a']++;
		j++;
		while (count > k) {
			vis[s[i] - 'a']--;
			if (vis[s[i] - 'a'] == 0)
				count--;
			i++;
		}
		if (j - i > ans) { 
			ans = max(ans, j - i);
			final_i = i;
			final_j = j;
		}
	}
	cout << final_i + 1 << " " << final_j << endl;

	return 0;
}
