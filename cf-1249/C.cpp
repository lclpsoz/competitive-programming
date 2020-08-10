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

ll po3[100];
bool vis[100];

ll eval(ll msk) {
	ll ret = 0;
	for(int i = 0; i < 40; i++)
		if(msk&(1LL<<i)) {
			ret += po3[i];
		}
	return ret;
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	int q;
	ll n;
	scanf("%d", &q);
	vector<ll> vec;
	ll th = 1;
	int lstPo3 = 0;
	ll ax = 0;
	for(int i = 0; i < 40; i++) {
		ax += th;
		// printf("%d: %lld\t%lld\n", i, th, ax);
		po3[i] = th;
		th*= 3;
		lstPo3 = i;
	}
	for(int i = 0; i < (1<<10); i++) {
		ll now = 0;
		for(int j = 0; j < 10; j++)
			if((1<<j)&i) {
				now += po3[j];
			}
		vec.push_back(now);
	}
	sort(ALL(vec));
	for(int i = 1; i < LEN(vec); i++) {
		// printf("%d\t%d\t", vec[i], vec[i]-vec[i-1]);
		// cout << bitset<10>(i) << '\n';
	}

	while(q--) {
		scanf("%lld", &n);
		memset(vis, 0, sizeof vis);
		ll total = 0;
		ll l = 1, r = (1LL<<40);
		while(l < r) {
			ll md = (l+r)/2;
			if(eval(md) < n)
				l = md+1;
			else
				r = md;
			// printf("%lld %lld\n", l, r);
		}
		printf("%lld\n", eval(l));
		// while(total < n and !vis[0]) {
		// 	for(int i = 0; i < lstPo3; i++) {
		// 		if(total + po3[i] >= n) {
		// 			int pos = i-1;
		// 			while(pos >= 0 and vis[pos]) --pos;
		// 			vis[pos] = true;
		// 			total += po3[pos];
		// 			break;
		// 		}
		// 	}
		// 	printf("total = %lld\n", total);
		// }
		// if(total < n) {
		// 	for(int i = 0; i < lstPo3; i++)
		// 		if(!vis[i]) {
		// 			total += po3[i];
		// 			break;
		// 		}
		// }
		// printf("%lld\n", total);
	}

	return 0;
}
