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
	return x%m;
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;

int n;

int main () {
    scanf ("%d", &n);
    int a = 1, b = 0, c = 1, d = 0;
    for (int i = 4; i <= n; i++) {
        d = mod (a + b);
        swap (a, b);
        swap (b, c);
        swap (c, d);
    }
    printf ("%d\n", c);
    
	return 0;
}
