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

const int N = 105;

int n;
int dp[N][2][2];
bool gym[N], contest[N];

int solve (int d, bool yGym, bool yContest) {
	if (d > n) return 0;
	int &ret = dp[d][yGym][yContest];
	if (ret != -1) return ret;
	ret = n+10;
	if (!yGym and gym[d])
		ret = min (ret, solve (d+1, true, false));
	if (!yContest and contest[d])
		ret = min (ret, solve (d+1, false, true));
	
	return ret = min (ret, solve (d+1, false, false) + 1);
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		gym[i] = x/2;
		contest[i] = x&1;
	}
	
	printf ("%d\n", solve (1, false, false));

	return 0;
}
