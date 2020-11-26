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

const int N = 5010;

int n;
vector<int> vec;
int dp[N][N];

int solve (int l, int r) {
// 	printf ("%d %d\n", l, r);
	if (l == r) return 0;
	
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	if (vec[l] == vec[r])
		ret = solve (l+1, r-1) + 1;
	ret = max (ret, solve (l+1, r));
	ret = max (ret, solve (l, r-1));
	
	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		if (vec.empty() or vec.back() != x)
			vec.push_back (x);
	}
	
	n = len (vec);
	printf ("%d\n", n - 1 - solve (0, n-1));

	return 0;
}
