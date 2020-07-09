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

const int N = 1e5 + 10, M = 1e6 + 10;;

int n;
int dp[M][2];

int main () {
    scanf ("%d", &n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int v;
        scanf ("%d", &v);
        dp[v-1][1] = max (dp[v-1][1], dp[v-2][0] + 1);
        dp[v][1] = max (dp[v][1], dp[v-1][1] + 1);
        dp[v][0] = max (dp[v][0], dp[v-1][0] + 1);
        ans = max (max (dp[v][0], dp[v][1]), ans);
    }
    

    printf ("%d\n", ans);

	return 0;
}
