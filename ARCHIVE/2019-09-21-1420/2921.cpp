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

const int N = 1010;

int n;
int mat[N][N], pref[N][N];

ll kad2d (int l, int r) {
    ll ret = - 1e18;
    ll now = pref[0][r] - pref[0][l-1];
    for (int i = 1; i <= n; i++) {
        int sum = pref[i][r] - pref[i][l-1];
        if (now + sum < sum)
            now = sum;
        else now += sum;
        ret = max (ret, now);
    }
    
    return ret;
}

int main () {
    while (scanf ("%d", &n) != EOF) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                scanf ("%d", &mat[i][j]);
                pref[i][j] = mat[i][j];
            }
        for (int i = 1; i <= n; i++)
            for (int j = 2; j <= n; j++)
                pref[i][j] += pref[i][j-1];
            
        ll ans = - 1e18;
        for (int i = 1; i <= n; i++)
            for (int j = i; j <= n; j++)
                ans = max (ans, kad2d (i, j));
        printf ("%lld\n", ans);
    }

	return 0;
}
