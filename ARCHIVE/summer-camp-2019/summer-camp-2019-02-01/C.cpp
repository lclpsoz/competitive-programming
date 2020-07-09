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



int n, m;
int dp[1010][15];
int a[15], b[15], c[15], d[15];

int solve (int qnt, int p) {
//     printf ("%d %d\n", qnt, p);
    if (p > m or qnt == 0) return 0;
    
    int &ret = dp[qnt][p];
//     printf ("RET: %d\n", ret);
    if (ret != -1) return ret;

//     printf ("%d %d\n", qnt, p);
    for (int i = 0; c[p]*i <= qnt and b[p]*i <= a[p]; i++)
        ret = max (ret, solve (qnt-c[p]*i, p+1) + d[p]*i);
    
    return ret;
}

int main () {
    memset (dp, -1, sizeof dp);
    a[0] = 1000000000;
    b[0] = 1;
    scanf ("%d %d %d %d", &n, &m, &c[0], &d[0]);
    for (int i = 1; i <= m; i++)
        scanf ("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
    printf ("%d\n", solve (n, 0));

	return 0;
}
