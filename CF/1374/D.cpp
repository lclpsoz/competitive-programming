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

const int N = 2e5 + 10;

int t;
int n, k, a[N];
map<int, int> mp;
vector<pii> vec;

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d", &t);
	while(t--) {
		mp.clear();
		vec.clear();
		scanf("%d %d", &n, &k);
		ll ans = 0;
		int acu = 0;
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			if((k - x%k)%k)
				mp[k - x%k]++, acu++;
		}
		int x = 0;
		while(acu) {
			// printf("acu = %d, x = %d, ans = %d\n", acu, x, ans);
			if(mp.count(x)) {
				// printf("  here!\n");
				mp[x]--;
				if(mp[x] == 0)
					mp.erase(x);
				--acu;
				x = (x+1)%k;
				++ans;
			} else {
				auto it = mp.lower_bound(x);
				if(it == mp.end()) {
					ans += k-x;
					x = 0;
				} else {
					ans += (it->x)-x;
					x = it->x;
				}
			}
		}
		printf("%lld\n", ans);
		// for(auto p : mp)
		// 	vec.push_back(p);
		// mp.clear();
		// for(auto p : vec)
		// 	mp[p.y]++;
		// int maxiQnt = 0;
		// int maxiQntVal = 0;
		// for(auto p : mp)
		// 	if(p.x > maxiQnt) {
		// 		maxiQnt = p.x;
		// 	}
		// for(auto p : vec)
		// 	if(p.y == maxiQnt)
		// 		maxiQntVal = max(maxiQntVal, p.x);
		// printf("%d %d\n", maxiQnt, maxiQntVal);

		
		// printf("%d\n", (maxiQnt-1)*(k-1) + maxiQntVal);
	}

	return 0;
}
