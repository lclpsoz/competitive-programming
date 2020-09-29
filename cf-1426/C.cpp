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

int t, n;

int eval(int sum) {
	if(n == 1) return 0;
	int val = sum+1;
	int afterSum = n-val;
	// cout << sum << ": " << val << ' ' << afterSum << ", =" << sum + afterSum/val + (afterSum%val > 0) << '\n';
	return sum + afterSum/val + (afterSum%val > 0);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		cin >> n;
		
		if(n == 1)
			cout << 0 << '\n';
		else {
			int sq = sqrt(n);
			int bst = 1e9;
			for(int i = sq/2; i <= sq*2; i++)
				bst = min(bst, eval(i));
			cout << bst << '\n';
		}
	}

	return 0;
}
