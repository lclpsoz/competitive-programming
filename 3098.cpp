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
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

char a[1010];
int dp[1010][1010];

int solve(int l, int r) {
	if(r < l) return 0;
	if(l == r) return a[l] != 'a';
	int &ret = dp[l][r];
	if(ret != -1) return ret;
	if(a[l] == 'a') a[l] = 'A';
	return ret = max(2*(int)(a[l] == a[r]) + solve(l+1, r-1),
			max(solve(l+1, r), solve(l, r-1)));
}

int main () {
	memset(dp, -1, sizeof dp);
	scanf("%s", &a);
	printf("%d\n", solve(0, strlen(a)-1));


	return 0;
}
