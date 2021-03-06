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

const int DBG = 1;

const int N = 2e5 + 10;

int n;
pii val[N];
int dp[N][8];
vi ax;

int solve(int p, int sz) {
	if(p == n-1) {
		if(sz < 2)
			return INF<int>;
		return val[p].x-val[p-sz].x;
	}
	int &ret = dp[p][sz];
	if(ret != -1) return ret;
	ret = INF<int>;
	if(sz < 4)
		ret = solve(p+1, sz+1);
	if(sz > 1)
		ret = min(ret, solve(p+1, 0) + val[p].x - val[p-sz].x);
	return ret;
}


void recu(int p, int sz) {
	if(p == n-1) return;
	int &ret = dp[p][sz];
	if(sz == 0)
		ax.push_back(p);
	if(sz < 4 and ret == solve(p+1, sz+1))
		recu(p+1, sz+1);
	else if(sz > 1 and ret == solve(p+1, 0) + val[p].x - val[p-sz].x)
		recu(p+1, 0);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	memset(dp, -1, sizeof dp);

	cin >> n;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		val[i] = {x, i};
	}
	sort(val, val+n);
	cout << solve(0, 0) << ' ';
	recu(0, 0);
	cout << LEN(ax) << '\n';
	int tm = 0;
	reverse(ALL(ax));
	vpii ans;
	for(int i = 0; i < n; i++) {
		if(LEN(ax) > 0 and ax.back() == i) ++tm, ax.pop_back();
		ans.push_back({val[i].y, tm});

	}
	// PRINT ANS
	sort(ALL(ans));
	for(int i = 0; i < n; i++)
		cout << ans[i].y << " \n"[i==n-1];

	return 0;
}
