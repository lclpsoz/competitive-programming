#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int INF = 1e9 + 10;
const int N = 1e5 + 10;

string s;
int dp[N][4];

int solve (int p, int rest) {
	if (p == len (s))
		return INF;
	int &ret = dp[p][rest];
	if (ret != -1)
		return ret;
	ret = INF;
	if ((rest+s[p])%3 == 0 and s[p]%2 == 0)
		ret = len (s)-p-1;
	ret = min (ret, solve (p+1, rest) + 1);
	if (rest != 3 or (rest == 3 and s[p] != 0)) {
		if (rest == 3) rest = 0;
		ret = min (ret, solve (p+1, (rest+s[p])%3));
	}
	// cout << p << ' ' << (int)started << ' ' << rest << " ret: " << ret << '\n';

	return ret;
}

int main () {
	ios::sync_with_stdio (false);
	cin.tie (0);
	int t;
	cin >> t;
	while (t--) {
		memset (dp, -1, sizeof dp);
		cin >> s;
		for (int i = 0; i < len (s); i++) s[i] -= '0';
		int ans = solve (0, 3);
		if (ans == INF)
			cout << "Cilada\n";
		else
			cout << ans << '\n';
	}

	return 0;
}
