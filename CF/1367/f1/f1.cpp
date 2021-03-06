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

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi vec(n);
		for(int &v : vec)
			cin >> v;
		vi sorted = vec;
		sort(ALL(sorted));
		for(int i = 0; i < n; i++)
			vec[i] = lower_bound(ALL(sorted), vec[i])-sorted.begin();
		vi lis(n+1, 1);
		vi val_idx(n+1);
		for(int i = 0; i < n; i++)
			val_idx[vec[i]] = i;
		for(int i = 0; i < n; i++)
			if(vec[i] and val_idx[vec[i]-1] < i)
				lis[i] = lis[val_idx[vec[i]-1]]+1;

		cout << n-*max_element(ALL(lis)) << '\n';
	}

	return 0;
}
