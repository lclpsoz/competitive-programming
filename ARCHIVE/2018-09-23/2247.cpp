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

int n;

int main () {
  int j, z;
  int t = 1;
  while (scanf ("%d", &n), n) {
    j = z = 0;
    int x, y;
    printf ("Teste %d\n", t++);
    for (int i = 0; i < n; i++) {
      scanf ("%d %d", &x, &y);
      j += x; z += y;
      printf ("%d\n", j-z);
    }
    putchar ('\n');
  }

  return 0;
}
