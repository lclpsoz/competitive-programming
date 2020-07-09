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

int n;
char s[110];
int val[110];
int nxt[110];
ll dp[110][110];

ll solve (int l, int r) {
	if (l == r) return 0;
	ll &ret = dp[l][r];
	if (ret != -1) return ret;
	ll base = 0, qnt = 0;
	char now = s[l];
	for (int k = l; k < r; k++) {
		if (s[k] == now) {
			++qnt;
			ret = max (ret, base + val[qnt] + solve (k+1, r));
		} else {
			base += solve (k, nxt[k]+1); // [k, nxt[k]+1)
			k = nxt[k];
		}
	}
	
	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %s", &n, s);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &val[i]);
	nxt[n-1] = n-1;
	for (int i = n-2; i >= 0; i--)
		if (s[i] == s[i+1])
			nxt[i] = nxt[i+1];
		else
			nxt[i] = i;
	
	printf ("%lld\n", solve (0, n));
	

	return 0;
}
