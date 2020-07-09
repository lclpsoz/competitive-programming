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

string s;
int n, a, b;
int dp[N], z[N];
int pref[N];
int c1, c2;

int z_function(string ss) {
    int nn = len (ss);
	int mx = -1;
	memset (z, 0, sizeof (int)*(nn+1));
    for (int i = 1, l = 0, r = 0; i < nn; ++i) {
		++c1;
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < nn && ss[z[i]] == ss[i + z[i]])
            ++z[i], ++c2;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
		if (mx == -1 and ss[i] == '#') mx = 0;
		if (mx != -1) mx = max (mx, z[i]);
    }

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
	ios::sync_with_stdio (false);
	memset (dp, -1, sizeof dp);
	cin >> n >> a >> b >> s;

	int sum = 0;
	for (int i = 1; i < n; i++) {
		string ax = s.substr(i)+'#'+s.substr(0, i);
		sum += len (ax);
		printf ("%d %d\n", i, sum), pref[i] = z_function (s.substr(i)+'#'+s.substr(0, i));
	}
	printf ("%d %d %d\n", sum, c1, c2);

	printf ("%d\n", solve (0));

	return 0;
}
