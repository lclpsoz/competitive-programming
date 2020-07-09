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

const int N = 1e5 + 10;

int qnt[N];
ll dp[N];

ll solve(int p) {
	if(p >= N) return 0;
	ll &ret = dp[p];
	if(ret != -1) return ret;
	return ret = max(solve(p+1), solve(p+2) + p*1LL*qnt[p]);
}

int main () {
	memset(dp, -1, sizeof dp);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		qnt[x]++;
	}
	printf("%lld\n", solve(1));

	return 0;
}
