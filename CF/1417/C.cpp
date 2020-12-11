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

const int N = 3e5 + 10;

int mp[N];
int dist[N];
int ans[N];

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i <= n; i++) {
			mp[i] = dist[i] = 0;
			ans[i] = 1e9;
		}
		for(int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			if(mp[x]) {
				dist[x] = max(dist[x], i-mp[x]);
			} else
				dist[x] = i;
			mp[x] = i;
		}

		for(int i = 1; i <= n; i++) {
			if(mp[i])
				dist[i] = max(n+1-mp[i], dist[i]);
			ans[dist[i]] = min(ans[dist[i]], i);
		}

		for(int i = 1; i <= n; i++) {
			if(i > 1 and !ans[i]) ans[i] = ans[i-1];
			if(i > 1 and ans[i-1])
				ans[i] = min(ans[i], ans[i-1]);
			cout << (ans[i] == 1e9 ? -1 : ans[i]) << ' ';
		}
		cout << '\n';
	}

	return 0;
}
