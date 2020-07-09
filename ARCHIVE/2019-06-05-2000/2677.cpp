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

const int N = 1005;

int n;
int dp[N][2];
int a[N];

int main () {
	while (scanf ("%d", &n), n) {
		n *= 2;
		for (int i = 1; i <= n; i++) {
			scanf ("%d", &a[i]); // 1 element
			a[i] = !(a[i]&1);
			dp[i][1] = 0;			
		}
		int now, bef;
		now = 0, bef = 1;
		for (int p = 2; p <= n; p++) {
			for (int i = p; i <= n; i++)
				if (p&1)
					dp[i][now] = min (dp[i-1][bef], dp[i][bef]);
				else
					dp[i][now] = max (dp[i-1][bef] + a[i], dp[i][bef] + a[i-p+1]);
			swap (now, bef);
//  			for (int i = 1; i <= n; i++)
//  				printf ("%d%c", dp[i][now], " \n"[i==n]);
		}
		
		printf ("%d\n", dp[n][0]);
	}
	
	return 0;
}
