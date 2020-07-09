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

const int MOD = 1e8l;
inline int mod (ll x, int m = MOD) {
	return (int)(x%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 102;

int n0, n1, k0, k1;
int dp[N][N][12][2];

int solve (int q0, int q1, int q, bool tp) {
	if (tp == 0 and q > k0)
		return 0;
	if (tp == 1 and q > k1)
		return 0;
	if (q0 > n0 or q1 > n1)
		return 0;
	if (q0 == n0 and q1 == n1)
		return 1;
	int &r = dp[q0][q1][q][tp];
	if (r != -1)
		return r;
	r = 0;
	if (tp == 0)
		r += solve (q0+1, q1, q+1, 0) + solve (q0, q1+1, 1, 1);
	else
		r += solve (q0, q1+1, q+1, 1) + solve (q0+1, q1, 1, 0);
	return r = mod (r);
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d %d %d", &n0, &n1, &k0, &k1);
	printf ("%d\n", mod (solve (1, 0, 1, 0) + solve (0, 1, 1, 1)));
	
	return 0;
}
