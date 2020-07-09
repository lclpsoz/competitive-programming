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

const int N = 3010;

ld dp[N][N];
int n;
ld pos[N];
bool vis[N][N];

ld solve (int p, int h) {
	if (p > n)
		return h > n/2;
	
	ld &r = dp[p][h];
	if (vis[p][h]) return r;
	vis[p][h] = true;
	return r = pos[p]*solve (p+1, h+1) +  (1-pos[p])*solve (p+1, h);
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf ("%Lf", &pos[i]);
	printf ("%0.16Lf\n", solve (0, 0));

	return 0;
}
