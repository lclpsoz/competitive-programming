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

const int N = 1e6 + 10;

int n, m;
int dp[N][3][3];
int a[N];

int solve (int p, int bef1, int bef2) {
	if (p == m+1) return 0;
	int &ret = dp[p][bef1][bef2];
	if (ret != -1) return ret;
	int a1 = a[p] - bef1 - bef2;
	int a2 = a[p+1] - bef2;
	int a3 = a[p+2];
	int mn = min (a1, min (a2, a3));
	ret = 0;
	for (int i = 0; i <= min (2, mn); i++)
		ret = max (ret, solve (p+1, bef2, i) + (a1-i)/3 + i);
	for (int i = 0; i < p; i++) printf ("  ");
	// printf ("  p = %d, bef1 = %d, bef2 = %d, ret = %d\n", p, bef1, bef2, ret);
	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d", &n, &m);
	for (int i = 2; i <= n+1; i++) {
		int x;
		scanf ("%d", &x);
		a[x]++;
	}

	printf ("%d\n", solve (1, 0, 0));

	return 0;
}
