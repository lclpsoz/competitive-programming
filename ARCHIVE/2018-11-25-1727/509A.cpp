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

int mat[15][15];

int main () {
  int n;
  scanf ("%d", &n);
  
  for (int i = 0; i < n; i++)
    mat[i][0] = mat[0][i] = 1;
  int ans = 1;
  for (int i = 1; i < n; i++)
    for (int j = i; j < n; j++)
      ans = max (ans, mat[i][j] = mat[j][i] = mat[i-1][j] + mat[i][j-1]);

  printf ("%d\n", ans);
  

  return 0;
}
