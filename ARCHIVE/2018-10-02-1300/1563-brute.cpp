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

int n;
map<int, pair<ll, ll>> ans;

ll mdc (ll a, ll b) {
  if (b == 0) return a;
  return mdc (b, a%b);
}

int main () {
  while (scanf ("%d", &n) != EOF) {
    if (ans[n].y != 0) {
      printf ("%lld/%lld\n", ans[n].x, ans[n].y);
      continue;
    }
    pair<ll, ll> &val = ans[n];
    for (int i = 2; i < n; i++)
      val.x += n%i;
    //printf ("%d: %d\n", n, val.x);

    val.y = n*1LL*n;
    ll md = mdc (val.x, val.y);
    val = {val.x/md, val.y/md};
    printf ("%lld/%lld\n", val.x, val.y);
  }
  
  return 0;
}
