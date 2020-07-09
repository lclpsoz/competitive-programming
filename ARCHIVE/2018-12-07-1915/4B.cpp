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

const int N = 50;

int d, total, sumMin, sumMax;
pii arr[N];

int main () {
    scanf ("%d %d", &d, &total);
    for (int i = 0; i < d; i++) {
        int mn, mx;
        scanf ("%d %d", &mn, &mx);
        arr[i] = {mn, mx};
        sumMin += mn;
        sumMax += mx;
    }
    
    if (sumMin > total || sumMax < total)
        printf ("NO\n");
    else {
        printf ("YES\n");
        total -= sumMin;
        for (int i = 0; i < d; i++) {
            if (i) putchar (' ');
            int val = min (arr[i].y-arr[i].x, total);
            total -= val;
            val += arr[i].x;
            printf ("%d", val);
        }
        putchar ('\n');
    }

    return 0;
}
