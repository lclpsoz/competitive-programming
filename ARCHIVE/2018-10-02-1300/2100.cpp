#include <bits/stdc++.h>
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

const int MOD = 1300031;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 4040;

int t;
int n, m;
int fat[N], inv_fat[4040];

int pow_mod (int b, int p) {
  int r = 1;
  while (p) {
    if (p&1)
      r = mod (r*1LL*b);
    p >>= 1;
    b = mod (b*1LL*b);
  }

  return r;
}

int inv_mod (int x) {
  return pow_mod (x, MOD-2);
}

int ans () {
  return (mod (mod (fat[n-m]*1LL*inv_fat[n-2*m]) * pow_mod (2, m)));
}

int main () {
  fat[0] = inv_fat[0] = 1;
  for (int i = 1; i < 4040; i++) {
    fat[i] = mod (fat[i-1]*1LL*i);
    inv_fat[i] = inv_mod (fat[i]);
  }
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &n, &m);
    printf ("%d\n", ans ());
  }
  
  return 0;
}
