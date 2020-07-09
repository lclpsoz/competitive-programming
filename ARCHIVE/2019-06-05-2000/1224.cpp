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

const int N = 1e4 + 10;

int n;
int a[N];
ll dp[N][2];
int now, bef;

int main () {
	while (scanf ("%d", &n) != EOF) {
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &a[i]);
			dp[i][1] = 0; // 1 element
		}
		now = 0, bef = 1;
		for (int p = 2; p <= n; p++) {
			for (int i = p; i <= n; i++)
				if (p&1)
					dp[i][now] = min (dp[i-1][bef], dp[i][bef]);
				else
					dp[i][now] = max (dp[i-1][bef] + a[i], dp[i][bef] + a[i-p+1]);
			swap (now, bef);
		}
		printf ("%lld\n", dp[n][0]);
	}

	return 0;
}
