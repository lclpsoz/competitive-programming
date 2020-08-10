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

int q;
int n;
int lst[1010];

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d", &q);
	vector<int> vec;
	while(q--) {
		vec.clear();
		scanf("%d", &n);

		memset(lst, -1, sizeof lst);
		for(int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			vec.push_back(x);
		}
		sort(vec.begin(), vec.end());
		int ans = 0;
		for(int i = 0; i < n; i++) {
			int now = 0;
			while(vec[i]-lst[now] == 1) ++now;
			lst[now] = vec[i];
			ans = max(ans, now+1);
		}
		printf("%d\n", ans);

	}

	return 0;
}
