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

char s[N], zs[2*N];
int n, a, b;
int dp[N], z[2*N+10];
int pref[N];

int z_function(int st) {
    int nn = n+1+st;
	int mx = 0;
    for (int i = 1, l = 0, r = 0; i+st < nn; ++i) {
		z[i] = 0;
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (st + i + z[i] < nn && zs[z[i]+st] == zs[i + z[i]+st])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
		if (i+st > n) mx = max (mx, z[i]);
    }
	// printf ("st = %d %d %lld\n", st, c1, c2);
	// putchar ('\n');

	return mx;
	
}

int solve (int p) {
	if (p == n) return 0;
	int &ret = dp[p];
	if (ret != -1) return ret;
	ret = 2e9;
	int qP = pref[p];
	// printf ("p = %d, qP = %d\n", p, qP);
	ret = solve (p+1) + a;
	if (qP and qP*a >= b)
		ret = min (ret, solve (p+qP) + b);
	return ret;
}

int main () {
	memset (dp, -1, sizeof dp);
	scanf ("%d %d %d %s", &n, &a, &b, s);
	zs[n] = '#';
	for (int i = 0; i < n; i++) {
		// s[i] -= 'a';
		zs[i] = s[i], zs[i+n+1] = s[i];
	}
	// printf ("%s\n", zs);

	for (int i = 0; i < n; i++) pref[i] = z_function (i);
	// printf ("%d %d\n", c1, c2);
	printf ("%d\n", solve (0));

	return 0;
}