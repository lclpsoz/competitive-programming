#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

ll eval(ll x, ll qnt) {
	ll k = qnt-1;
	// printf("x = %d, k = %d, ret = %lld\n", x, k, ((k+2)*1LL*(k+1))/2 + (k+1)*1LL*(x-k-1));
	return ((k+2)*(k+1))/2 + (k+1)*(x-k-1);
}

int main () {
	ll n, k;
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%lld %lld", &n, &k);

	ll maxi = 1 + ((k-1)*k)/2;
	// printf("%lld\n", maxi);
	if(n == 1)
		printf("0\n");
	else if(n > maxi)
		printf("-1\n");
	else {
		n -= k;
		k -= 2;
		ll l = 0, r = k;
		while(l < r) {
			ll md = (l+r)/2;
			if(eval(k, md) >= n)
				r = md;
			else
				l = md+1;
		}
		printf("%lld\n", l+1);
	}

	return 0;
}
