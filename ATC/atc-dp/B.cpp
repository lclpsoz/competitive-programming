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

const int INF = 1e9 + 1e3;
const int N = 1e5+10;

int n, k;
int a[N], dp[N];

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf ("%d", &a[i]);
		dp[i] = INF;
	}
	dp[1] = 0;
	for (int i = 1; i <= n; i++)
		for (int nxt = i+1; nxt-i <= k and nxt <= n; nxt++)
			dp[nxt] = min (dp[nxt], dp[i] + abs (a[i]-a[nxt]));
	
	printf ("%d\n", dp[n]);

	return 0;
}
