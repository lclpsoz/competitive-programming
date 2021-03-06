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
  int n, m;
  scanf ("%d %d", &n, &m);
  if (m > n)
    printf ("-1\n");
  else if (m == n)
    printf ("%d\n", m);
  else {
    for (int i = m;; i += m)
      if (n <= 2*i) {
	printf ("%d\n", i);
	break;
      }
  }

  return 0;
}
