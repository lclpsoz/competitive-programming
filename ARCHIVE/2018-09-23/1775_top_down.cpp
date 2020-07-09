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

const int N = 1005;

int n, tt;
int a[N];
int dp[N][N];

int func (int l, int r) {
  if (l == r)
    return 1;
  if (l > r)
    return 0;
  int &ret = dp[l][r];
  if (dp[l][r] != -1)
    return ret;
  ret = 0;
  if (a[l] == a[r])
    return ret = func (l+1, r-1) + 1;
  return ret = min (func (l+1, r), func (l, r-1)) + 1;
}

int main () {
  scanf ("%d", &tt);
  for (int t = 1; t <= tt; t++) {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf ("%d", &a[i]);
      for (int j = 0; j < n; j++)
	dp[i][j] = -1;
    }
    printf ("caso #%d: %d\n", t, func (0, n-1));
  }
  
  return 0;
}
