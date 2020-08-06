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
		int m, d, w;
		scanf("%d %d %d", &m, &d, &w);
		int g = __gcd(d-1, w);
		w /= g;
		int mx = min(m, d);
		ll ans = 0;
		// Start
		ans = (mx%w)*1LL*((mx-1)/w);
		// printf("  %d %d %d\n", mx, w, mx%w);
		// printf("  ans = %lld\n", ans);
		ll base = ((mx-(1 + mx%w))/w);
		// if(mx%w == 0)
		// 	base--;
		ans += w*(base*(base+1))/2;
		// for(int x = 1; x <= mx; x++)
		// 	ans += (mx-x)/w;
		printf("%lld\n", ans);
	}

	return 0;
}
