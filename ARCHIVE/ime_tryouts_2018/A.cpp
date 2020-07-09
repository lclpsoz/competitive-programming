#include <bits/stdc++.h>
using namespace std;

// ------------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

// ------------

const int N = 1e7 + 10;

int dp[N];

int main () {
	int n;
	scanf("%d", &n);
	
	if(n%2 == 1){
		printf("0\n");
		return 0;
	}
	
	dp[0] = 1;
	
	ll sum = 0;
	
	for(int i = 2; i <= n; i += 2){
		dp[i] = (sum + 3LL*dp[i - 2])%MOD;
		sum = (sum + 2LL*dp[i - 2])%MOD;
	}
	
	printf("%d\n", dp[n]);

	return 0;
}