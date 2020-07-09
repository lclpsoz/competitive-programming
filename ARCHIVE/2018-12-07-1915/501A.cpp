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

int a, b, c, d;
int v1, v2;

int main () {
  scanf ("%d %d %d %d", &a, &b, &c, &d);
  v1 = max ((3*a)/10, a - (a/250 * c));
  v2 = max ((3*b)/10, b - (b/250 * d));
  if (v1 == v2)
    printf ("Tie\n");
  else if (v1 > v2)
    printf ("Misha\n");
  else
    printf ("Vasya\n");
  
  return 0;
}
