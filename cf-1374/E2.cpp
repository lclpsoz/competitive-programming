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

int n, k;
int both[N], a[N], b[N];

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d %d", &n, &k);
	vector<int> vec[3];
	for(int i = 0; i < n; i++) {
		int t, x, y;
		scanf("%d %d %d", &t, &x, &y);
		if(x == y and x == 1)
			vec[0].push_back(t);
		else if(x == 1 and y == 0)
			vec[1].push_back(t);
		else if(x == 0 and y == 1)
			vec[2].push_back(t);
	}
	for(int i = 0; i < 3; i++) {
		sort(vec[i].begin(), vec[i].end());
		reverse(vec[i].begin(), vec[i].end());
	}

	ll ans = 0;
	while(k) {
		// printf("ka = %d, kb = %d\n", ka, kb);
		if(ka and kb) {
			if(LEN(vec[0]) and LEN(vec[1]) and LEN(vec[2]) and
				vec[0].back() < vec[1].back()+vec[2].back()) {
				ans += vec[0].back();
				vec[0].pop_back();
			} else if(LEN(vec[0]) and LEN(vec[1]) and LEN(vec[2]) and
				vec[0].back() >= vec[1].back()+vec[2].back()) {
				ans += vec[1].back();
				ans += vec[2].back();
				vec[1].pop_back();
				vec[2].pop_back();

			}
			else if(LEN(vec[0])) {
				ans += vec[0].back();
				vec[0].pop_back();
			} else {
				if(LEN(vec[1]) == 0 or LEN(vec[2]) == 0) {
					printf("-1\n");
					exit(0);
				}
				ans += vec[1].back();
				ans += vec[2].back();
				vec[1].pop_back();
				vec[2].pop_back();
			}
			ka--, kb--;
		}
	}
	printf("%lld\n", ans);

	return 0;
}
