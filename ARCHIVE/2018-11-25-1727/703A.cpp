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

int ans;

int main () {
  int n;
  scanf ("%d", &n);
  while (n--) {
    int x, y;
    scanf  ("%d %d", &x, &y);
    if (x > y)
      ++ans;
    else if (x < y)
      --ans;
  }
  if (ans == 0)
    printf ("Friendship is magic!^^\n");
  else if (ans > 0)
    printf ("Mishka\n");
  else
    printf ("Chris\n");

  return 0;
}
