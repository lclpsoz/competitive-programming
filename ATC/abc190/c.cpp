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

	int n, m;
	cin >> n >> m;
	vpii conditions(m);
	for (auto &[x, y] : conditions)
		cin >> x >> y;

	int k;
	cin >> k;
	vpii people(k);
	for (auto &[x, y] : people)
		cin >> x >> y;
	
	int ans = 0;
	vi dishs(n+1);
	for (int msk = 0; msk < (1<<k); msk++) {
		dishs.assign(n+1, 0);
		for (int i = 0; i < k; i++)
			if (msk&(1<<i))
				dishs[people[i].x]++;
			else
				dishs[people[i].y]++;
		int now = 0;
		for (auto [x, y] : conditions)
			now += (dishs[x] and dishs[y]);
		ans = max(ans, now);
	}
	cout << ans << '\n';

	return 0;
}
