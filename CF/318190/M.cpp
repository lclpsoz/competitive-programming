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

	int n; cin >> n;
	vi k1, k2;
	for(int i = 0; i < n; i++)
	{
		ll s, a;
		cin >> s >> a;
		if(s < 0)
			k1.emplace_back(a * s);
		else
			k2.emplace_back(a * s);
	}
	sort(ALL(k1));
	sort(ALL(k2));
	int m; cin >> m;
	while(m--)
	{
		int x; cin >> x;
		int ans = 0;

		if(!empty(k1))
		{
			auto it1 = lower_bound(ALL(k1), x);
			ans += int(k1.end() - it1);
		}
		if(!empty(k2))
		{
			auto it2 = upper_bound(ALL(k2), x);
			ans += int(it2 - k2.begin());
		}

		cout << ans << endl;
	}

	return 0;
}
