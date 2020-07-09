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

int a, b, c;

int main () {
    scanf ("%d %d %d", &a, &b, &c);
    for (int i = 1; i <= 1000; i++) {
//         printf ("%d %d %d\n", i, 2*i, 4*i);
        if (!(a >= i and b >= 2*i and c >= 4*i)) {
            --i;
            printf ("%d\n", i + 2*i + 4*i);
            exit (0);
        }   
    }

	return 0;
}
