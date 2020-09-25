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

const int N = 2e5 + 10;

int t, n;
ll odd[N], even[N];
ll mini[2];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		cin >> n;
		ll acu0, acu1;
		acu0 = acu1 = 0;
		mini[0] = 1e9;
		mini[1] = 0;
		ll maxi = 0;
		for(int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if(i%2 == 0)
				acu0 += x;
			else
				acu1 += x;
			maxi = max(maxi, (acu1-acu0)-mini[i%2]);
			mini[i%2] = min(mini[i%2], acu1-acu0);
			// cout << "acu0 = " << acu0 << ", acu1 = " << acu1 << ", diff = " << acu1-acu0 << '\n';
			// cout << acu << ' ' << mini[i%2] << '\n';
		}

		cout << acu0+maxi << '\n';
	}

	return 0;
}
