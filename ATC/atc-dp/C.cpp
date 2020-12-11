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

const int N = 1e5+10;

int n;
int a[N][3];
int dp[N][3];

int solve (int day, int bef) {
	if (day > n)
		return 0;
	
	int &r = dp[day][bef];
	if (r != -1) return r;
	for (int i = 0; i < 3; i++)
		if (i != bef)
			r = max (r, solve (day+1, i) + a[day][i]);
		
	return r;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			scanf ("%d", &a[i][j]);
		
	int ans = -1;
	for (int i = 0; i < 3; i++)
		ans = max (ans, solve (2, i) + a[1][i]);
	printf ("%d\n", ans);

	return 0;
}
