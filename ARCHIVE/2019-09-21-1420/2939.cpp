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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
int ans = 1;

int main () {
    scanf ("%d", &n);
    int b = 2;
    int ax = n;
    while (ax) {
        if (ax&1)
            ans = (ans * 1LL * b)%MOD;
        ax >>= 1;
        b = (b * 1LL * b) % MOD;
    }
    
    for (int i = 2; i <= n; i++)
        ans = (ans * 1LL * i) % MOD;
    
    int bef = 0, fib = 1;
    while (n-- >= 1) {
        int c = (fib + bef)%MOD;
        bef = fib;
        fib = c;
    }
    ans = (ans * 1LL * fib) % MOD;
    printf ("%d\n", ans);

	return 0;
}
