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

// Solution N^2

int dp[102][102];  // N, K

int main () {
	for (int i = 0; i <= 100; i++)
		dp[i][1] = 1;
	for (int k = 2; k <= 100; k++)
		for (int i = 0; i <= 100; i++) {
			int &now = dp[i][k];
			now = dp[i][k-1];
			if (i)
				now += dp[i-1][k];
			now %= 1000000;
		}
		
	int x, y;
	while (scanf ("%d %d", &x, &y), x) printf ("%d\n", dp[x][y]);

	return 0;
}
