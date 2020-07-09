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
  int x1, y1, x2, y2, x3, y3, x4, y4;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2 && y1 == y2) {
    printf ("-1\n");
    return 0;
  }
  else if (x1 != x2 && y1 != y2 && abs (x1-x2) != abs (y1-y2)) {
    printf ("-1\n");
    return 0;
  }
  else if (x1 == x2) {
    int d = abs (y1-y2);
    x3 = x4 = x1 + d;
    y3 = y1;
    y4 = y2;
  } else if (y1 == y2) {
    int d = abs (x1-x2);
    y3 = y4 = y1 + d;
    x3 = x1;
    x4 = x2;
  } else {
    x3 = x1;
    y3 = y2;
    x4 = x2;
    y4 = y1;
  }
  printf ("%d %d %d %d\n", x3, y3, x4, y4);

  return 0;
}
