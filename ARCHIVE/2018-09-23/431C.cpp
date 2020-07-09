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

const int MOD = 1e9+7;
int mod (ll x, ll m = MOD) {
  return ((x%m) + m)%m;
}

////////////////////////// Solution starts below. //////////////////////////////

int k, d;

ll dp[105][2];

ll func (int n, bool ok) {
  //printf ("%d %d\n", n, ok);
  if (n == 0)
    return ok;
  ll &val = dp[n][ok];
  if (val != -1)
    return val;
  val = 0;
  for (int i = 1; i <= k && i <= n; ++i) {
    if (i < d)
      val += func (n-i, ok);
    else
      val += func (n-i, true);
  }

  return val = mod (val);
}

int main () {
  memset (dp, -1, sizeof (dp));
  int n;
  scanf ("%d %d %d", &n, &k, &d);
  printf ("%lld\n", func (n, false));
  
  return 0;
}
