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

mt19937_64 rng((llu)chrono::steady_clock::now().time_since_epoch().count());

int main () {
    uniform_real_distribution<ld> disReal(-10000, 10000); // Real numbers in interval [l, r) EXCLUSIVE
    
    int n = 100000;
    printf ("%d\n", n);
    for (int i = 0; i < n; i++)
        printf ("%.20Lf %.20Lf\n", disReal (rng), disReal (rng));
    
	return 0;
}
