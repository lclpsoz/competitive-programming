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

const int N = 5010;

int n, k;
int dp[N][N];
int a[N], mx[N];

int solve (int p, int q) {
	if (p == n or q == 0) return 0;
	int &ret = dp[p][q];
	if (ret != -1) return ret;
	return ret = max (solve (p+1, q), solve (p+mx[p], q-1) + mx[p]);
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	sort (a, a + n);
	int r = 0;
	for (int l = 0; l < n; l++) {
		while (r < n-1 and a[r+1] - a[l] <= 5) ++r;
		mx[l] = r - l + 1;
	}
	printf ("%d\n", solve (0, k));
	
	return 0;
}
