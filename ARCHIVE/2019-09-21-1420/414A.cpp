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

int n, k;

const int VAL = 5e8 + 10;

int main () {
    scanf ("%d %d", &n, &k);
    if ((n <= 1 and k > 0) or n/2 > k)
        printf ("-1\n");
    else {
        for (int i = 1; i < n/2; i++)
            printf ("%d %d ", i*2 + VAL, i*2+1 + VAL);
        
        if (n > 1) {
            int v = k - n/2 + 1;
            
            printf ("%d %d ", v, 2*v);
        }
        
        if (n%2 == 1)
            printf ("1000000000\n");
    }

	return 0;
}
