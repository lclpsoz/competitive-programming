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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	cin >> n >> m;

	deque<int> dq;
	int sum = 0;
	for(int i = 0; i < 30; i++) {
		int x;
		cin >> x;
		dq.push_back(x);
		sum += x;
	}
	m-=n;
	int q = 0;
	int lst = -1;
	int ans = 0;
	while(m and q < 31) {
		int md = (sum/30) + (sum%30 > 0);
		m = max(0, m-md);
		if(md != lst) {
			lst = md;
			q = 0;
		}
		++q;
		++ans;
		sum += md;
		dq.push_back(md);
		sum -= dq.front();
		dq.pop_front();
	}
	if(m)
		ans += (m/lst) + (m%lst > 0);
	cout << ans << '\n';

	return 0;
}
