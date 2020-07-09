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

int a, b, c;

int main () {
  scanf ("%d %d %d", &a, &b, &c);
  printf ("A = %d, B = %d, C = %d\n", a, b, c);
  printf ("A = %10d, B = %10d, C = %10d\n", a, b, c);
  printf ("A = %010d, B = %010d, C = %010d\n", a, b, c);
  printf ("A = %-10d, B = %-10d, C = %-10d\n", a, b, c);
  
  return 0;
}
