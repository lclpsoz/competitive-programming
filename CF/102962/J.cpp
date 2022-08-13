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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 4e5 + 10;
int dp[N][2];
vi nxt[26];
int n;
string s;

int solve(int i, bool k) {
	if(i == n) return 0;

	int& ans = dp[i][k];

	if(ans == -1) {
		ans = -INF<int>;
		int c = s[i] - 'a';

		if(k) ans = max(ans, 1 + solve(i + 1, false));
		auto it = upper_bound(ALL(nxt[c]), i);
		if(it != nxt[c].end()) {
			ans = max(ans, solve(*it, true));
		}
	}

	return ans;
}

vpii sub;
void rec(int i, bool k) {
	if(i == n) {
		sub.pop_back();
		return;
	}

	int c = s[i] - 'a';

	if(k) {
		if(solve(i, k) == 1 + solve(i + 1, false)) {
			sub.back().second = i;
			sub.emplace_back(i + 1, -1);
			rec(i + 1, false);
			return;
		}
	} 
	auto it = upper_bound(ALL(nxt[c]), i);
	if(it != nxt[c].end()) {
		if(solve(i, k) == solve(*it, true)) {
			rec(*it, true);
			return;
		}
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> s;

	for(int i = 0; i < n; i++)
		nxt[s[i] - 'a'].emplace_back(i);

	memset(dp, -1, sizeof dp);

	int ans = solve(0, false);

	if(ans < 1) {
		cout << -1 << endl;
		return 0;
	}

	cout << ans << endl;
	sub.emplace_back(0, -1);
	rec(0, false);
	for(auto [a, b] : sub) cout << b - a + 1 << " ";

	return 0;
}
