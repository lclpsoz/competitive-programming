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

const int N = 1e5 + 10;

int n, m;
int dp[N];
string s;

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> n >> m;
	cin >> s;
	deque<int> avail;
	avail.push_back(n);
	for(int i = n-1; i >= 0; i--) {
		if(LEN(avail) and avail.back()-i > m) avail.pop_back();
		if(s[i] == '0') {
			if(LEN(avail)) {
				dp[i] = dp[avail.back()]+1;
				avail.push_front(i);
			}
			else
				dp[i] = -1;
		}
		else
			dp[i] = -1;
	}
	// for(int i = 0; i <= n; i++)
	// 	cout << dp[i] << " \n"[i==n];
	vector<int> ans;
	int val_now = dp[0];
	if(val_now == -1)
		cout << "-1\n";
	else {
		for(int i = 0; i <= n; i++)
			if(dp[i] == val_now) {
				ans.push_back(i);
				val_now--;
			}
		for(int i = 1; i < LEN(ans); i++) {
			assert(ans[i]-ans[i-1] <= m);
			cout << ans[i]-ans[i-1] << " \n"[i==LEN(ans)-1];
		}
	}

	return 0;
}
