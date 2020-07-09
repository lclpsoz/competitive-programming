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

const int INF = 1e9 + 10;
const int N = 505;

int n, dp[N][N];
char str[N];

int func (int l, int r) {
	int &ret = dp[l][r];
	if (ret != -1) return ret;
	int c = str[l];
	ret = 0;
	for (int p = l; p <= r; p++) {
		while (str[p] == c and p <= r) ++p;
		if (p > r) break;
		int st = p;
		while (str[p+1] != c and p+1 <= r) ++p;
		ret += func (st, p) + (str[st] != c);
	}
	
	for (int k = l; k < r; k++)
		ret = min (ret, func (l, k) + func (k+1, r) + (str[k+1] != c));
	
	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %s", &n, str);
	for (int i = 0; i < n; i++) str[i] -= 'a';
	printf ("%d\n", func (0, n-1) + 1);

	return 0;
}
