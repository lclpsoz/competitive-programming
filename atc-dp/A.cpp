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

const int INF = 1e9+100;

const int N = 1e5+10;

int n;
int a[N];
int dp[N];

int solve (int p) {
	if (p == n)
		return 0;
	else if (p > n)
		return INF;
	int &r = dp[p];
	if (r != -1) return r;
	return r = min (solve (p+1) + abs(a[p]-a[p+1]),
					solve (p+2) + abs(a[p]-a[p+2]));
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	printf ("%d\n", solve (1));

	return 0;
}
