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
int cmp(ld x, ld y = 0, ld tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

using point = pair<ld, ld>;
int n;
// Coeficients:
pair<ld, ld> target; // x is down; y is top
pair<ld, ld> way;

ld f_coef (point a, point b) {
  return ((b.x-a.x)/(b.y-a.y));
}

int main () {
  scanf ("%d", &n);
  way.x = 0;
  way.y = 1e9;
  ld d, a, b;
  point st = {0.0, 0.0};
  while (n--) {
    scanf ("%Lf %Lf %Lf", &d, &a, &b);
    way.y = min (way.y, f_coef (st, {b, d}));
    way.x = max (way.x, f_coef (st, {a, d}));
  }
  scanf ("%Lf %Lf %Lf", &d, &a, &b);
  target.y = f_coef (st, {b, d});
  target.x = f_coef (st, {a, d});
  //printf ("%.3Lf %.3Lf\n", way.y, target.y);
  //printf ("%.3Lf %.3Lf\n", way.x, target.x);
  if (cmp (way.x, way.y) == 1 || cmp (way.x, target.y) == 1 || cmp (way.y, target.x) == -1)
    printf ("N\n");
  else
    printf ("Y\n");
  
  return 0;
}
