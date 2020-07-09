#include "stdio.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
// using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9+7;
inline int mod (int x, int m = MOD) {
	return x%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int n, k;
int dp[2010][2010];

int main () {
	scanf ("%d %d", &n, &k);
	
	for (int i = 1; i <= n; i++)
		dp[k][i] = 1;
	for (int i = k-1; i >= 1; i--)
		for (int val = 1; val <= n; val++)
			for (int mult = val; mult <= n; mult += val)
				dp[i][val] = mod (dp[i][val] + dp[i+1][mult]);
			
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = mod (ans + dp[1][i]);
	
	printf ("%d\n", ans);
			
	return 0;
}