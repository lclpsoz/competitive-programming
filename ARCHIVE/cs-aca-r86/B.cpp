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

int n, c, s;
int dp[N][(1<<5) + 1];
int a[N], b[N];
int prod[100];

int solve (int now, int msk) {
	if (now >= c) return 0;
	int &ret = dp[now][msk];
	if (ret != -1) return ret;
	ret = solve (now + prod[msk], msk) + 1;
	for (int i = 0; i < n; i++)
		if (((1<<i)&msk) == 0 and now >= a[i])
			ret = min (ret, solve (now - a[i], msk | (1<<i)));

	// printf ("%d %d -> %d\n", now, msk, ret);
	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d %d", &n, &c, &s);
	for (int i = 0; i < n; i++)
		scanf ("%d %d", &a[i], &b[i]);

	for (int i = 0; i < (1<<n); i++) {
		prod[i] = s;
		for (int j = 0; j < n; j++)
			if ((1<<j)&i)
				prod[i] += b[j];
		// printf ("%d: %d\n", i, prod[i]);
	}

	printf ("%d\n", solve (0, 0));

	return 0;
}
