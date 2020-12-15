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

int ans_max (vi positions) {
	vi used(LEN(positions)+2);

	for (int i = 1; i < LEN(positions); i++)
		if (positions[i] >= 3)
			used[i-1] = used[i] = used[i+1] = 1;

	for (int i = 1; i < LEN(positions); i++)
		if (positions[i] == 1) {
			if (used[i-1] == 0)
				used[i-1] = 1;
			else if(used[i] == 0)
				used[i] = 1;
			else
				used[i+1] = 1;
		}
		else if (positions[i] == 2) {
			if (used[i-1] == 0) {
				used[i-1] = 1;
				positions[i]--;
			}
			if (used[i] == 0) {
				used[i] = 1;
				positions[i]--;
			}
			if (positions[i] and !used[i+1])
				used[i+1] = 1;
		}

	int ans = 0;
	for (int i = 0; i < LEN(used); i++)
		ans += used[i]>0;
	return ans;
}

int ans_min (vi cnt) {
	int n = LEN(cnt)-1;
	for (int i = 1; i <= n; i++)
		if (cnt[i]) {
			if (cnt[i-1] > 0)
				cnt[i] = 0;
			else if (i < n and !cnt[i-1]) {
				cnt[i+1] = 1;
				cnt[i] = -1;
			}
		}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += cnt[i]>0;
	return ans;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vi cnt(n+1);
	while (n--) {
		int v;
		cin >> v;
		cnt[v]++;
	}
	cout << ans_min(cnt) << ' ' << ans_max(cnt) << '\n';

	return 0;
}
