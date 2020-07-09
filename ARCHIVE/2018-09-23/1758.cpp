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
int p, n, x, acu;

int main () {
  scanf ("%d", &tt);
  for (int t = 0; t < tt; t++) {
    scanf ("%d %d", &p, &n);
    acu = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < p; j++) {
	scanf ("%d", &x);
	acu += x;
      }
      ld aux = acu;
      acu /= p;
      if (cmp (acu, 4) == -1)
	printf ("%.2Lf\n", acu);
  }
  
  return 0;
}
