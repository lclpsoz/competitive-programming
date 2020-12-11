#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////



int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	int t;
	scanf("%d", &t);
	while(t--) {
		ll n;
		ll k;
		scanf("%lld %lld", &n, &k);
		int a, b, l, r;
		scanf("%d %d %d %d", &a, &b, &l, &r);
		ll ans = 0;
		if(a > l) swap(a, l), swap(b, r);
		else if(a == l and b > r) swap(a, l), swap(b, r);
		// Cost 0
		int cost0 = max(0, (min(b, r) - max(a, l)));
		k -= cost0*n;
		// printf("  a = %d, b = %d\n", a, b);
		// printf("    k = %lld\n", k);
		// Cost 1 & 2
		if(k > 0) {
			ll maxi = max(b, r) - min(a, l) - cost0;
			if(b >= l) {
				// No cost to make contact
				ans = min(k, maxi*n);
				k -= min(k, maxi*n);
				ans += 2*k;
			} else {
				// printf("here!\n");
				// Cost to make contact
				if(maxi*n >= k) {
					ll ansNow = 1e18;
					for(int i = 1; i <= n; i++) {
						ll costNow = 0;
						ll axK = k;
						costNow += i*1LL*(l-b) + min(k, i*maxi);
						axK -= min(k, i*maxi);
						if(axK > 0)
							costNow += 2*axK;
						// printf("  i = %d, costNow = %lld\n", i, costNow);
						ansNow = min(costNow, ansNow);
					}
					ans += ansNow;
				} else {
					ans = maxi*n + n*(l-b);
					k -= min(k, maxi*n);
					ans += 2*k;
					k = 0;
				}
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}
