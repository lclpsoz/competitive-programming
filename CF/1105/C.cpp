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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5+100;

int n, l, r;
int dp[N][3];



int main () {
	scanf ("%d %d %d", &n, &l, &r);
	int qnt[] = {r/3 - (l-1)/3,
				(r+2)/3 - (l+1)/3,
				(r+1)/3 - l/3};
	for (int i = 0; i < 3; i++)
		dp[0][i] = qnt[i];
	for (int i = 1; i < n; i++) {
		dp[i][0] = mod (mod (mod (dp[i-1][0]*1LL*qnt[0]) + 
							mod (dp[i-1][1]*1LL*qnt[2])) +
						mod (dp[i-1][2]*1LL*qnt[1]));
		dp[i][1] = mod (mod (mod (dp[i-1][0]*1LL*qnt[1]) + 
							mod (dp[i-1][1]*1LL*qnt[0])) +
						mod (dp[i-1][2]*1LL*qnt[2]));
		dp[i][2] = mod (mod (mod (dp[i-1][0]*1LL*qnt[2]) + 
							mod (dp[i-1][1]*1LL*qnt[1])) +
						mod (dp[i-1][2]*1LL*qnt[0]));
	}
	printf ("%d\n", dp[n-1][0]);

	return 0;
}
