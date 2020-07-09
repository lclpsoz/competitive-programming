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

const int N = 505;

int n, k;
int mat[N][N];
int ans;

int main () {
  scanf ("%d %d", &n, &k);
  int v = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j < k; j++)
      mat[i][j] = v++;
  for (int i = 1; i <= n; i++) {
    ans += v;
    for (int j = k; j <= n; j++)
      mat[i][j] = v++;
  }

  printf ("%d\n", ans);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++)
      printf ("%d ", mat[i][j]);
    putchar ('\n');
  }

  return 0;
}
