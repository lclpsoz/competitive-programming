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

const int N = 3e5+10;

int n, c;
int fat[N];


int fstPow (int b, int p) {
    int r = 1;
    int aux = b;
    while (p) {
        if (p&1)
            r = mod (r*1LL*aux);
        aux = mod (aux*1LL*aux);
        p >>= 1;
    }
    
    return r;
}

int invMod (int b) {
    return fstPow (b, MOD-2);
}

int main () {
    scanf ("%d %d", &n, &c);
    // (6^n * (c-2*n)!)/((c-3n)!)
    fat[0] = 1;
    for (int i = 1; i < N; i++)
        fat[i] = mod (fat[i-1] * 1LL * i);
    printf ("%d\n", mod (
                        mod (fstPow (6, n) * 1LL * fat[c-2*n]) * 1LL * 
                        invMod (fat[c-3*n])));
    
    return 0;
}
