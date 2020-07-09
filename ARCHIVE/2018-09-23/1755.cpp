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

int tt;
int d, n;
ld x;

int main () {
  scanf ("%d", &tt);
  while (tt--) {
    scanf ("%d %d", &d, &n);
    //printf ("%d %d\n", d, n);
    ld ans = 0;
    char str[100];
    for (int i = 0; i < n; i++) {
      scanf ("%Lf", &x);
      int q = 1;
      while (x*q <= d) ++q;
      --q;
      if (q)
	ans = max (ans, d-q*x);
    }
    printf ("%.2Lf\n", ans);
  }
  
  return 0;
}

