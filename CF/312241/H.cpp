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

	int n, g;
	cin >> n >> g;
	vi p(n);
	for(int& i : p) cin >> i;
	int total = accumulate(ALL(p), 0);
	vi sum(1 << n, 0);
	int m = n;
	for(int msk = 1; msk < (1 << n); msk++)
	{
		int r = __builtin_ctz(msk);
		sum[msk] = sum[msk ^ (1 << r)] + p[r];
		if(100 * sum[msk] / total >= g)
			m = min(m, __builtin_popcount(msk));
	}
	vi ans;
	for(int msk = 1; msk < (1 << n); msk++)
		if(__builtin_popcount(msk) == m && 100 * sum[msk] / total >= g)
			ans.emplace_back(msk);

	cout << m << " " << LEN(ans) << endl;
	for(int msk : ans)
	{
		cout << 100 * sum[msk] / total;
		for(int i = 0; i < n; i++)
			if(msk & (1 << i)) cout << " " << i + 1;
		cout << '\n';
	}

	return 0;
}
