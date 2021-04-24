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
	while(cin >> n >> m)
	{
		vector<ll> msk(n, 0);
		for(int i = 0; i < n; i++)
		{
			int k; cin >> k;
			while(k--)
			{
				int j; cin >> j;
				msk[i] |= 1LL << --j;
			}
		}

		int ans = (1 << n) - 1;

		for(int i = 0; i < (1 << n); i++)
		{
			ll now = 0;
			for(int j = 0; j < n; j++)
				if((1 << j) & i)
					now |= msk[j];

			if(now + 1 == (1LL << m))
				if(__builtin_popcount(i) < __builtin_popcount(ans))
					ans = i;
		}
		cout << __builtin_popcount(ans) << endl;
		for(int i = 0; i < n; i++)
			if(ans & (1 << i))
				cout << i + 1 << " ";
	}


	return 0;
}
