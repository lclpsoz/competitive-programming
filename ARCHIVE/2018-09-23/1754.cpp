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

int t;
ll x, y;

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%lld %lld", &x, &y);
    if (x%y == 0)
      printf ("%lld\n", max (2ll, x/y));
    else
      printf ("%lld\n", max (2ll, x/y + 1));
  }
  
  return 0;
}
