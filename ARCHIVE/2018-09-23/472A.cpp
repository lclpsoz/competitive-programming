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

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n;

int main () {
  scanf ("%d", &n);
  int a, b;
  a = n/2;
  b = n/2;
  if (n&1) {
    ++a;
    while (a%3 != 0 || b&1) {
      ++a; --b;
    }
    printf ("%d %d\n", a, b);
  }
  else {
    if (a % 2 != 0) {
      a++; b--;
    }
    printf ("%d %d\n", a, b);
  }
  
  return 0;
}
