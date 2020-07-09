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


const ll INF = 1e11+10;
const int N = 1010;

int n;
ll mat[N][N], matCycle[N][N];
ll dp[N][N];

int main () {
	while (scanf ("%d", &n), n) {
		ll ans = 0;
		memset (dp, 0, sizeof dp);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= i; j++)
				scanf ("%lld", &mat[i][j]);
		for (int i = 1; i <= n; i++)
			for (int j = 1, k = 1; j <= n-i+1; j++, k++) {
				matCycle[i][k]  = mat[j+i-1][j] + matCycle[i][k-1];
//  				printf ("%lld%c", matCycle[i][k], " \n"[j==n-i+1]);
			}
		
		for (int i = 1; i <= n; i++) {
			for (int j = n-i+1; j >= 1; j--) {
				if (j == n-i+1)
					dp[i][j] = matCycle[i][j] + dp[i-1][j];
				else
					dp[i][j] = max (matCycle[i][j] + dp[i-1][j], dp[i][j+1]);
				ans = max (ans, dp[i][j]);
			}
		}
		
		printf ("%lld\n", ans);
// 		printf ("_____\n");
	}

	return 0;
}
