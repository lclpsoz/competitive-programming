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
vector<char> vec;
int dp[4][1010];

int solve(int l, int r) {
	if(r < l) return 0;
	if(l == r) return 1;
	int &ret = dp[l][r];
	if(ret != -1) return ret;
	return ret = max(2*(int)(vec[l] == vec[r]) + solve(l+1, r-1),
			max(solve(l+1, r), solve(l, r-1)));
}

int main () {
	scanf("%s", &a);
	for(int i = 0; a[i] != '\0'; i++)
		if(a[i] != 'a')
			vec.push_back(a[i]);
	for(int i = 1; i <= len(vec); i++) dp[1][i] = 1;
	int ans = min(1, len(vec));
	for(int i = 2; i <= len(vec); i++)
		for(int j = 1; j <= len(vec)-i+1; j++) {
			dp[i%4][j] = max(dp[(i-2)%4][j+1] + 2*(vec[j-1] == vec[j+i-1-1]),
						max(dp[(i-1)%4][j], dp[(i-1)%4][j+1]));
			ans = max(ans, dp[i%4][j]);
		}
	printf("%d\n", ans);

	return 0;
}
