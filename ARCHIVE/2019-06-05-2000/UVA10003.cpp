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

int leng, n;
int dp[52][52];
vector<int> vec;

int solveTopDown (int l, int r) {
	if (l == r-1) return 0;
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	
	ret = 2e9;
	for (int i = l+1; i < r; i++)
		ret = min (ret, solveTopDown (l, i) + solveTopDown (i, r));
	
	ret += vec[r] - vec[l];
	return ret;
}

int solve (int l, int r) {
	for (int i = 0; i <= r; i++)
		dp[i][i+1] = 0;
	for (int k = 2; k <= r; k++)
		for (int i = 0; i <= r-k; i++) {
			int &now = dp[i][i+k];
			now = 2e9;
			for (int j = i+1; j < i+k; j++)
				now = min (now, dp[i][j] + dp[j][i+k]);
			now += vec[i+k] - vec[i];
		}
				
	return dp[l][r];
}

int main () {
	while (scanf ("%d", &leng), leng) {
// 		memset (dp, 0, sizeof dp);
		vec.clear();
		vec.push_back (0);
		scanf ("%d", &n);
		for (int i = 1; i <= n; i++) {
			int x;
			scanf ("%d", &x);
			vec.push_back (x);
		}
		vec.push_back (leng);
		printf ("The minimum cutting is %d.\n", solve (0, n+1));
	}

	return 0;
}
