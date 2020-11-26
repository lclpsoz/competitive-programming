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

const int N = 2e5+10;

int n;
int a[N];

int main () {
  scanf ("%d", &n);
  int l = 0, r = n+1;
  for (int i = 1; i <= n; i++)
    scanf ("%d", &a[i]);

  ll sum_l, sum_r;
  ll ans = 0;
  sum_l = sum_r = 0;
  
  while (l < r && l <= n && r >= 1) {
    //printf ("%d %d\n", l, r);
    if (sum_l == sum_r) {
      ans = max (sum_l, ans);
      ++l; sum_l += a[l];
      --r; sum_r += a[r];
    }
    else if (sum_l < sum_r) {
      ++l; sum_l += a[l];
    } else {
      --r; sum_r += a[r];
    }
  }

  printf ("%lld\n", ans);
  
  return 0;
}
