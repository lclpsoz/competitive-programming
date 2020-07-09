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

const int MOD = 1e6 + 7;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int MAXN = 2e5+10;

int t;
int k, n;
int a[MAXN];

int main () {
  scanf ("%d", &t);
  while (t--) {
    scanf ("%d %d", &k, &n);
    int i = 1;
    for (; i <= k && i <= n; i++)
      a[i] = i-1;
    if (i <= n) {
      a[i] = mod ((k*1LL*(k-1))/2);
      i++;
      for (; i <= n; i++)
	a[i] = mod (2*a[i-1]-a[i-k-1]);
    }
    printf ("%d\n", a[n]);
  }

  return 0;
}
