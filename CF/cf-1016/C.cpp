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

const int N = 3e5+100;

int n;
ll asc[2][N], desc[2][N], baseAsc[2][N], baseDesc[2][N];
ll a[2][N];

void fillAsc () {
  int i, ax;
  ax = 1; i = 2;
  for (; i <= n; i++) {
    baseAsc[0][i] = baseAsc[0][i-1] + a[0][i];
    asc[0][i] = asc[0][i-1] + ax*a[0][i];
    ++ax;
  }
  --i;
  baseAsc[1][i] = baseAsc[0][i];
  asc[1][i] = asc[0][i];
  for (; i >= 1; i--) {
    baseAsc[1][i] += baseAsc[1][i+1] + a[1][i];
    asc[1][i] += asc[1][i+1] + ax*a[1][i];
    ++ax;
  }
}

void fillDesc () {
  int i, ax;
  ax = 1; i = 1;
  for (; i <= n; i++) {
    baseDesc[1][i] = baseDesc[1][i-1] + a[1][i];
    desc[1][i] = desc[1][i-1] + ax*a[1][i];
    ++ax;
  }
  --i;
  baseDesc[0][i] = baseDesc[1][i];
  desc[0][i] = desc[1][i];
  for (; i >= 1; i--) {
    baseDesc[0][i] += baseDesc[0][i+1] + a[0][i];
    desc[0][i] += desc[0][i+1] + ax*a[0][i];
    ++ax;
  }
}

ll func (int x, int y, int ax) {
  if (y > n)
    return 0;
  ll v = ax*a[x][y];
  ll en = 0;
  if (!x) {
    en = (asc[!x][y+1]-asc[x][y]) + (ax-y+1)*(baseAsc[!x][y+1]-baseAsc[x][y]);
    //printf (" en1: %lld\n", (asc[!x][y+1]-asc[x][y]));
    //printf (" en1: %lld x %d\n", (baseAsc[!x][y+1]-baseAsc[x][y]), ax-y);
  }
  else {
    en = (desc[!x][y+1]-desc[x][y]) + (ax-y)*(baseDesc[!x][y+1]-baseDesc[x][y]);
    //printf (" en1: %lld\n", (desc[!x][y+1]-desc[x][y]));
    //printf (" en2: %lld\n", (ax-y)*(baseDesc[!x][y+1]-baseDesc[x][y]));
  }
  
  //printf ("%d %d %d %lld %lld\t%lld\n\n", x, y, ax, v, en, v+en);
  if (ax%2 == 1)
    return max (v+en, v + func (x, y+1, ax+1));
  else
    return max (v+en, v + func (!x, y, ax+1));
}

int main () {
  scanf ("%d", &n);
  for (int i = 0; i < 2; i++)
    for (int j = 1; j <= n; j++)
      scanf ("%lld", &a[i][j]);
  a[1][0] = 0;

  fillAsc();
  fillDesc();
  ll ans = asc[1][1];

  ans = max (ans, func (1, 1, 1));

  printf ("%lld\n", ans);  

  return 0;
}
