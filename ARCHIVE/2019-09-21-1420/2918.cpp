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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

ll l, r;
ll dp[12][10];

void initDp () {
    for (int i = 1; i <= 9; i++)
        dp[0][i] = i + dp[0][i-1];
    ll p10 = 10;
    for (int p = 1; p < 12; p++) {
        dp[p][0] = dp[p-1][9];
//         printf ("\np = %2d d =  0 > %10lld\n", p, dp[p][0]);
        for (int d = 1; d < 10; d++) {
            dp[p][d] = dp[p][d-1] + d*p10 + dp[p-1][9];
//             printf ("p = %2d d = %2d > %10lld\n", p, d, dp[p][d]);
        }
        p10 *= 10;
    }
}

ll getSum (ll n) {
    if (n == 0) return 0;
    ll ret = dp[0][n%10];
    ll now = n/10;
    ll p10 = 10;
    int p = 1;
    while (now) {
//         printf ("now: %lld\n", now);
        if (now%10)
            ret += dp[p][now%10 - 1] + (now%10)*(n%p10 + 1);
        p10 *= 10;
        now /= 10;
        p++;
    }
    
    return ret;
}

int main () {
    initDp();
    while (scanf ("%lld %lld", &l, &r) != EOF) {
        l = max (l, 1ll);
        printf ("%lld\n", mod (getSum (r) - getSum (l-1)));
    }

	return 0;
}
