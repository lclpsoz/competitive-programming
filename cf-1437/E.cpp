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

const int N = 5e5 + 10;

int n, k;
int a[N], b[N];
int mn[N], mx[N];

void no() {
	cout << "-1\n";
	exit(0);
}

ll cost_lis(int l, int r) {
	// cout << "l, r = " << l << ", " << r << '\n';
	vi lis;
	for(int i = l; i <= r; i++) {
		mn[i] = a[l]+(i-l);
		mx[i] = a[r]-(r-i);
		// cout << "    i(" << i << ") = " << mn[i] << ", " << mx[i] << "\n";
	}
	if(mx[l] < a[l] or a[r] < mn[r])
		no();

	for(int i = l+1; i < r; i++)
		if(mn[i] <= a[i] and a[i] <= mx[i]) {
			int val = a[i]-mn[i];
			// cout << "  i = " << i << ", val = " << val << '\n';
			if(LEN(lis) == 0)
				lis.push_back(val);
			else {
				int pos = (upper_bound(ALL(lis), val)-lis.begin());
				if(pos == 0)
					lis[0] = val;
				else if(pos == LEN(lis))
					lis.push_back(val);
				else
					lis[pos] = val;
			}
		}
	// cout << "  |lis| = " << LEN(lis) << '\n';
	return r-l-1-LEN(lis);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	for(int i = 0; i < k; i++)
		cin >> b[i];
	
	ll ans = 0;
	a[n+1] = 1e9+N;
	a[0] = -1e9-N;
	if(k) {
		if(b[0] > 1)
			ans += cost_lis(0, b[0]);
		for(int i = 1; i < k; i++)
			ans += cost_lis(b[i-1], b[i]);
		if(b[k-1] < n)
			ans += cost_lis(b[k-1], n+1);
	} else {
		ans = cost_lis(0, n+1);
	}
	cout << ans << '\n';

	return 0;
}
