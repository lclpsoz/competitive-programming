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

int main () {
  int a, b;
  float c, d;
  a = 15;
  b = a/2;
  c = 15.456;
  d = c/7;
  printf ("Valores de b:\n");
  printf ("-------------\n");
  printf ("1) b = 7\n");
  printf ("2) b = %20d\n", b);
  printf ("3) b = %020d\n", b);
  printf ("4) b = %-20d\n", b);
  printf ("5) b = %d%%\n", b);
  putchar ('\n');
  printf ("Valores de d:\n");
  printf ("-------------\n");
  printf ("1) d = %f\n", d);
  printf ("2) d = %.0f\n", d);
  printf ("3) d = %.1f\n", d);
  printf ("4) d = %.2f\n", d);
  printf ("5) d = %.3f\n", d);
  printf ("6) d = %20.3f\n", d);
  printf ("7) d = %020.3f\n", d);
  printf ("8) d = %-20.3f\n", d);
  printf ("9) d = %.2f%%\n", d);
  
  return 0;
}
