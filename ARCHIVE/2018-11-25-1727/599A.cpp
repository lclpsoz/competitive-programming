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

int main () {
  int a, b, c;
  cin >> a >> b >> c;
  int x1, x2, x3, x4;
  x1 = a+c+b;
  x2 = a+a+b+b;
  x3 = a+c+c+a;
  x4 = b+c+c+b;
  printf ("%d\n", min (min (x1, x2), min (x3, x4)));

  return 0;
}
