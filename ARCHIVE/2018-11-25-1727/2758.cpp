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

float a, b;
double c, d;

int main () {
  cin >> a >> b >> c >> d;
  printf ("A = %.6f, B = %.6f\n", a, b);
  printf ("C = %.6lf, D = %.6lf\n", c, d);
  for (int i = 1; i <= 3; i++) {
    printf ("A = %.*f, B = %.*f\n", i, a, i, b);
    printf ("C = %.*lf, D = %.*lf\n", i, c, i, d);
  }
  printf ("A = %.3E, B = %.3E\n", a, b);
  printf ("C = %.3E, D = %.3E\n", c, d);
  printf ("A = %.0f, B = %.0f\n", a, b);
  printf ("C = %.0lf, D = %.0lf\n", c, d);
  
  return 0;
}
