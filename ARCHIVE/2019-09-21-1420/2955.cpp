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

int a[1010];

int main () {
    int x;
    scanf ("%d", &x);
    
    a[0] = 1;
    for (int i = 1; i <= 1009; i++) {
        for (int j = 0; i-j >= 0; j+=3)
            a[i] = mod (a[i] + a[i-j]);
        a[i] = mod (a[i] + a[i-1]);
    }
//     for (int i = 1; i <= 100; i++)
//         printf ("%d %d %d\n", i, a[i], mod (a[i+2] - a[i-1]));
        
//     printf ("%d %d\n", a[15], a[82]);

    if (x == 1)
        printf ("1 1\n");
    else if (x == 2)
        printf ("2 2\n");
    else
        printf ("%d %d\n", mod (a[x+2] - a[x-1]), x%3 + 1); 

	return 0;
}
