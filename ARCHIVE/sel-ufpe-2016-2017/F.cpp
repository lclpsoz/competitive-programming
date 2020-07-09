#include<bits/stdc++.h>
using namespace std;

// ----------------
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

// ----------------

const int N = 22, MASK = (1 << 18) + 10, SUM = N*110;

int n, m;
int a[N], sum[MASK], cant[N];
int dp[MASK];

int solve(int mask = 0){
	if(mask == (1 << n) - 1) return 1;
	
	int &ret = dp[mask];
	if(ret == -1){
		ret = 0;
		for(int i = 0; i < n; i++) if(!(mask & (1 << i)) && (cant[i] & mask) == 0){
			ret = (ret + solve(mask | (1 << i))*1LL*a[i])%MOD;
		}
	}
	return ret;
}

int main () {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int mask = 0; mask < (1 << n); mask++){
		for(int i = 0; i < n; i++) if(mask & (1 << i)){
			sum[mask] += a[i];
		}
	}
	while(m--){
		int x, y;
		scanf("%d %d", &x, &y); x--, y--;
		cant[y] |= (1 << x);
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", solve());
	
	return 0;
}
