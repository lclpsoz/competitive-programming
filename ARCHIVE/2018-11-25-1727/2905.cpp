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

const int N = 1e4+100;
const ll INF = 1e13;

int n;
ll dp[N];
ll mat[N][4];

ll func (int p) {
  if (p == n)
    return 0;
  
  ll &r = dp[p];
  if (r != -1)
    return r;

  r = INF;
  int tm = mat[p][0];
  ll acu = mat[p][1];
  for (int i = 1; i <= 6 && i+p <= n; i++) {
    r = min (r, func (p+i) + acu);
    if (tm >= 120 || i+p == n)
      break;
    tm += mat[p+i][0];
    if (i == 1)
      acu += mat[p+i][2];
    else
      acu += mat[p+i][3];
    //printf ("ACU %d [%d]:%lld\n", p, i, acu);
  }
  

  //printf ("%d: %lld\n", p, r);
  
  return r;
}

int main () {
  memset (dp, -1, sizeof dp);
  scanf ("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf ("%d %d", &mat[i][0], &mat[i][1]);
    mat[i][1] *= 100;
    mat[i][2] = mat[i][1]/2;
    mat[i][3] = mat[i][1]/4;
  }

  printf ("%.2Lf\n", (ld)func (0)/100.0);
    
  
  return 0;
}
