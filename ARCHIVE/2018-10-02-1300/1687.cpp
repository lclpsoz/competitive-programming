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

const int MOD = 1300031;
inline int mod (ll x, int m = MOD) {
  return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 15, P = 1e5+10;;

int dp[N][N][P];
int adj[][2] = {

int func (int x, int y, int p) {  
  int &ret = dp[x][y][p];
  if (ret != -1)
    return ret;
  ret = 0;
  
}

int main () {
  int n, p;
  while (scanf ("%d %d", &n, &p), n || p) {
    memset (dp, -1, sizeof (dp));
    
  }
  
  return 0;
}
